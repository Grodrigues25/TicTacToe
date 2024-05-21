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
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			if (column == 0)
			{
				cout << board[row][column];
			}
			else if (column == 2)
			{
				cout << "|";
				cout << board[row][column] << endl;
				if (row != 2)
				{
					cout << "- - -" << endl;
				}
			}
			else
			{
				cout << "|";
				cout << board[row][column];
			}
		}

	}
}

int winConditions(string board[3][3])
{
	// ROWS
	if (board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][0] != " " && board[0][1] != " " && board[0][2] != " ")
	{
		return -1;
	}
	if (board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0] != " " && board[1][1] != " " && board[1][2] != " ")
	{
		return -1;
	}
	if (board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] != " " && board[2][1] != " " && board[2][2] != " ")
	{
		return -1;
	}

	// COLUMNS
	if (board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[0][0] != " " && board[1][0] != " " && board[2][0] != " ")
	{
		return -1;
	}
	if (board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1] != " " && board[1][1] != " " && board[2][1] != " ")
	{
		return -1;
	}
	if (board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2] != " " && board[1][2] != " " && board[2][2] != " ")
	{
		return -1;
	}

	//DIAGONALS
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != " " && board[1][1] != " " && board[2][2] != " ")
	{
		return -1;
	}
	if (board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[2][0] != " " && board[1][1] != " " && board[0][2] != " ")
	{
		return -1;
	}


}

int main()
{
	string board[3][3] = { {" "," "," "},{" "," "," "},{" "," "," "}};
	
	int playercoord1=0;
	int playercoord2=0;
	int winStatus;

	cout << "Welcome to Tic Tac Toe" << endl;
	cout << endl;
	printBoard(board);
	cout << endl;

	for (int playedMoves = 0; playedMoves < 9; playedMoves++)
	{
		if (playedMoves % 2 == 0)
		{
			cout << "Player 1 turn to play. Select your Board coordinates" << endl;
			
			cin >> playercoord1;
			while (playercoord1 < 0 || playercoord1 > 2)
			{
				cout << "The coord inserted is invalid";
				cin >> playercoord1;
			}

			cin >> playercoord2;
			while (playercoord1 < 0 || playercoord1 > 2)
			{
				cout << "The coord inserted is invalid";
				cin >> playercoord1;
			}
			
			board[playercoord1][playercoord2] = "X";

			printBoard(board);
			winStatus = winConditions(board);
			
			if (winStatus == -1)
			{
				break;
			}
			else
			{
				continue;
			}
		}

		cout << "Player 2 turn to play. Select your Board coordinates" << endl;

		cin >> playercoord1;
		while (playercoord1 < 0 || playercoord1 > 2)
		{
			cout << "The coord inserted is invalid" << endl;
			cin >> playercoord1;
		}

		cin >> playercoord2;
		while (playercoord1 < 0 || playercoord1 > 2)
		{
			cout << "The coord inserted is invalid" << endl;
			cin >> playercoord1;
		}

		board[playercoord1][playercoord2] = "O";

		printBoard(board);
		winStatus = winConditions(board);

		if (winStatus == -1)
		{
			break;
		}
	}

	cout << "Game Over!";
}
