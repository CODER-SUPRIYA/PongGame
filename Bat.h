#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;
class Bat{
    //declare position
    Vector2f m_Position;

    //declare shape
    RectangleShape m_Shape;

    //declare speed
    float m_Speed=1000.0f;

    //declare bool var for right and left movement
    bool m_movingRight=false;
    bool m_movingLeft=false;

    public:
    //declare constructor method
   Bat(float startX,float startY);
    //declare get position method
    FloatRect get_Position();

    RectangleShape get_Shape();

    void moveRight();

    void moveLeft();

    void stopRight();

    void stopLeft();

    //declare update

    void update(Time dt);
};