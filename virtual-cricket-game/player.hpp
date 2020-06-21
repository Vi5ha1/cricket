#ifndef _player_h_
#define _player_h_
#include<string>
class Player{
    public:
        Player();
        std::string name;
        int index;
        int runsScored;
        int ballsPlayed;
        int ballsBowled;
        int runsGiven;
        int wicketsTaken;
};
#endif