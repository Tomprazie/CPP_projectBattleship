#include <iostream>
#include <string.h>

#include "Boat.h"
#include "AircraftCarrier.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Submarine.h"


using namespace std;

int grid_player_1[10][10];
int grid_player_2[10][10];
int grid_player_1_to_play[10][10];
int grid_player_2_to_play[10][10];

void player_v_player();

void display_grid_player_1();
void display_grid_player_2();
void display_grid_player_1_to_play();
void display_grid_player_2_to_play();


void add_boat_player_1(string nom_bateau);
void add_boat_player_2(string nom_bateau);

void player_2_shoots();
void player_1_shoots();

bool test_win_player_1();
bool test_win_player_2();


int line;
int row;
int D;
int compteur;
int8_t numberOfSunkShips = 0;

Boat * boatsPlayerOne[5];
//Boat * boatsPlayerOne = new Boat[5];

Boat * boatsPlayerTwo[5];
//Boat * boatsPlayerTwo = new Boat[5];



int main()
{

    for(int i=0;i<10;i++) {
		for(int j=0;j<10;j++){
			grid_player_1[i][j] = 0;
			grid_player_2[i][j] = 0;
            grid_player_1_to_play[i][j] = -1;
            grid_player_2_to_play[i][j] = -1;
		}
	}

    player_v_player();
}



void display_grid_player_1() {

    cout << "     | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "----------------------------------------------" << endl;
        cout << " | " << i << " | ";
        for (int j = 0; j < 10; j++)
        {
            if (grid_player_1[i][j] != 0) cout << grid_player_1[i][j] << " | ";
            else cout << "  | ";
        }
        cout << endl;
    }

}
void display_grid_player_1_to_play() {

    cout << "     | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "----------------------------------------------" << endl;
        cout << " | " << i << " | ";
        for (int j = 0; j < 10; j++)
        {
            switch (grid_player_1_to_play[i][j]) {
            case -1:
                cout << "  | "; break;
            case 0:
                cout << "O | "; break;
            case 1:
                cout << "X | "; break;
            case 2:
                cout << "D | "; break;
            }
        }
        cout << endl;
    }

    cout << endl << endl;

}


void display_grid_player_2() {


	cout << "     | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "----------------------------------------------" << endl;
        cout << " | " << i << " | ";
        for (int j = 0; j < 10; j++)
        {
            if (grid_player_2[i][j] != 0) cout << grid_player_2[i][j] << " | ";
            else cout << "  | ";
        }
        cout << endl;
    }

}
void display_grid_player_2_to_play() {

    cout << "     | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "----------------------------------------------" << endl;
        cout << " | " << i << " | ";
        for (int j = 0; j < 10; j++)
        {
            switch (grid_player_2_to_play[i][j]) {
            case -1:
                cout << "  | "; break;
            case 0:
                cout << "O | "; break;
            case 1:
                cout << "X | "; break;
            case 2:
                cout << "D | "; break;
            }
        }
        cout << endl;
    }

    cout << endl << endl;

}





void player_v_player() {
    cout << endl;
    display_grid_player_1();
    cout << endl << endl;

	add_boat_player_1("submarine"); //submarine
	add_boat_player_1("premier destroyer"); // first destroyer
	add_boat_player_1("deuxieme destroyer"); // destroyer
	add_boat_player_1("cruiser"); // cruiser
	add_boat_player_1("aircraft carrier"); //aircraft carrier

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<< endl;


    display_grid_player_2();

	add_boat_player_2("submarine");
	add_boat_player_2("premier destroyer");
	add_boat_player_2("deuxieme destroyer");
	add_boat_player_2("cruiser");
	add_boat_player_2("aircraft carrier");

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<< endl;

	player_1_shoots();
}

