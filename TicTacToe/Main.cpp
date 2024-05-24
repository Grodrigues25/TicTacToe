#include <iostream>
#include <string>

using namespace std;

/*

Tic Tac Toe

1. I need an interface where to appear in the command line
2. I need a way to save the information of the locations played in a data structure
3. I need to insert the played locations into the data structure
4. I need to be checking if any player has won
5. I need to be able to check for a tie
6. I need to be able to avoid a player playing in a location already played

*/ 

void printBoard(string board[3][3]) //O(N^2)
{
	cout << " | 0 1 2" << endl << "-|------" << endl;

	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			if (column == 0) 
			{
				cout << row << "| " << board[row][column];
			}
			else if (column == 2)
			{
				cout << "|" << board[row][column] << endl;
				if (row != 2)
				{
					cout << " | - - -" << endl;
				}
			}
			else
			{
				cout << "|" << board[row][column];
			}
		}

	}
}

int winConditions(string board[3][3])
{
	// ROWS
	if (board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][0] != " " && board[0][1] != " " && board[0][2] != " ")
	{
		if (board[0][0] == "X") {return 1;} 
		else {return -1;}
	}
	if (board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0] != " " && board[1][1] != " " && board[1][2] != " ")
	{
		if (board[1][0] == "X") { return 1; }
		else { return -1; }
	}
	if (board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] != " " && board[2][1] != " " && board[2][2] != " ")
	{
		if (board[2][0] == "X") { return 1; }
		else { return -1; }
	}

	// COLUMNS
	if (board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[0][0] != " " && board[1][0] != " " && board[2][0] != " ")
	{
		if (board[0][0] == "X") { return 1; }
		else { return -1; }
	}
	if (board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1] != " " && board[1][1] != " " && board[2][1] != " ")
	{
		if (board[0][1] == "X") { return 1; }
		else { return -1; }
	}
	if (board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2] != " " && board[1][2] != " " && board[2][2] != " ")
	{
		if (board[0][2] == "X") { return 1; }
		else { return -1; }
	}

	//DIAGONALS
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != " " && board[1][1] != " " && board[2][2] != " ")
	{
		if (board[0][0] == "X") { return 1; }
		else { return -1; }
	}
	if (board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[2][0] != " " && board[1][1] != " " && board[0][2] != " ")
	{
		if (board[2][0] == "X") { return 1; }
		else { return -1; }
	}
}

int* inputCoords()
{
	int pc1 = 0;
	int pc2 = 0;
	int pc[2] = { -1, -1 };

	cout << "Row: ";
	cin >> pc1;
	while (pc1 < 0 || pc1 > 2)
	{
		cout << "The coord inserted is invalid." << endl << "Row: ";
		cin >> pc1;
	}

	cout << "Column: ";
	cin >> pc2;
	while (pc2 < 0 || pc2 > 2)
	{
		cout << "The coord inserted is invalid." << endl << "Column: ";
		cin >> pc2;
	}

	pc[0] = pc1;
	pc[1] = pc2;

	return pc;
}

int main()
{
	string board[3][3] = { {" "," "," "},{" "," "," "},{" "," "," "}};
	
	int* playercoord;
	int winStatus;

	cout << "Welcome to Tic Tac Toe" << endl << endl;
	printBoard(board);
	cout << endl;

	for (int playedMoves = 0; playedMoves < 9; playedMoves++)
	{
		cout << "Player " << playedMoves % 2 + 1 << " turn to play. Select your Board coordinates." << endl;

		playercoord = inputCoords();

		while (board[playercoord[0]][playercoord[1]] != " ")
		{
			cout << "Coordenadas já jogadas. Insira coordenadas válidas!" << endl;
			playercoord = inputCoords();
		}

		if (playedMoves % 2 == 0)
		{
			board[playercoord[0]][playercoord[1]] = "X";
		}
		else
		{
			board[playercoord[0]][playercoord[1]] = "O";
		}

		cout << endl;
		printBoard(board);
		cout << endl;

		if (winConditions(board) == 1)
		{
			cout << "Player 1 Wins!! ";
			break;
		}
		else if (winConditions(board) == -1)
		{
			cout << "Player 2 Wins!! ";
			break;
		}

	}

	cout << "Game Over!" << endl;
}
