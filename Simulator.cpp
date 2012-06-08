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


#include "Simulator.h"

#include <cstdlib> // needed for calloc
#include <cstring> // needed for memset
#include <cassert> // needed for assert
#include <iostream> // needed for cout

#include <algorithm> // needed for std::copy

#define SIZE ((m_width)*(m_height))
#define CALLOC(x) {(x) = (Array1Df)calloc(SIZE,sizeof(float)); assert((x));}
#define FREE(x) { free((x)); } 
#define CLEAR(x) { memset((x), 0,sizeof(float)*SIZE);}


#define SWAP(x,y) {Array1Df tmp = (x); (x) = (y); (y) = tmp;}

Simulator::Simulator()
{

  m_width = 400;
  m_height = 200;
  m_diff = 1;
  m_visc = 1;
  m_dt = 1.0;
  m_k = 20;
  
  CALLOC(m_u)
  CALLOC(m_u_t)
  CALLOC(m_v)
  CALLOC(m_v_t)
  CALLOC(m_d)
  CALLOC(m_d_t)
  CALLOC(m_source)
  CALLOC(m_force_u) 
  CALLOC(m_force_v)
  
//   m_source[IX(50,50)] = 400000.0f;
//   
//   for (int i = 0; i < SIZE; ++i)
//   {
//     m_v[i] = 5;
//     m_u[i] = 5;
//   }
//   
  
}
void Simulator::reset(void )
{
  CLEAR(m_u)
  CLEAR(m_u_t)
  CLEAR(m_v)
  CLEAR(m_v_t)
  CLEAR(m_d)
  CLEAR(m_d_t)
  CLEAR(m_source)
  CLEAR(m_force_u) 
  CLEAR(m_force_v)  
}

Simulator::Simulator(Simulator& other)
{

}

Simulator& Simulator::operator=(Simulator& other)
{
  return *this;
}


Simulator::~Simulator()
{
  FREE(m_u)
  FREE(m_u_t)
  FREE(m_v)
  FREE(m_v_t)
  FREE(m_d)
  FREE(m_d_t)
  FREE(m_source)
  FREE(m_force_u) 
  FREE(m_force_v)  
}

void Simulator::SetBounds(float b, Array1Df d)
{

  for(int i = 1; i < m_width; ++i)
  {
    d[IX(i,0)] = b==2? -d[IX(i,1)] : d[IX(i,1)];
    d[IX(i,m_height-1)] = b==2? -d[IX(i,m_height-2)] : d[IX(i,m_height-2)];
  }
  
  for(int j = 1; j < m_height; ++j)
  {
    d[IX(0,j)] = b==1? -d[IX(1,j)] : d[IX(1,j)];
    d[IX(m_width-1,j)] = b==1? -d[IX(m_width-2,j)] : d[IX(m_width-2,j)];
  }
  
  d[IX(0,0)] = 0.5*(d[IX(1,0)] + d[IX(0,1)]);
  d[IX(m_width-1,0)] = 0.5*(d[IX(m_width-2,0)] + d[IX(m_width-1,1)]);
  d[IX(0,m_height-1)] = 0.5*(d[IX(1,m_height-1)] + d[IX(0,m_height-2)]);
  d[IX(m_width-1,m_height-1)] = 0.5*(d[IX(m_width-2,m_height-1)] + d[IX(m_width-1,m_height-2)]);
}

void Simulator::Project(Array1Df u, Array1Df v, Array1Df p, Array1Df div)
{
  int i, j, k;
  for ( i=1 ; i< m_width -1; i++ ) {
    for ( j=1 ; j< m_height -1; j++ ) {
      div[IX(i,j)] = -0.5*(u[IX(i+1,j)]-u[IX(i-1,j)]+v[IX(i,j+1)]-v[IX(i,j-1)]);
      p[IX(i,j)] = 0;
    }
  }
  SetBounds (0, div ); SetBounds (0, p );
  for ( k=0 ; k<m_k ; k++ ) {
    for ( i=1 ; i< m_width-1 ; i++ ) {
      for ( j=1 ; j< m_height-1 ; j++ ) {
	p[IX(i,j)] = (div[IX( i,j)]+p[IX(i-1,j)]+p[IX(i+1,j)]+p[IX(i,j-1)]+p[IX(i,j+1)])/4;
      }
    }
    SetBounds (0, p );
  }
  for ( i=1 ; i< m_width -1 ; i++ ) {
    for ( j=1 ; j< m_height -1 ; j++ ) {
      u[IX(i,j)] -= 0.5*(p[IX(i+1,j)]-p[IX(i-1,j)]);
      v[IX(i,j)] -= 0.5*(p[IX(i,j+1)]-p[IX(i,j-1)]);
    }
  }
  SetBounds (1, u );SetBounds ( 2, v );
}


