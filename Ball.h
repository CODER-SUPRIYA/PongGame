#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;
class Ball{
    private:
    //position
    Vector2f m_Position;

    //Shape
     CircleShape m_Shape;

     //speed
     float m_Speed=1000.0f;

    //X Direction
    float m_DirectionX=0.2f;

    //Ydirection
    float m_DirectionY=0.2f;

    public:
    //constructor
    Ball(float startX, float startY);

    //getPosition()
    FloatRect getPosition();

    //getshape
    CircleShape getShape();

    //get velocity
    float getVelocity();

    //reboundsides
    void ReboundSides();


    void ReboundBatOrTop();

    void ReboundBottom();

    void update(Time dt);



};