#include "Ball.h"
//constructor
Ball::Ball(float startX, float startY){
    m_Position.x=startX;
    m_Position.y=startY;
    m_Shape.setRadius(10.0);
    m_Shape.setPosition(m_Position);
}

FloatRect Ball::getPosition(){
    return m_Shape.getGlobalBounds();

}

CircleShape Ball::getShape(){
    return m_Shape;
}

float Ball::getVelocity(){
    return m_DirectionX;
}
void Ball::ReboundSides(){
m_DirectionX=-m_DirectionX;
}
void Ball::ReboundBatOrTop(){
    m_DirectionY=-m_DirectionY;
}

void Ball::ReboundBottom(){
//   m_DirectionY=-m_DirectionY;

  m_Position.x=500.0;
  m_Position.y=0.0;
//   m_Shape.setPosition(500,0);

}
void Ball::update(Time dt){
    m_Position.x+=m_DirectionX*m_Speed*dt.asSeconds();
    m_Position.y+=m_DirectionY*m_Speed*dt.asSeconds();
    m_Shape.setPosition(m_Position);
}