void add_boat_player_1(string nom_bateau){
	int parametre = 0;
	if(nom_bateau == "submarine") parametre=1;
	if(nom_bateau == "premier destroyer") parametre=2;
	if(nom_bateau == "deuxieme destroyer") parametre=2;
	if(nom_bateau == "cruiser") parametre=3;
	if(nom_bateau == "aircraft carrier") parametre=4;


	cout << "Player 1, enter the line of the " << nom_bateau << " :\n";
	cin >> line;



	if((line<0) | (line>9)){
		while((line<0) | (line>9)){
			cout << "Player 1, enter line valid number between 1 and 9";
            cin >> line;
		}
	}

	cout << "Player 1, enter the row of the " << nom_bateau << " :\n";
	cin >> row;

	if((row<0) | (row>9)){
		while((row<0) | (row>9)){
			cout << "Player 1, enter line valid number between 1 and 9";
            cin >> row;
		}
	}



	string Direction = "";
	if(row>=parametre){
		compteur = 0;
		for(int i=0; i<parametre+1; i++){
			if(grid_player_1[line][row-i] != 0){
				compteur +=1;
			}
		}
		if(compteur == 0){
			Direction += "1:Left, ";
		}
	}



	if(row<=(9-parametre)){
		compteur = 0;
		for(int i=0; i<parametre+1; i++){
			if(grid_player_1[line][row+i] != 0){
				compteur +=1;
			}
		}
		if(compteur == 0){
			Direction += "2:Right, ";
		}
	}
	if(line>=parametre){
		compteur = 0;
		for(int i=0; i<parametre+1; i++){
			if(grid_player_1[line-i][row] != 0){
				compteur +=1;
			}
		}
		if(compteur == 0){
			Direction += "3:Up, ";
		}
	}
	if(line<=9-parametre){
		compteur = 0;
		for(int i=0; i<parametre+1; i++){
			if(grid_player_1[line+i][row] != 0){
				compteur +=1;
			}
		}
		if(compteur == 0){
			Direction += "4:Down";
		}
	}

	if(Direction == "") { //si les deux chaines sont égales
		while(Direction == ""){
			cout << "Please enter valid coordinates";
			cout << "Player 1, enter the line of the " << nom_bateau << " :\n" << endl;
			cin >> line;

			if((line<0) | (line>9)){
				while((line<0) | (line>9)){
					cout << "Player 1, enter line valid number between 1 and 9";
					cin >> line;
				}
			}

			cout << "Player 1, enter the row of the " << nom_bateau << ":\n";
			cin >> row;
			if((row<0) | (row>9)){
				while((row<0) | (row>9)){
					cout << "Player 1, enter line valid number between 1 and 9";
                    cin >> row;
				}
			}

			if(row>=parametre){
				compteur = 0;
				for(int i=0; i<parametre+1; i++){
					if(grid_player_1[line][row-i] != 0){
						compteur +=1;
					}
				}
				if(compteur == 0){
                    Direction += "1:Left, ";
				}
			}
			if(row<=(9-parametre)){
				compteur = 0;
				for(int i=0; i<parametre+1; i++){
					if(grid_player_1[line][row+i] != 0){
						compteur +=1;
					}
				}
				if(compteur == 0){
                    Direction += "2:Right, ";
				}
			}
			if(line>=parametre){
				compteur = 0;
				for(int i=0; i<parametre+1; i++){
					if(grid_player_1[line-i][row] != 0){
						compteur +=1;
					}
				}
				if(compteur == 0){
					Direction += "3:Up, ";
				}
			}
			if(line<=9-parametre){
				compteur = 0;
				for(int i=0; i<parametre+1; i++){
					if(grid_player_1[line+i][row] != 0){
						compteur +=1;
					}
				}
				if(compteur == 0){
					Direction += "4:Down";
				}
			}

		}
	}
	cout << "Toward witch direction do you want to put your boat (" << Direction << ") : \n";


	cin >> D;


	if(nom_bateau == "submarine"){
		if(D==1){
			grid_player_1[line][row] = 2;
			grid_player_1[line][row-1] = 2;
            boatsPlayerOne[4] = new Submarine(line, row, "left");
		}
		if(D==2){
			grid_player_1[line][row] = 2;
			grid_player_1[line][row+1] = 2;
            boatsPlayerOne[4] = new Submarine(line, row, "right");
		}
		if(D==3){
			grid_player_1[line][row] = 2;
			grid_player_1[line-1][row] = 2;
            boatsPlayerOne[4] = new Submarine(line, row, "up");
		}
		if(D==4){
			grid_player_1[line][row] = 2;
			grid_player_1[line+1][row] = 2;
            boatsPlayerOne[4] = new Submarine(line, row, "down");
		}
	}


	if(nom_bateau == "premier destroyer"){
		if(D==1){
			grid_player_1[line][row] = 3;
			grid_player_1[line][row-1] = 3;
			grid_player_1[line][row-2] = 3;
            boatsPlayerOne[3] = new Destroyer(line, row, "left");
		}
		if(D==2){
			grid_player_1[line][row] = 3;
			grid_player_1[line][row+1] = 3;
			grid_player_1[line][row+2] = 3;
            boatsPlayerOne[3] = new Destroyer(line, row, "right");
		}
		if(D==3){
			grid_player_1[line][row] = 3;
			grid_player_1[line-1][row] = 3;
			grid_player_1[line-2][row] = 3;
            boatsPlayerOne[3] = new Destroyer(line, row, "up");
		}
		if(D==4){
			grid_player_1[line][row] = 3;
			grid_player_1[line+1][row] = 3;
			grid_player_1[line+2][row] = 3;
            boatsPlayerOne[3] = new Destroyer(line, row, "down");
		}
	}
	if(nom_bateau == "deuxieme destroyer"){
		if(D==1){
			grid_player_1[line][row] = 4;
			grid_player_1[line][row-1] = 4;
			grid_player_1[line][row-2] = 4;
            boatsPlayerOne[2] = new Destroyer(line, row, "left");
		}
		if(D==2){
			grid_player_1[line][row] = 4;
			grid_player_1[line][row+1] = 4;
			grid_player_1[line][row+2] = 4;
            boatsPlayerOne[2] = new Destroyer(line, row, "right");
		}
		if(D==3){
			grid_player_1[line][row] = 4;
			grid_player_1[line-1][row] = 4;
			grid_player_1[line-2][row] = 3;
            boatsPlayerOne[2] = new Destroyer(line, row, "up");
		}
		if(D==4){
			grid_player_1[line][row] = 4;
			grid_player_1[line+1][row] = 4;
			grid_player_1[line+2][row] = 4;
            boatsPlayerOne[2] = new Destroyer(line, row, "down");
		}
	}
	if(nom_bateau == "cruiser"){
		if(D==1){
			grid_player_1[line][row] = 5;
			grid_player_1[line][row-1] = 5;
			grid_player_1[line][row-2] = 5;
			grid_player_1[line][row-3] = 5;
            boatsPlayerOne[1] = new Cruiser(line, row, "left");
		}
		if(D==2){
			grid_player_1[line][row] = 5;
			grid_player_1[line][row+1] = 5;
			grid_player_1[line][row+2] = 5;
			grid_player_1[line][row+3] = 5;
            boatsPlayerOne[1] = new Cruiser(line, row, "right");
		}
		if(D==3){
			grid_player_1[line][row] = 5;
			grid_player_1[line-1][row] = 5;
			grid_player_1[line-2][row] = 5;
			grid_player_1[line-3][row] = 5;
            boatsPlayerOne[1] = new Cruiser(line, row, "up");
		}
		if(D==4){
			grid_player_1[line][row] = 5;
			grid_player_1[line+1][row] = 5;
			grid_player_1[line+2][row] = 5;
			grid_player_1[line+3][row] = 5;
            boatsPlayerOne[1] = new Cruiser(line, row, "down");
		}
	}
	if(nom_bateau == "aircraft carrier"){
		if(D==1){
			grid_player_1[line][row] = 6;
			grid_player_1[line][row-1] = 6;
			grid_player_1[line][row-2] = 6;
			grid_player_1[line][row-3] = 6;
			grid_player_1[line][row-4] = 6;
            boatsPlayerOne[0] = new AircraftCarrier(line, row, "left");
		}
		if(D==2){
			grid_player_1[line][row] = 6;
			grid_player_1[line][row+1] = 6;
			grid_player_1[line][row+2] = 6;
			grid_player_1[line][row+3] = 6;
			grid_player_1[line][row+4] = 6;
            boatsPlayerOne[0] = new AircraftCarrier(line, row, "right");
		}
		if(D==3){
			grid_player_1[line][row] = 6;
			grid_player_1[line-1][row] = 6;
			grid_player_1[line-2][row] = 6;
			grid_player_1[line-3][row] = 6;
			grid_player_1[line-4][row] = 6;
            boatsPlayerOne[0] = new AircraftCarrier(line, row, "up");
		}
		if(D==4){
			grid_player_1[line][row] = 6;
			grid_player_1[line+1][row] = 6;
			grid_player_1[line+2][row] = 6;
			grid_player_1[line+3][row] = 6;
			grid_player_1[line+4][row] = 6;
            boatsPlayerOne[0] = new AircraftCarrier(line, row, "down");

		}
	}










	cout << endl << endl;

	display_grid_player_1();


	cout << endl << endl;





}


