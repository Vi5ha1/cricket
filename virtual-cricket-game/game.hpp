#ifndef _game_h_
#define _game_h_

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
#include<algorithm>
#include <random>
//#include<string>
//#include<vector> cause these both are in team.hpp
#include"team.cpp"
class Game{
    public:
        Game();
        int playersPerTeam;
        int maxBalls;
        int totalPlayers;
        int IndiaScore,Pakscore;

        bool isFirstInnings;
        bool isSecondInnings;
        Team teamA,teamB;
        Team *battingTeam, *bowlingTeam;
        Player *batsman,*bowler;
        std::string players [11];

        void Welcome();
        int Players();
        int takingInput();
        void selectPlayer();
        bool validateSelectPlayer(int);
        void showTeamPlayers();
        void toss();
        void tossChoice(Team);
        void startFirstInnings();
        void initializePlayer();
        void playingInnings();
        void bat();
        bool validateInningsScore();
        void showScore();
        void secondInnings();
        void playingInnings2();
        void finalScore();
};


#endif