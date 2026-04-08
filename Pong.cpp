#include "Bat.h"
#include"Ball.h"
#include<sstream>
#include<SFML/Graphics.hpp>
int main(){
    VideoMode vm(1920,1080);
    RenderWindow window(vm,"Pong!!!",Style::Fullscreen);
    int score=0;
    int lives=3;

    Bat bat(window.getSize().x/2.0,window.getSize().y-10);
    Ball ball (window.getSize().x/2.0,0);

    //create a text object called HUD (heads up display)
    Font font;
    font.loadFromFile("./fonts/KOMIKAP_.ttf");
    Text hud;
    hud.setFont(font);
    hud.setCharacterSize(75.0);
    hud.setColor(Color::Magenta);
    hud.setPosition(20.0,20.0);
    Clock clock;

    while(window.isOpen()){
        //handle player input
        Event event;
        while(window.pollEvent(event)){
         if(event.type==Event::Closed){
            window.close();
         }
        }
        if(Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
        }

        if(Keyboard::isKeyPressed(Keyboard::Left)){
            if(bat.get_Position().left<=0){
                bat.stopLeft();

            }
            else{
                bat.moveLeft();
            }
        }

        else
            bat.stopLeft();
        

        if(Keyboard::isKeyPressed(Keyboard::Right)){
            if(bat.get_Position().left + bat.get_Position().width>=1920){
                bat.stopRight();

            }
            else{
                bat.moveRight();
            }
        }

        else
            bat.stopRight();
        

            Time dt=clock.restart();
            bat.update(dt);
            ball.update(dt);
            std::stringstream ss;
            ss<<"Score:"<<score<<"  Lives: "<<lives;
            hud.setString(ss.str());

            if(ball.getPosition().top>=window.getSize().y){
                lives--;
                if(lives<=0){
                    lives=3;
                    score=0;
                     
                }
                 
                 ball.ReboundBottom();
                ball.update(dt);
              
               
            }

             if(ball.getPosition().top<=0){
               score++;
                
               ball.ReboundBatOrTop();
            }   
            if(ball.getPosition().left<=0|| ball.getPosition().left+ball.getPosition().width>=window.getSize().x){
                ball.ReboundSides();
            }
            //has the ball hit the bat
            if(ball.getPosition().intersects(bat.get_Position())){
                //if hit, reverse the ball and score a point
                score++;
                ball.ReboundBatOrTop();
                ball.update(dt);
            }
               window.clear();
            window.draw(bat.get_Shape());
            window.draw(ball.getShape());
            window.draw(hud);
            //display
            window.display();
    }
    return 0;
}