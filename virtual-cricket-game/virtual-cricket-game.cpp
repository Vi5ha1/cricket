#include"game.cpp"
using namespace std;
int main(){
    Game g1;//g1 is called object and is used to call the function from Game class you stupid shit
    g1.Welcome();

    cout << "Press Enter to Continue";
    cin.ignore();

    g1.Players();

    cout << "Press Enter to Continue";
    cin.ignore();
    
    g1.selectPlayer();

    g1.showTeamPlayers(); 

    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "Press Enter to Continue";
    cin.ignore();

    g1.toss();

    g1.startFirstInnings();


    return 0;
}



