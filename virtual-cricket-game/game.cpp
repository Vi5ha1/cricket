#include"game.hpp"
using namespace std;
Game::Game(){

    playersPerTeam=4;
    maxBalls=6;
    totalPlayers = 11 ;
    isFirstInnings = false;

    players[0]="Sachin";
    players[1]="Dhoni";
    players[2]="Sewagh";
    players[3]="Rahul";
    players[4]="Kapil";
    players[5]="Afridi";
    players[6]="Irfan";
    players[7]="Malik";
    players[8]="Mohamad";
    players[9]="Abdul";
    players[10]="Jahingir";

    teamA.teamName="India";
    teamB.teamName="Pakistan";

 
 
}
void Game::Welcome(){
    cout<<"\n\n..........Welcome to one of the most awaited match of the tournament..........\n\n..........It's not a tournament its a Battle...........\n\n";
    _sleep(1000);
    cout<<"==========CRTC-IN==========\n\nWelcome to Virtual Cricket Game \n\n";
    _sleep(1000);
    cout<<"==========Instructions==========\n1. Create 2 teams (Team-A and Team-B with 4\n players each) from a given pool of 11 players.\n2. Lead the toss and decide the choice of play.\n3. Each innings will be of 6 balls.\n\n";
    _sleep(1000);
}

int Game::Players(){

    cout<<endl<<"=====Pool of Players====="<<endl;
    _sleep(1000);
    for (int i = 0; i < 11 ; i++)
    {
        cout<<"\t\t["<<i<<"]"<<players[i]<<endl;
    }
        return 0;  
}

bool Game::validateSelectPlayer(int ind){

    int n;
    vector<Player>players;

    players = teamA.player;
    n=players.size();
    for (int i = 0; i<n;i++){
        if (players[i].index == ind){
            return false;
        }
    }

    players = teamB.player;
    n=players.size();
    for (int i = 0; i<n;i++){
        if (players[i].index == ind){
            return false;
        }
    }
    return true;
}

int Game::takingInput(){
    int a;
    while(true){
        if (a<10||a>0){
            while(!(cin >>a)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input.  Try again: ";
                }
            return a;
            break;
        }
        else
        {
            cout<<"\n";
        }
    }
    return 0;
}

void Game::selectPlayer(){
    _sleep(1000);
    cout<<"========================================="<<endl;
    cout<<"***Create Team India and Team Pakistan***"<<endl;
    cout<<"========================================="<<endl;
    _sleep(1000);
    for (int i = 0; i < playersPerTeam; i++)
    {
        teamIndiaSelection:
            cout<<endl<<"Select player "<<i+1<<" for India :- ";
            int playerIndexIndia = takingInput();
            if(playerIndexIndia<0 || playerIndexIndia>10)
            {
                cout<<endl<<"please select from given players"<<endl;
                goto teamIndiaSelection;
            } 
            else if(!(validateSelectPlayer(playerIndexIndia)))
            {
                cout<<"\nalready selected try again\n";
                goto teamIndiaSelection;
            }
            else
            {
                Player teamIndia;            
                teamIndia.index = playerIndexIndia;
                teamIndia.name = players[playerIndexIndia];
                teamA.player.push_back(teamIndia);//adding the players of team to vector player
            }

        //pak team selection

        teamPakistanSelection:

            cout<<endl<<"Select player "<<i+1<<" for Pakistan :- ";
            int playerIndexPakistan = takingInput();

            if (0>playerIndexPakistan || 10<playerIndexPakistan)
            {
                cout<<endl<<"please select from given players"<<endl;
                goto teamPakistanSelection;
            }
            else if(!(validateSelectPlayer(playerIndexPakistan)))
            {
                cout<<"\nalready selected try again\n";
                goto teamPakistanSelection;
            }
            else 
            {
                Player teamPak;
                teamPak.index = playerIndexPakistan;
                teamPak.name = players[playerIndexPakistan];
                teamB.player.push_back(teamPak);//adding the players of team to vector player
            }
    }
}  

void Game::showTeamPlayers(){
    vector<Player>indianPlayers;
    indianPlayers = teamA.player;
    vector<Player>pakPlayers;
    pakPlayers = teamB.player;
    _sleep(1000);
    cout<<"\n************************\t\t***************************";
    cout<<endl<<"|======== "<< teamA.teamName <<" =======|\t\t|======== "<< teamB.teamName <<" =======|"<<endl;
    cout<<"************************\t\t***************************\n";
    _sleep(1000);
    for (int i = 0; i < playersPerTeam; i++)
    {
        cout<<"|\t["<<i<<"] "<<indianPlayers[i].name<<"\t|\t\t"<<"|\t["<<i<<"] "<<pakPlayers[i].name<<"\t   |\n";
    }
    
}

