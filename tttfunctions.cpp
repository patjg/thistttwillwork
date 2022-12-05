#include <iostream>
#include <vector>
#include <string>
using namespace std;

void instructions (string player1, string player2) {
    string grid =
        " _______________________________________________ \n"
        "|               |               |               |\n"
        "|               |               |               |\n"
        "|       1       |       2       |       3       |\n"
        "|               |               |               |\n"
        "|_______________|_______________|_______________|\n"
        "|               |               |               |\n"
        "|               |               |               |\n"
        "|       4       |       5       |       6       |\n"
        "|               |               |               |\n"
        "|_______________|_______________|_______________|\n"
        "|               |               |               |\n"
        "|               |               |               |\n"
        "|       7       |       8       |       9       |\n"
        "|               |               |               |\n"
        "|_______________|_______________|_______________|\n";

    cout << "Welcome to tic, tac, toe, " << player1 << " and " << player2 << "." << endl;
    cout << "The rules are pretty simple. You will select numbers that correspond to a square on a tic, tac, toe grid,\nwhich I will show you shortly" << endl;
    cout << "The goal is to get 3 squares in a row. These squares can be horizontal, diagonal, or vertical within the grid.";
    cout << "Here is the aforementioned grid: \n\n" << endl;
    cout << grid;
}

bool randomizer () {
    bool playerorder1 = false;
    int randnum = rand() % 2 + 1;
    if (randnum == 1) {
        playerorder1 = true;
        return playerorder1;
    }else {
        return !playerorder1;
    } 
}


//function to alter the grid that is output after each player selection
string gamegrid (int id, int tmp, string updatedgrid) {
    string modifiedgrid = " _______________________________________________ \n|               |               |               |\n|               |               |               |\n|       1       |       2       |       3       |\n|               |               |               |\n|_______________|_______________|_______________|\n|               |               |               |\n|               |               |               |\n|       4       |       5       |       6       |\n|               |               |               |\n|_______________|_______________|_______________|\n|               |               |               |\n|               |               |               |\n|       7       |       8       |       9       |\n|               |               |               |\n|_______________|_______________|_______________|\n";
        
    if (updatedgrid == modifiedgrid) {
        ;
    }else {
        modifiedgrid = updatedgrid;
    }
    
    tmp = tmp + '0';

    for (unsigned int i = 0; i < modifiedgrid.length(); i++) {
        if (id == 1 && modifiedgrid[i] == tmp) {
            modifiedgrid[i] = 'X';
        }else if (id == 2 && modifiedgrid[i] == tmp) {
            modifiedgrid[i] = 'O';
        }else {
            continue;
        }
    }
    cout << modifiedgrid << endl;
    return modifiedgrid;
}


string game (string p1, string p2) {
    vector <unsigned short int> p1selections;
    string modifiedgrid = " _______________________________________________ \n|               |               |               |\n|               |               |               |\n|       1       |       2       |       3       |\n|               |               |               |\n|_______________|_______________|_______________|\n|               |               |               |\n|               |               |               |\n|       4       |       5       |       6       |\n|               |               |               |\n|_______________|_______________|_______________|\n|               |               |               |\n|               |               |               |\n|       7       |       8       |       9       |\n|               |               |               |\n|_______________|_______________|_______________|\n";
    vector <unsigned short int> p2selections;
    vector <vector <unsigned short int> > correct = {{1,2,3}, {1,4,7}, {2,5,8}, {3,6,9}, {4,5,6}, {7,8,9}, {1,5,9}, {3,5,7}};
    unsigned short int tmp;
    int short counter = 0;

    while (counter != 3) {
        //p1 selection

        cout << p1 << ", please make your selection: ";
        cin >> tmp; 

        //add tmp to p1selections
        for (unsigned int q = 0; q < p1selections.size(); q++) {
            if (p1selections[q] == tmp) {
                while (p1selections[q] == tmp) {
                    cout << "Please make an original selection!" << endl;
                    cout << p1 << ", please make your selection: ";
                    cin >> tmp; 
                }
            }
        }
        for (unsigned int r; r < p2selections.size(); r++) {
            if (p2selections[r] == tmp) {
                while (p2selections[r] == tmp) {
                    cout << "Please make an original selection!" << endl;
                    cout << p1 << ", please make your selection: ";
                    cin >> tmp; 
                }
            }
        }

        p1selections.push_back(tmp);
        modifiedgrid = gamegrid(1, tmp, modifiedgrid);

        //check if p1selections contains any of the winning combinations


        for (unsigned int j = 0; j < correct.size(); j++) {
            for (unsigned int k = 0; k < 3; k++) {            
                for (unsigned int i = 0; i < p1selections.size (); i++) {
                    if (p1selections [i] == correct[j][k]) {
                        counter += 1;
                    }
                }
            }
            if (counter == 3) {
                cout << p1 << ", you win! Nicely done!" << endl;
                return p1;
            }else {
                counter = 0;
            }
        }

        cout << p2 << ", please make your selection: ";
        cin >> tmp; 
        //add tmp to p2selections and check for originality

        for (unsigned int q = 0; q < p1selections.size(); q++) {
            if (p1selections[q] == tmp) {
                while (p1selections[q] == tmp){
                    cout << "Please make an original selection!" << endl;
                    cout << p2 << ", please make your selection: ";
                    cin >> tmp;
                } 
            }
        }
        for (unsigned int r; r < p2selections.size(); r++) {
            if (p2selections[r] == tmp) {
                while (p2selections[r] == tmp){
                    cout << "Please make an original selection!" << endl;
                    cout << p2 << ", please make your selection: ";
                    cin >> tmp; 
                }    
            }
        }

        p2selections.push_back(tmp);
        modifiedgrid = gamegrid (2, tmp, modifiedgrid);

        //check if p1selections contains any of the winning combinations
        for (unsigned int j = 0; j < correct.size(); j++) {
            for (unsigned int k = 0; k < correct[j].size(); k++) {            
                for (unsigned int i = 0; i < p2selections.size (); i++) {
                    if (p2selections [i] == correct[j][k]) {
                        counter += 1;
                    }
                }
//linter - will indent appropriately for me
//return the winning player, switch return type
            }
                if (counter == 3) {
                    cout << p2 << ", you win! Nicely done!" << endl;
                    return p2;
                    counter = 0;
                }else {
                    counter = 0;
                }        
        }

    }

    string error = "error";
    return error;
}