void add_boat_player_2(string nom_bateau){
	int parametre = 0;
	if(nom_bateau == "submarine") parametre=1;
	if(nom_bateau == "premier destroyer") parametre=2;
	if(nom_bateau == "deuxieme destroyer") parametre=2;
	if(nom_bateau == "cruiser") parametre=3;
	if(nom_bateau == "aircraft carrier") parametre=4;


	cout << "Player 2, enter the line of the " << nom_bateau << " :\n";
	cin >> line;
	if((line<0) | (line>9)){
		while((line<0) | (line>9)){
			cout << "Player 2, enter line valid number between 1 and 9";
			cin >> line;
		}
	}

	cout << "Player 2, enter the row of the " << nom_bateau << " :\n";
	cin >> row;
	if((row<0) | (row>9)){
		while((row<0) | (row>9)){
			cout << "Player 2, enter line valid number between 1 and 9";
			cin >> row;
		}
	}

	string Direction = "";
	if(row>=parametre){
		compteur = 0;
		for(int i=0; i<parametre+1; i++){
			if(grid_player_2[line][row-i] != 0){
				compteur +=1;
			}
		}
		if(compteur == 0){
			Direction += "1:Left, ";
		}
	}
	if(row<=(9-parametre)){
		compteur = 0;
		for(int i=0; i<parametre+1; i++){
			if(grid_player_2[line][row+i] != 0){
				compteur +=1;
			}
		}
		if(compteur == 0){
			Direction += "2:Right, ";
		}
	}
	if(line>=parametre){
		compteur = 0;
		for(int i=0; i<parametre+1; i++){
			if(grid_player_2[line-i][row] != 0){
				compteur +=1;
			}
		}
		if(compteur == 0){
			Direction += "3:Up, ";
		}
	}
	if(line<=9-parametre){
		compteur = 0;
		for(int i=0; i<parametre+1; i++){
			if(grid_player_2[line+i][row] != 0){
				compteur +=1;
			}
		}
		if(compteur == 0){
			Direction += "4:Down";
		}
	}

	if(Direction == ""){ //si les deux chaines sont égales
		while(Direction == ""){
			cout << "Please enter valid coordinates" << endl;
			cout << "Player 2, enter the line of the " << nom_bateau << " :\n";
			cin >> line;
			if((line<0) | (line>9)){
				while((line<0) | (line>9)){
					cout << "Player 2, enter line valid number between 1 and 9";
					cin >> line;
				}
			}

			cout << "Player 2, enter the row of the " << nom_bateau << " :\n";
			cin >> row;
			if((row<0) | (row>9)){
				while((row<0) | (row>9)){
					cout << "Player 2, enter line valid number between 1 and 9";
					cin >> row;
				}
			}

			if(row>=parametre){
				compteur = 0;
				for(int i=0; i<parametre+1; i++){
					if(grid_player_2[line][row-i] != 0){
						compteur +=1;
					}
				}
				if(compteur == 0){
					Direction += "1:Left, ";
				}
			}
			if(row<=(9-parametre)){
				compteur = 0;
				for(int i=0; i<parametre+1; i++){
					if(grid_player_2[line][row+i] != 0){
						compteur +=1;
					}
				}
				if(compteur == 0){
					Direction += "2:Right, ";
				}
			}
			if(line>=parametre){
				compteur = 0;
				for(int i=0; i<parametre+1; i++){
					if(grid_player_2[line-i][row] != 0){
						compteur +=1;
					}
				}
				if(compteur == 0){
					Direction += "3:Up, ";
				}
			}
			if(line<=9-parametre){
				compteur = 0;
				for(int i=0; i<parametre+1; i++){
					if(grid_player_2[line+i][row] != 0){
						compteur +=1;
					}
				}
				if(compteur == 0){
					Direction += "4:Down";
				}
			}

		}
	}
	cout << "Toward witch direction do you want to put your boat (" << Direction << ") : \n";


	cin >> D;


	if(nom_bateau == "submarine"){
		if(D==1){
			grid_player_2[line][row] = 2;
			grid_player_2[line][row-1] = 2;
            boatsPlayerTwo[4] = new Submarine(line, row, "left");
		}
		if(D==2){
			grid_player_2[line][row] = 2;
			grid_player_2[line][row+1] = 2;
            boatsPlayerTwo[4] = new Submarine(line, row, "right");
		}
		if(D==3){
			grid_player_2[line][row] = 2;
			grid_player_2[line-1][row] = 2;
            boatsPlayerTwo[4] = new Submarine(line, row, "up");
		}
		if(D==4){
			grid_player_2[line][row] = 2;
			grid_player_2[line+1][row] = 2;
            boatsPlayerTwo[4] = new Submarine(line, row, "down");
		}
	}
	if(nom_bateau == "premier destroyer"){
		if(D==1){
			grid_player_2[line][row] = 3;
			grid_player_2[line][row-1] = 3;
			grid_player_2[line][row-2] = 3;
            boatsPlayerTwo[3] = new Destroyer(line, row, "left");
		}
		if(D==2){
			grid_player_2[line][row] = 3;
			grid_player_2[line][row+1] = 3;
			grid_player_2[line][row+2] = 3;
            boatsPlayerTwo[3] = new Destroyer(line, row, "right");
		}
		if(D==3){
			grid_player_2[line][row] = 3;
			grid_player_2[line-1][row] = 3;
			grid_player_2[line-2][row] = 3;
            boatsPlayerTwo[3] = new Destroyer(line, row, "up");
		}
		if(D==4){
			grid_player_2[line][row] = 3;
			grid_player_2[line+1][row] = 3;
			grid_player_2[line+2][row] = 3;
            boatsPlayerTwo[3] = new Destroyer(line, row, "down");
		}
	}
	if(nom_bateau == "deuxieme destroyer"){
		if(D==1){
			grid_player_2[line][row] = 4;
			grid_player_2[line][row-1] = 4;
			grid_player_2[line][row-2] = 4;
            boatsPlayerTwo[2] = new Destroyer(line, row, "left");
		}
		if(D==2){
			grid_player_2[line][row] = 4;
			grid_player_2[line][row+1] = 4;
			grid_player_2[line][row+2] = 4;
            boatsPlayerTwo[2] = new Destroyer(line, row, "right");
		}
		if(D==3){
			grid_player_2[line][row] = 4;
			grid_player_2[line-1][row] = 4;
			grid_player_1[line-2][row] = 4;
            boatsPlayerTwo[2] = new Destroyer(line, row, "up");
		}
		if(D==4){
			grid_player_2[line][row] = 4;
			grid_player_2[line+1][row] = 4;
			grid_player_2[line+2][row] = 4;
            boatsPlayerTwo[2] = new Destroyer(line, row, "down");
		}
	}
	if(nom_bateau == "cruiser"){
		if(D==1){
			grid_player_2[line][row] = 5;
			grid_player_2[line][row-1] = 5;
			grid_player_2[line][row-2] = 5;
			grid_player_2[line][row-3] = 5;
            boatsPlayerTwo[1] = new Cruiser(line, row, "left");
		}
		if(D==2){
			grid_player_2[line][row] = 5;
			grid_player_2[line][row+1] = 5;
			grid_player_2[line][row+2] = 5;
			grid_player_2[line][row+3] = 5;
            boatsPlayerTwo[1] = new Cruiser(line, row, "right");
		}
		if(D==3){
			grid_player_2[line][row] = 5;
			grid_player_2[line-1][row] = 5;
			grid_player_2[line-2][row] = 5;
			grid_player_2[line-3][row] = 5;
            boatsPlayerTwo[1] = new Cruiser(line, row, "up");
		}
		if(D==4){
			grid_player_2[line][row] = 5;
			grid_player_2[line+1][row] = 5;
			grid_player_2[line+2][row] = 5;
			grid_player_2[line+3][row] = 5;
            boatsPlayerTwo[1] = new Cruiser(line, row, "down");
		}
	}
	if(nom_bateau == "aircraft carrier"){
		if(D==1){
			grid_player_2[line][row] = 6;
			grid_player_2[line][row-1] = 6;
			grid_player_2[line][row-2] = 6;
			grid_player_2[line][row-3] = 6;
			grid_player_2[line][row-4] = 6;
            boatsPlayerTwo[0] = new AircraftCarrier(line, row, "left");
		}
		if(D==2){
			grid_player_2[line][row] = 6;
			grid_player_2[line][row+1] = 6;
			grid_player_2[line][row+2] = 6;
			grid_player_2[line][row+3] = 6;
			grid_player_2[line][row+4] = 6;
            boatsPlayerTwo[0] = new AircraftCarrier(line, row, "right");
		}
		if(D==3){
			grid_player_2[line][row] = 6;
			grid_player_2[line-1][row] = 6;
			grid_player_2[line-2][row] = 6;
			grid_player_2[line-3][row] = 6;
			grid_player_2[line-4][row] = 6;
            boatsPlayerTwo[0] = new AircraftCarrier(line, row, "up");
		}
		if(D==4){
			grid_player_2[line][row] = 6;
			grid_player_2[line+1][row] = 6;
			grid_player_2[line+2][row] = 6;
			grid_player_2[line+3][row] = 6;
			grid_player_2[line+4][row] = 6;
            boatsPlayerTwo[0] = new AircraftCarrier(line, row, "down");

		}
	}

	cout << endl << endl;

	display_grid_player_2();

	cout << endl << endl;




}





