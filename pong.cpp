#include <iostream>
#include <raylib.h>
#include "ball.h"
#include "score.h"

class Paddle{
    private:
    float x,y;
    int width,hight;
    int speed;
    
    protected:

    void LimitMovement(){
        if(y <= 0)
        {
            y = 0;
        }

        if(y + hight >= GetScreenHeight())
        {
            y = GetScreenHeight() - hight;
        }   
    }

    public:

    Paddle(float startX, float startY, int initWidth, int initHight, int initSpeed)
        : x(startX), y(startY), width(initWidth), hight(initHight), speed(initSpeed){}

    void Draw()
    {
        DrawRectangle(x,y,width,hight,RED);
    }

    void Move()
    {   
        LimitMovement();
        if(IsKeyDown(KEY_UP))
        {
            y = y - speed;
        }

        if(IsKeyDown(KEY_DOWN))
        {
            y = y + speed;
        }
    }

    float getY() const { return y; }
    float getX() const { return x; }
    int getWidth() const { return width; }
    int getHeight() const { return hight; }
    int getSpeed() const {return speed;}

    void setY(float newY) {y = newY;}

};

class CpuPaddle: public Paddle{
    public:
    CpuPaddle(float startX, float startY, int initWidth, int initHeight, int initSpeed)
    : Paddle(startX, startY, initWidth, initHeight, initSpeed) {}

    void Move(float ballY) {
        LimitMovement();

        if (ballY > getY() + getHeight() / 2) {
            setY(getY()+getSpeed());
        } else if (ballY < getY() + getHeight() / 2) {
            setY(getY()-getSpeed());
        }
    }
    
};



int main(int argc, char const *argv[])
{   
    const int screen_width = 1280;
    const int screen_hight = 800;

    InitWindow(screen_width,screen_hight,"Pong Game :P");
    SetTargetFPS(60);
    
    ScoreTracker scoreboard;

    Ball myball(screen_width/2,screen_hight/2,5,5,12, scoreboard);
    // Create the Player and CPU Paddle objects
    Paddle player(10, screen_hight / 2 - 60, 25, 120, 6);
    CpuPaddle cpu(screen_width - 35, screen_hight / 2 - 60, 25, 120, 6);


    while(!WindowShouldClose()){

        BeginDrawing();

        ClearBackground(BLACK); // Remove the previous frame

        myball.Draw();
        myball.Move();

        player.Draw();
        player.Move();

        cpu.Draw();
        cpu.Move(myball.getY());

        if(CheckCollisionCircleRec(Vector2{myball.getX(),myball.getY()},myball.getRadius(),Rectangle{player.getX(),player.getY(),static_cast<float>(player.getWidth()),static_cast<float>(player.getHeight())}))
        {
            myball.flipSpeedX();
        }
        if(CheckCollisionCircleRec(Vector2{myball.getX(),myball.getY()},myball.getRadius(),Rectangle{cpu.getX(),cpu.getY(),static_cast<float>(cpu.getWidth()),static_cast<float>(cpu.getHeight())}))
        {
            myball.flipSpeedX();
        }
    
        DrawLine(screen_width/2,0,screen_width/2,screen_hight,WHITE);

        DrawText(TextFormat("%i", scoreboard.getPlayerScore()),screen_width/4-20,20,80,WHITE);
        DrawText(TextFormat("%i", scoreboard.getCpuScore()),3*screen_width/4-20,20,80,WHITE);


        EndDrawing();

    }



    return 0;
}





