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


#ifndef SIMULATOR_H
#define SIMULATOR_H

//#include "World.h"

#define IX(x,y) (((x)*(m_height))+(y))

class Simulator
{
public:
  Simulator();
  virtual ~Simulator();
  
  void setForceU(int i, int j, float s) { if ((0 < i < m_width) && (0 < j < m_height)) m_force_u[IX(i,j)] = s;};
  void setForceV(int i, int j, float s) { if ((0 < i < m_width) && (0 < j < m_height)) m_force_v[IX(i,j)] = s;};
  void setSource(int i, int j, float s) { if ((0 < i < m_width) && (0 < j < m_height)) m_source[IX(i,j)] = s;};
  float getSource(int i, int j) { return m_source[IX(i,j)];};
  float getDensity(int i, int j) { return m_d[IX(i,j)]; };
  float getVelU (int i, int j) { return m_u[IX(i,j)]; };
  float getVelV (int i, int j) { return m_v[IX(i,j)]; };
  float getForceU(int i, int j) { return m_force_u[IX(i,j)]; };
  float getForceV(int i, int j){ return m_force_v[IX(i,j)]; };
  int getWidth(void) { return m_width; };
  int getHeight(void) { return m_height; };
  
  
  void setDT(int a_new) { m_dt = a_new; };
  void setDiff(int a_new) { m_diff = a_new; };
  void setVisc(int a_new) { m_visc = a_new; };
  void setK(int a_new) { m_k = a_new; };
  
  void Step(float dt = -1);
  void reset(void);
  
  
  
private:
  Simulator(Simulator& other);
  virtual Simulator& operator=(Simulator& other);
  
  void ApplySources(float dt, float* d, float* source);
  void Diffuse(float b, float dt, float diff, float* d, float *d_t);
  void Advect(float b, float dt, float* d, float* d_t, float* u, float* v);
  void DensityStep(float dt);
  void VelocityStep(float dt);
  
  void SetBounds(float b, float* d);
  void Project(float *u, float *v, float *p, float *div);
  
  //World m_world;
  
  int m_width;
  int m_height;
  
  float* m_u;
  float* m_v;
  float* m_u_t;
  float* m_v_t;
  float* m_d;
  float* m_d_t;
  float* m_source;
  float* m_force_u;
  float* m_force_v;
  float m_diff;
  float m_visc;
  float m_dt;
  int m_k;
  
};

#endif // SIMULATOR_H