void player_1_shoots () {
    display_grid_player_1_to_play();

	cout << "Player 1 can play" << endl;
	cout << "Enter the line where you want to shoot :";
	cin >> line;
	cout << "Enter the row where you want to shoot :";
	cin >> row;



	if (grid_player_1_to_play[line][row] != -1){
		cout << "Please enter a place you have not shoot yet" << endl << endl;
		player_1_shoots();
	}

	if (grid_player_2[line][row] == 0){
		cout << "Ocean" << endl << endl;
		grid_player_1_to_play[line][row] = 0;
		player_2_shoots();
	}

	if (grid_player_2[line][row] > 0) {

        for (int j=0; j<7; j++) {
            if (grid_player_2[line][row] == 6-j) {
                boatsPlayerTwo[j]->isHit();
                if(boatsPlayerTwo[j]->isSunk()) {
                    cout << "Hit and sunk !" << endl << endl;

                    for(int k=0; k<10; k++) {
                        for (int l=0; l<10; l++) {
                            if (grid_player_2[k][l] == 6-j){
                                grid_player_1_to_play[k][l] = 2;
                            }
                        }
                    }
                }
                else {
                    cout << "Hit !" << endl << endl;
                    grid_player_1_to_play[line][row] = 1;
                }
            }
		}

        if (test_win_player_1()) {
            cout << "Player 1 wins the game !!!!!" << endl;
            for (int t = 0; t < 5; t++) {
                delete boatsPlayerOne[t];
                delete boatsPlayerTwo[t];
            }
        }
        else player_1_shoots();
	}

}//fin de tir joueur 1







