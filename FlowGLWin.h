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

#ifndef FLOWGLWIN_H
#define FLOWGLWIN_H

#include <QtOpenGL/QGLWidget>
#include <QTimer>

#include "Simulator.h"

enum INSERT_MODES { INSERT_MODE_SOURCE, INSERT_MODE_FORCE_U, INSERT_MODE_FORCE_V };
enum VISIBLE_COMPONENT { COMPONENT_DENSITY=0, COMPONENT_SOURCE, COMPONENT_UFORCE, 
  COMPONENT_VFORCE, COMPONENT_SUMFORCE, COMPONENT_UVELOCITY, COMPONENT_VVELOCITY, COMPONENT_SUMVELOCITY };

class FlowGLWin : public QGLWidget
{

  Q_OBJECT
  
public:
  FlowGLWin(QWidget* parent = 0);

  virtual ~FlowGLWin();

  void mouseMoveEvent(QMouseEvent* a_event);
//virtual bool operator==(const FlowGLWin& other) const;

protected:
  void initializeGL();
  void resizeGL(int width, int height);
  void paintGL();
  
   
private:
  int m_sides_i;
  double m_radius_d;
  int m_steps;
  
  FlowGLWin(const FlowGLWin& other) {};
  virtual FlowGLWin& operator=(const FlowGLWin& other) {};
  
  float valueByComponentEnum(int i, int j, VISIBLE_COMPONENT choice);
  
  int m_update_interval;
  
  int m_screen_width;
  int m_screen_height;
  
  INSERT_MODES m_insert_mode;
  VISIBLE_COMPONENT m_visible_components[3];
  
  QTimer* m_timer;
  
  Simulator m_sim;
  QWidget* m_parent;
  
public slots:
  void changeDiffusion(int a_new);
  void changeViscosity(int a_new);
  void changeUpdateInterval(int a_new);
  void changeTimestep(int a_new);
  void changeK(int a_new);
  void step(void);
  void resetSim(void);
  
  void startSim(void);
  void pauseSim(void);
  
  
  void selectInsertMode_source(void);
  void selectInsertMode_force_u(void);
  void selectInsertMode_force_v(void);
  
  void selectRed(int a_new);
  void selectGreen(int a_new);
  void selectBlue(int a_new); 

signals:
  void tellX(int x);
  void tellY(int y);
  void tellDens(double dens);
  void tellUForce(double uforce);
  
};

//#include "FlowGLWin.moc"

#endif // IFNDEF FLOWGLWIN_H