#include <iostream>
#include <string>

using namespace std;

/*

Tic Tac Toe - Features to Add

Checklist
- UI complete - DONE
- Game logic implemented - DONE
- Input validations implemented - DONE
- Make players able to play again in the same session - DONE
- Create a score for a multiple game session - DONE

What I'm analysing of implementing:
- Clearing the CLI between each play for just one board to appear at a time

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
	int* playercoord;
	int winStatus;
	int gameSessionStatus = 1;
	int score[2] = { 0,0 };

	cout << "Welcome to Tic Tac Toe" << endl << endl;

	while (gameSessionStatus)
	{
		string board[3][3] = { {" "," "," "},{" "," "," "},{" "," "," "} };
		
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
				cout << "Player 1 Wins!! " << endl;
				score[0]++;
				break;
			}
			else if (winConditions(board) == -1)
			{
				cout << "Player 2 Wins!! " << endl;
				score[1]++;
				break;
			}
		}

		cout << "Current Score:" << endl << "- Player 1: " << score[0] << endl << "- Player 2: " << score[1] << endl << endl;

		cout << "Do you want to play again? Enter 1 for Yes or 0 for No" << endl;
		cin >> gameSessionStatus;
	}
	

	cout << "Game Over!" << endl;
}
