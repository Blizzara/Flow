/*
    Copyright (c) 2012, <copyright holder> <email>
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.
        * Neither the name of the <organization> nor the
        names of its contributors may be used to endorse or promote products
        derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY <copyright holder> <email> ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL <copyright holder> <email> BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#include "FlowGLWin.h"

#include <cmath>

#include <GL/glu.h>
#include <iostream>

#include <QMouseEvent>

FlowGLWin::FlowGLWin(QWidget* parent) : m_sim()
{
  m_sides_i = 3;
  m_radius_d	 = 1.0;
  m_steps = 0; 
  m_screen_height = 400;
  m_screen_width = 800;
  m_insert_mode = INSERT_MODE_SOURCE;
  m_visible_components[0] = COMPONENT_DENSITY;
  m_visible_components[1] = COMPONENT_SOURCE;
  m_visible_components[2] = COMPONENT_SUMFORCE;
  
  m_timer = new QTimer(this);
  connect(m_timer, SIGNAL(timeout()), this, SLOT(step()));
}


FlowGLWin::~FlowGLWin()
{
  delete m_timer;
}

void FlowGLWin::mouseMoveEvent(QMouseEvent* a_event)
{
  QPoint r_pos = QPoint((a_event->pos().x() * m_sim.getWidth() / m_screen_width), (800-a_event->pos().y())*m_sim.getHeight()/m_screen_height);

  float strength = 100000.0f;
  switch (m_insert_mode){
    case INSERT_MODE_SOURCE:
      m_sim.setSource((int)r_pos.x(), (int)r_pos.y(), strength); break;
    case INSERT_MODE_FORCE_U:
      m_sim.setForceU((int)r_pos.x(), (int)r_pos.y(), strength); break;
    case INSERT_MODE_FORCE_V:
      m_sim.setForceV((int)r_pos.x(), (int)r_pos.y(), strength); break;
  }
  updateGL();
}


void FlowGLWin::initializeGL()
{
  glShadeModel(GL_SMOOTH);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 
}

void FlowGLWin::paintGL()
{
  
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  
  //glTranslated(5.0, 5.0, 0.0);
  glPointSize(1.0f);
  for (int i = 0; i < m_sim.getWidth(); ++i)
  {
    for(int j = 0; j < m_sim.getHeight(); ++j)
    {
      float r = valueByComponentEnum(i,j,m_visible_components[0]);
      float g = valueByComponentEnum(i,j,m_visible_components[1]);
      float b = valueByComponentEnum(i,j,m_visible_components[2]);

      //if (r+g+b > 0.1f) std::cout << r << " " << g << " " << b << std::endl;
      glColor3f(r, g, b);
      glBegin(GL_POINTS);
	glVertex2i(i,j);
      glEnd();
    }
  }
}

void FlowGLWin::resizeGL(int width, int height)
{
  double xMin = 0, xMax = 400, yMin = 0, yMax = 200;
  glViewport(0,0,m_screen_width, m_screen_height);
  //glViewport(0,0,(GLint)width, (GLint)height);
  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-1,1,-1,1);
  
  if (width/400 > height/200){
    height = height?height:1;
    yMax = width/2;
  }
  else {
    width = width?width:1;
    xMax = height*2;
  }
  //gluOrtho2D(xMin, xMax, yMin, yMax);
  //std::cout << xMin << " " << xMax  << " " << yMin<< " " << yMax << std::endl;
  gluOrtho2D(0, 400, 0, 200);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
    

}

float FlowGLWin::valueByComponentEnum(int i, int j, VISIBLE_COMPONENT choice)
{
  switch (choice) // doesn't need break due to returns
  {
    case COMPONENT_DENSITY:
      return m_sim.getDensity(i,j);
    case COMPONENT_SOURCE:
      return m_sim.getSource(i,j);
    case COMPONENT_UFORCE:
      return m_sim.getForceU(i,j);
    case COMPONENT_VFORCE:
      return m_sim.getForceV(i,j);
    case COMPONENT_SUMFORCE:
      return sqrt(pow(m_sim.getForceU(i,j),2) + pow(m_sim.getForceV(i,j),2));
    case COMPONENT_UVELOCITY:
      return m_sim.getVelU(i,j);
    case COMPONENT_VVELOCITY:
      return m_sim.getVelV(i,j);
    case COMPONENT_SUMVELOCITY:
      return sqrt(pow(m_sim.getVelU(i,j),2) + pow(m_sim.getVelV(i,j),2));
    default:
      return 0;
  }
}

void FlowGLWin::step(void )
{
  m_sim.Step();
  std::cout << "Steps done: " << m_steps++ << std::endl;
  updateGL();
}


void FlowGLWin::pauseSim(void )
{
  m_timer->stop();
}

void FlowGLWin::startSim(void )
{
  m_timer->start(m_update_interval);
}

void FlowGLWin::changeTimestep(int a_new)
{
  m_sim.setDT(a_new);
}

void FlowGLWin::changeUpdateInterval(int a_new)
{
  m_update_interval = a_new;
}


void FlowGLWin::changeDiffusion(int a_new)
{
  m_sim.setDiff(a_new);
}

void FlowGLWin::changeViscosity(int a_new)
{
  m_sim.setVisc(a_new);
}

void FlowGLWin::changeK(int a_new)
{
  m_sim.setK(a_new);
}

void FlowGLWin::selectInsertMode_source(void )
{
  m_insert_mode = INSERT_MODE_SOURCE;
}

void FlowGLWin::selectInsertMode_force_u(void )
{
  m_insert_mode = INSERT_MODE_FORCE_U;
}

void FlowGLWin::selectInsertMode_force_v(void )
{
  m_insert_mode = INSERT_MODE_FORCE_V;
}

void FlowGLWin::selectRed(int a_new)
{
  m_visible_components[0] = (VISIBLE_COMPONENT)a_new; // DANGEROUS CAST
  updateGL();
}

void FlowGLWin::selectGreen(int a_new)
{
  m_visible_components[1] = (VISIBLE_COMPONENT)a_new; // DANGEROUS CAST
  updateGL();
}

void FlowGLWin::selectBlue(int a_new)
{
  m_visible_components[2] = (VISIBLE_COMPONENT)a_new; // DANGEROUS CAST
  updateGL();
}

void FlowGLWin::resetSim(void )
{
  m_sim.reset();
  updateGL();
}