void Game::toss(){
    _sleep(1000);
    cout<<"\n******************************";
    cout<<endl<<"|======== "<< "Let's Toss" <<" =======|"<<endl;
    cout<<"******************************\n";
    _sleep(1000);
    cout<<"Tossing the coin..."; 
    _sleep(1000);
    int n;
    srand(time(0));
    string won;
    n = rand() % 2 + 1 ;
    if (n==1)
    {
        cout<<"\nIndia won the toss";
        tossChoice(teamA);
    }
    else if (n==2)
    {
        cout<<"\nPakistan won the toss";
        tossChoice(teamB);        
    }
}

void Game::tossChoice(Team tossWinnerTeam){

    choice:
        _sleep(1000);
        cout<<"\nEnter 1 to bat or enter 2 to bowl first\n";
        _sleep(1000);
        cout<<"1. Bat\n2. Bowl\n";
        _sleep(1000);
        int n = takingInput();
        switch (n)
        {
        case 1: 
            cout<< tossWinnerTeam.teamName <<" Won the toss and chose to Bat first\n" ;
            if (tossWinnerTeam.teamName.compare("India")==0)
            {
                battingTeam =&teamA;
                bowlingTeam = &teamB;
            }
            else
            {
                battingTeam =&teamB;
                bowlingTeam = &teamA;
            }
            
                     
            break;
        case 2:
            cout<< tossWinnerTeam.teamName <<" Won the toss and chose to Bowl first\n" ;
            if (tossWinnerTeam.teamName.compare("India")==0)
            {
                battingTeam =&teamB;
                bowlingTeam = &teamA;
            }
            else
            {
                battingTeam =&teamA;
                bowlingTeam = &teamB;
            }
            break;
        default:
            cout<<"select a valid input"<<endl;
            goto choice;
        }
}

void Game::startFirstInnings(){
    _sleep(1000);
    cout<<"\t ||| AND THE BATTLE BEGINS |||\n\n";
    _sleep(1000);
    isFirstInnings = true;
    isSecondInnings = false;
    initializePlayer();
    playingInnings();
}

void Game::initializePlayer(){

    batsman = &battingTeam->player[0];
    bowler = &bowlingTeam->player[0];

    _sleep(1000);
    cout<<"\nHere comes the players, or should I say warriors..\n";
    _sleep(1000);
    cout<<"From Team "<< battingTeam->teamName<<" "<<batsman->name<<" Walks in"<<endl;
    _sleep(1000);
    cout<<"And he has to face "<< bowler->name<<endl ;
    _sleep(1000);

}

void Game::playingInnings(){
    int target;
    for (int i = 0; i < maxBalls; i++)
    {   
        cin.ignore();
        cout<<"press Enter to bowl\n";
        getchar();
        cout<<"Bowling... "<<endl;
        _sleep(1000);
        bat();
        _sleep(1000); 
        if (!validateInningsScore())
        {
            cout << "end of 1st innings";
            secondInnings();
        }    
    }
}

void Game::bat(){
    srand(time(NULL));
    int runsScored = rand()%7;

    batsman->runsScored = batsman->runsScored + runsScored;
    battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
    batsman->ballsPlayed = batsman->ballsPlayed + 1;

    bowler->runsGiven = bowler->runsGiven+runsScored;
    bowler->ballsBowled = bowler->ballsBowled + 1;
    bowlingTeam->TotalBallsPlayed =  bowlingTeam->TotalBallsPlayed +1;
    if (runsScored!=0){
        if(runsScored==6){
            cout << bowler->name << " to " << batsman->name <<" "<< runsScored << " runs!\n";
            cout<<"And thats a masive one, beautiful..\n";
            _sleep(1000);
            showScore();
            _sleep(1000);
            cout<<"\n\nPress enter to continue"; 

        }
        else if(runsScored!=6)
        {
            cout << bowler->name << " to " << batsman->name <<" "<< runsScored << " runs!\n";
            _sleep(1000);
            showScore();
            _sleep(1000);
            cout<<"\n\nPress enter to continue"; 
        }
    }
    else
    {
        cout << bowler->name << " to " << batsman->name <<" "<<"OUT!\n\n";
        cout<<"What an amazing delivery by "<<bowler->name<<endl;
        battingTeam->wicketsLost=battingTeam->wicketsLost + 1;
        bowler->wicketsTaken = bowler->wicketsTaken + 1;

        int nextPlayerIndex = battingTeam->wicketsLost;
        batsman = &battingTeam->player[nextPlayerIndex];

        cout<<batsman->name<<" walks in next..\n";
        _sleep(1000);
        showScore();
        _sleep(1000);
        cout<<"\n\nPress enter to continue"; 
    }
    
}

