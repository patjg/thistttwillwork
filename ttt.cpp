#include <iostream>
#include "tttfunctions.h"
using namespace std;

int main () {
    
    string player1;
    string player2;
    //request names
    cout << "Please enter player 1's name here: ";
    cin >> player1;

    cout << "Please enter player 2's name here: ";
    cin >> player2;

    instructions (player1, player2);
    bool playerorder1 = randomizer ();
    if (playerorder1) {
        game (player1, player2);
    }else {
        player1 = player2;
        player2 = player1;
        game (player1, player2);
    }

    return 0;
}