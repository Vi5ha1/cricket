#ifndef _team_h_
#define _team_h_
#include<vector>
#include"player.cpp"
//dont need string header file case we have it in player
class Team{
    public:
        Team();
        std::string teamName;
        int totalRunsScored;
        int wicketsLost;
        int TotalBallsPlayed;
        std::vector<Player>player;
};
#endif