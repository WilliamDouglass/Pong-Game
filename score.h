#ifndef scoreH
#define scoreH

class ScoreTracker{
    private:
    int playerScore;
    int cpuScore;

    public:
    ScoreTracker();

    void appendPlayerScore();
    void appendCpuScore();

    int getPlayerScore() const;
    int getCpuScore() const ; 

};


#endif