void player_2_shoots () {
    display_grid_player_2_to_play();

	cout << "Player 2 can play" << endl;
	cout << "Enter the line where you want to shoot :";
	cin >> line;

	cout << "Enter the row where you want to shoot :";
	cin >> row;



	if (grid_player_2_to_play[line][row] != -1){
		cout << "Please enter a place you have not shoot yet" << endl << endl;
		player_2_shoots();
	}

	if (grid_player_1[line][row] == 0){
		cout << "Ocean" << endl << endl;
		grid_player_2_to_play[line][row] = 0;
		player_1_shoots();
	}

	if (grid_player_1[line][row] > 0) {

        for (int j=0; j<7; j++) {
            if (grid_player_1[line][row] == 6-j) {


                boatsPlayerOne[j]->isHit();
                if(boatsPlayerOne[j]->isSunk()) {
                    cout << "Hit and sunk !" << endl << endl;

                    for(int o=0; o<10; o++) {
                        for (int p=0; p<10; p++) {
                            if (grid_player_1[o][p] == 6-j){
                                grid_player_2_to_play[o][p] = 2;
                            }
                        }
                    }
                }
                else {
                    cout << "Hit !" << endl << endl;
                    grid_player_2_to_play[line][row] = 1;
                }
            }
		}

        if (test_win_player_2()) {
            cout << "Player 2 wins the game !!!!!" << endl;
            for (int t = 0; t < 5; t++) {
                delete boatsPlayerOne[t];
                delete boatsPlayerTwo[t];
            }
        }
        else player_2_shoots();
	}

}//fin de tir joueur 2



bool test_win_player_1() {
	numberOfSunkShips = 0;

	for(int i=0; i<5; i++){
	    if (boatsPlayerTwo[i]->isSunk() == true) numberOfSunkShips += 1;
	}

	if (numberOfSunkShips == 5) return true;
	else return false;

}


bool test_win_player_2() {
	numberOfSunkShips = 0;

	for(int i=0; i<5; i++){
	    if (boatsPlayerOne[i]->isSunk() == true) numberOfSunkShips += 1;
	}

	if (numberOfSunkShips == 5) return true;
	else return false;
}

