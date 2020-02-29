#include <iostream>

using namespace std;

string p1, p2;
char game[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
int r, c;
char turn = 'O';
bool draw = true;

void just_for_fun() {
	int num;
	cout << "Number of players:";
	cin >> num;
	
	do
	{
		cout << "\nSorry!!!!! Only 2 players can play this game\n";
		cout << "Number of players:";
		cin >> num;
	} while (num > 2);

		cout << "\nName of Players:\n";
		cout << "Player 1:";
		cin >> p1;
		cout << "Player 2:";
		cin >> p2;
		cout << "Hey " << p1 << ',' << p2;
	
}

void display_board() {
	
	system("CLS");
	cout << "\t\t    |    |    \n";
	cout << "\t\t "<<  game[0][0] <<"  | "<< game[0][1] <<"  | "<< game[0][2] << "\n";
	cout << "\t\t____|____|____\n";
	cout << "\t\t    |    |    \n";
	cout << "\t\t " << game[1][0] << "  | " << game[1][1] << "  | " << game[1][2] << "\n";
	cout << "\t\t____|____|____\n";
	cout << "\t\t    |    |    \n";
	cout << "\t\t " << game[2][0] << "  | " << game[2][1] << "  | " << game[2][2] << "\n";
	cout << "\t\t    |    |    \n";
}

void choice() {
	int choice;
	if(turn=='O')
	cout << "\nPlayer[O], "<<p1<< "'s turn:";
	
	if (turn == 'X')
		cout << "\nPlayer[X], "<<p2<< "'s turn:";

	cin >> choice;

	
	switch (choice) 
	{
	case 1:
		r= 0;
		c = 0;
		break;

	case 2:
		r = 0;
		c = 1;
		break;

	case 3:
		r = 0;
		c = 2;
		break;

	case 4:
		r = 1;
		c = 0;
		break;

	case 5:
		r = 1;
		c = 1;
		break;

	case 6:
		r = 1;
		c = 2;
		break;

	case 7:
		r = 2;
		c = 0;
		break;

	case 8:
		r = 2;
		c = 1;
		break;

	case 9:
		r = 2;
		c = 2;
		break;

	default:
		cout<<"Invalid choice\n";
	}




	if (turn == 'O' && game[r][c]!='O'&&game[r][c]!='X') {
		
		game[r][c] = 'O';
		turn = 'X';

	}

	else if (turn == 'X' && game[r][c] != 'X' && game[r][c] != 'O') {

		game[r][c] = 'X';
		turn = 'O';

	}

	else {
		cout << "You cannot do it here.Box is already full\n";
		system("pause");
		
	}
	
}

bool noWin() {
	for (int i = 0; i < 3; i++) 
		if(game[i][0] == game[i][1] && game[i][0] == game[i][2])
			return false;

	for (int j = 0; j <= 3; j++)
		if (game[0][j] == game[1][j] && game[0][j] == game[2][j])
			return false;

	if ((game[0][0] == game[1][1] && game[0][0] == game[2][2]))
		return false;

	if (game[0][2] == game[1][1] && game[0][2] == game[2][0])
		return false; 

	/*
	for(int i=0;i<3;i++)
		for (int j = 0; j < 3; j++) 
			if (game[i][j] != 'O' && game[i][j] != 'X')
				return true;
	

	draw = true;
	return false;
	*/

	return true;

}

int main() {
	int counter = 0;
	just_for_fun();
	cout << ",let's Begin the Game" << endl;
	printf("Press [Enter] key to continue.\n");
	while (getchar() != '\n');
	getchar();
	
	while (noWin()) {
		display_board();
		if (counter == 9) {
			cout << "DRAW " << endl;
			system("pause");
			break;
		}
		choice();
		counter++;
		display_board();

	}
	

	if (turn == 'O' )
		cout << "COngracts You Win Player X "<<p2;


	else if (turn == 'X')
		cout << "COngracts You Win Player 0\n"<<p1;
}