#ifndef ballH
#define ballH
#include "score.h"

class Ball
{
    private:
    const float initX,initY;
    float x,y;
    int speedX,speedY;
    int radius;
    ScoreTracker &score;


    public:
    Ball(float startX,float startY,int initSpeedX, int initSpeedY, int radius, ScoreTracker& score);
    void Move();
    void Draw();

    void resetPos();

    float getY() const;
    float getX() const;
    int getRadius() const;
    void flipSpeedX();
    
};
#endif