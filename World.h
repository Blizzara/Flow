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


#ifndef WORLD_H
#define WORLD_H

#include <vector>

typedef std::vector<double> Array1Df;
typedef std::vector<bool> Array1Db;

//#define IX(x,y,width,height) (((x)*(height))+(y))

#define DEFAULT_WIDTH 400
#define DEFAULT_HEIGHT 200

class World
{

  public:
    World();
    virtual ~World();
    virtual bool operator==(const World& other) const;
    void setDensity(int a_x, int a_y, double a_density) {m_density[IX(a_x,a_y)] = a_density;};
    double getDensity(int a_x, int a_y) {return m_density[IX(a_x,a_y)];};
    double getSource(int a_x, int a_y){return m_source[IX(a_x,a_y)];}; 
  
    
    void setWidth(int a_w) { m_width = a_w;};
    void setHeight(int a_h) { m_height = a_h;};
    
    int getWidth(void) { return m_width;};
    int getHeight(void) {return  m_height;};
   
  private:
    World(const World& other);
    virtual World& operator=(const World& other);

    int IX(int x, int y) { return (x*m_height + y);};  
    
    int m_width;
    int m_height;

    Array1Df m_velocity_x;
    Array1Df m_velocity_y;
    Array1Df m_velocity_x_tmp;
    Array1Df m_velocity_y_tmp;
    
    Array1Df m_density;
    Array1Df m_density_tmp;
    Array1Df m_source;
    Array1Df m_force_x;
    Array1Df m_force_y;
    Array1Db m_is_solid;

};

#endif // WORLD_H