bool Game::validateInningsScore(){
    int target;
    if (isFirstInnings)
    {
        if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->TotalBallsPlayed == maxBalls)
        {
            cout<<"\n\t==|| Innings has come to an end let's look at the score card ||==\n";
            _sleep(1000);
            
            cout<<battingTeam->teamName<<" "<<battingTeam->totalRunsScored<<"-"
            <<battingTeam->wicketsLost <<"("<<bowlingTeam->TotalBallsPlayed<<")"<<endl;
            _sleep(1000);
            if(battingTeam->teamName.compare("India")==0){
                IndiaScore = battingTeam->totalRunsScored;
            }
            else
            {
                Pakscore = battingTeam->totalRunsScored;
            }
            
            
            if (!(isSecondInnings)){
                cout<<bowlingTeam->teamName<<" needs "<< battingTeam->totalRunsScored + 1 <<" runs to win the match \n\n";
                _sleep(1000);
            }

            else
            
            {
                if(battingTeam->teamName.compare("India")==0){
                    IndiaScore = battingTeam->totalRunsScored;
                }
                else
                {
                    Pakscore = battingTeam->totalRunsScored;
                }
                
            }
            return false;
        }
    }return true;
    
}

void Game::showScore(){
    for (int i = 0; i < 60; i++)
    {
        cout<<"=";
    }       
    cout<<endl<<battingTeam->teamName<<" "<<battingTeam->totalRunsScored<<"-"
    <<battingTeam->wicketsLost <<"("<<bowlingTeam->TotalBallsPlayed<<") | "
    <<batsman->name<<" "<< batsman->runsScored <<" ("<<batsman->ballsPlayed<<")\t"
    <<bowler->name<<" "<<bowler->ballsBowled<<" - "<<bowler->runsGiven<<" - "<<bowler->wicketsTaken<<endl;

    for (int i = 0; i < 60; i++)
    {
        cout<<"=";
    }
    
}

void Game::secondInnings(){
    swap(battingTeam,bowlingTeam);
    initializePlayer();
    cout<<"Press Enter to continue";
    playingInnings2();
}

void Game::playingInnings2(){    
    for (int i = 0; i < maxBalls; i++)
    {   
        cin.ignore();
        cout<<"Press Enter to bowl\n";
        getchar();
        cout<<"Bowling... "<<endl;
        _sleep(1000);
        bat();
        _sleep(1000);
        isSecondInnings = true; 
        if (!validateInningsScore())
        {
            _sleep(1000);
            cout << "End of 2nd innings";
            if(IndiaScore>Pakscore){
                _sleep(1000);
                cout<<"\nIndia won the match, what an innings!\n";
                _sleep(1000);
                cout<<"We can see the joy on faces of fans...\n";
                _sleep(1000);
                cout<<"Marvoleus.\n";
                finalScore();
            }    
            else if(IndiaScore<Pakscore){
                _sleep(1000);
                cout<<"\nPakistan won the match..\n";
                _sleep(1000);
                cout<<"Inshala the boys played well\n";
                finalScore();
            }
            else
            {
                _sleep(1000);
                cout<<"\nIts a tie\n";
                finalScore();
            }
        }   
    }
}

void Game::finalScore(){
    


    cout<<"\t|| MATCH ENDS ||\n";
    cout<<battingTeam->teamName<<" "<<battingTeam->totalRunsScored<<"-"
        <<battingTeam->wicketsLost <<"("<<bowlingTeam->TotalBallsPlayed<<")\n";
    for (int i = 0; i < 49; i++)
    {
        cout<<"=";
    }
    cout<<"\n| PLAYER\t\tBATTING\t\tBOWLING\t|\n";

    for (int i = 0; i < 4; i++)
    {   
        cout<<"|";
        cout<<"-----------------------------------------------";
        cout<<"|\n";
        cout<<"|";
        batsman = &battingTeam->player[i];
        cout<<" ["<<i<<"] "<< batsman->name <<"\t\t"<<batsman->runsScored<<" ("<<batsman->ballsPlayed<<")\t\t"<<batsman->ballsBowled<<"-"<<batsman->runsGiven<<"-"<<batsman->wicketsTaken<<"\t|\n";
    }

    for (int i = 0; i < 49; i++)
    {
        cout<<"=";
    }

    cout<<endl<<endl;
    cout<<bowlingTeam->teamName<<" "<<bowlingTeam->totalRunsScored<<"-"
        <<bowlingTeam->wicketsLost <<"("<<bowlingTeam->TotalBallsPlayed<<")\n";
    for (int i = 0; i < 49; i++)
    {
        cout<<"=";
    }
    cout<<"\n| PLAYER\t\tBATTING\t\tBOWLING\t|\n";
    for (int i = 0; i < 4; i++)
    {   
        cout<<"|";
        cout<<"-----------------------------------------------";
        cout<<"|\n";
        cout<<"|";
        bowler = &bowlingTeam->player[i];
        cout<<" ["<<i<<"] "<< bowler->name <<"\t\t"<<bowler->runsScored<<" ("<<bowler->ballsPlayed<<")\t\t"<<bowler->ballsBowled<<"-"<<bowler->runsGiven<<"-"<<bowler->wicketsTaken<<"\t|\n";

    }
    for (int i = 0; i < 49; i++)
    {
        cout<<"=";
    }

}