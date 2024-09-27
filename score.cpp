#include "score.h"


int playerScore;
int cpuScore;

ScoreTracker::ScoreTracker(){
    playerScore = 0;
    cpuScore = 0;
}
void ScoreTracker::appendPlayerScore(){
    playerScore++;
}
void appendCpuScore(){
    cpuScore++;
}

int ScoreTracker::getPlayerScore() const {return playerScore;}
int ScoreTracker::getCpuScore() const {return cpuScore;}  

