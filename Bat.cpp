#include "Bat.h"

using namespace sf;

//definations of methods in Bat Class
//constructor
Bat::Bat(float startX, float startY){
  m_Position.x=startX;
  m_Position.y=startY;
  m_Shape.setSize(Vector2f(100.0,10.0));
  m_Shape.setPosition(m_Position);
}

FloatRect Bat::get_Position(){
    return m_Shape.getGlobalBounds();
}

RectangleShape Bat::get_Shape(){
    return m_Shape;
}
void Bat::moveRight(){
    m_movingRight=true;
}
void Bat::moveLeft(){
    m_movingLeft=true;
}
void Bat:: stopRight(){
m_movingRight=false;
}

void Bat:: stopLeft(){
m_movingLeft=false;
}

void Bat::update(Time dt){
if(m_movingLeft){
    m_Position.x-=m_Speed*dt.asSeconds();
}
if(m_movingRight){
    m_Position.x+=m_Speed*dt.asSeconds();
}

m_Shape.setPosition(m_Position);
}