void Simulator::ApplySources(float dt, Array1Df d, Array1Df source)
{
  for (int i = 0; i < m_width; ++i)
    for(int j = 0; j < m_height; ++j)
      d[IX(i,j)] += source[IX(i,j)] * dt;
}

void Simulator::Diffuse(float b, float dt, float diff, Array1Df d, Array1Df d_t)
{
  float a = diff*dt*m_width*m_height;
  
  for (int k = 0; k < m_k; ++k)
  {
    for(int i = 1; i < m_width-1; ++i)
      for(int j = 1; j < m_height-1; ++j)
	d[IX(i,j)] = (d_t[IX(i,j)] + a*(d[IX(i-1, j)] + d[IX(i+1, j)] + d[IX(i, j-1)] + d[IX(i, j+1)]))/(1+4*a);   
    SetBounds(b, d);
  }
}

void Simulator::Advect(float b, float dt, Array1Df d, Array1Df d_t, Array1Df u, Array1Df v)
{
  int i0,j0,i1,j1; // neighbour cells
  
  float s0,s1,t0,t1; // location relative to neigbours
  
  for(int i = 1; i < m_width; ++i)
    for(int j = 1; j < m_height; ++j)
    {
      int x = i-dt*u[IX(i,j)]; 
      int y = j-dt*v[IX(i,j)];
      
      if (x < 0.5) x = 0.5;
      else if(x > m_width - 1.5) x = m_width - 1.5;
      i0 = (int)x; i1 = i0+1;
      
      if (y < 0.5) y = 0.5;
      else if (y > m_height - 1.5) y = m_height - 1.5;
      j0 = (int)y; j1 = j0+1;
      
      s1 = x - i0; s0 = 1-s1;
      t1 = y - j0; t0 = 1-t1;
      
      d[IX(i,j)] = s0 * (t0*d_t[IX(i0,j0)] + t1*d_t[IX(i0,j1)]) + s1 * (t0*d_t[IX(i1,j0)] + t1*d_t[IX(i1,j1)]);
    }
  
  SetBounds(b, d);
      
}

void Simulator::Step(float dt)
{
  if (dt < 0)
    dt = m_dt;
  
  std::copy(m_force_u, m_force_u+SIZE, m_u_t);
  std::copy(m_force_v, m_force_v+SIZE, m_v_t);
  
  DensityStep(dt);
  VelocityStep(dt);
}


void Simulator::DensityStep(float dt)
{
  ApplySources(dt, m_d, m_source);
  SWAP(m_d,m_d_t)
  Diffuse(0, dt, m_diff, m_d, m_d_t);
  SWAP(m_d,m_d_t)
  Advect(0,dt, m_d, m_d_t, m_u, m_v);
}

void Simulator::VelocityStep(float dt)
{
  ApplySources(dt, m_u, m_u_t);
  ApplySources(dt, m_v, m_v_t);
  SWAP(m_u,m_u_t)
  SWAP(m_v,m_v_t)
  Diffuse(1, dt, m_visc, m_u, m_u_t);
  Diffuse(2, dt, m_visc, m_v, m_v_t);
  Project(m_u, m_v, m_u_t, m_u_t);
  SWAP(m_u,m_u_t)
  SWAP(m_v,m_v_t)
  Advect(1,dt, m_u, m_u_t, m_u_t, m_v_t);
  Advect(2,dt, m_v, m_v_t, m_u_t, m_v_t);
  Project(m_u, m_v, m_u_t, m_u_t);
}
