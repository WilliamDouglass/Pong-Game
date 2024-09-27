#include <raylib.h>
#include "ball.h"
#include "score.h"

Ball::Ball(float startX,float startY,int initSpeedX, int initSpeedY, int radius, ScoreTracker &score )
    : initX(startX), initY(startY), speedX(initSpeedX), speedY(initSpeedY), radius(radius), score(score){
        x = initX;
        y = initY;
    }

void Ball::Move(){
    x += speedX;
    y += speedY;

    if(y + radius >= GetScreenHeight() || y - radius <= 0)
    {
        speedY *= -1;
    }
    if(x + radius >= GetScreenWidth())
    {
        score.appendPlayerScore();
        resetPos();
    }
    
    if(x - radius <= 0)
    {
        score.appendPlayerScore();
        resetPos();
    }
}

void Ball::Draw()
{
    DrawCircle(x,y,radius,WHITE);
}   

void Ball::resetPos(){
    x = initX;
    y = initY;
    int upDown[2] = {-1,1};
    speedY = upDown[GetRandomValue(0,1)] * GetRandomValue(5,7);
    speedX = GetRandomValue(5, 7) * ((speedX > 0) ? -1 : 1);
}

float Ball::getY() const {return y;}
float Ball::getX() const { return x; }
int Ball::getRadius() const {return radius;}

void Ball::flipSpeedX() {speedX *= -1;}
    
