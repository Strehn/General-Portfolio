/* Sydney Petrehn
   Assignment 10
   A game similar to minesweeper but gophers
*/

#include<iostream>
#include<fstream>
using namespace std;

const int size = 10; // the size of the board game

// ----- function fragments -----
void printBoard(string a[][size]);
int inArray(int a, int b, int c);
void findGopher(string a[][size]);

int main()
{
        // ------ Variables ---------
        string arrayBoard[size][size];
        string arrayValues[size][size];
        int user1, user2;
        int inarray;
	bool Continue = true;
	bool validInput = false;
	int tries = 71;
	ifstream infile;

	// ----- Gets the board information from a file -----	
	 infile.open("Gopher.txt");
        if(!infile)
        {
                cout << "Unable to open file" << endl;
        }

        // ------ Saves data from file to array -----
        // data arrays
        for(int i = 0; i < size; i++)
        {
		for(int column = 0; column < size; column++)
		{
                	infile >> arrayValues[i][column];
		}
        }

	// ----- Create the Board the player sees -----

	 for(int row=0; row< size; row++) // to start just make everything the same
                {
                        for(int column = 0; column < size; column++)
                        {
                                arrayBoard[row][column] = "+";
                        }
                }
	// ----- Add in the boarder -----
	for(int i=0; i < 10; i++)
	{
		arrayBoard[i][0] = "|";
		arrayBoard[i][9] = "|";
	}

	// ----- Start the Game ----
	cout << "The goal of this game is to uncover all the board without hitting a gopher." << endl;
	
	do
	{
		// ----- print the board every loop -----
		printBoard(arrayBoard);
		while(validInput == false)
		{		
			// ----- get user input of which spot they choose -----
			cout << "Enter which row (0-9) you choose." << endl;
			cin >> user1;
			cout << "Enter which column (0-9) you choose." << endl;
			cin >> user2;
		
			// ----- ensure the value is in array -----
			inarray = inArray(user1, user2, size);
			if(inarray == -1)
			{
				cout << "Invalid input. Please enter valid x, y coordinates." << endl;
			}
			else
			{
				validInput = true;
			}
		}
		tries--;
		validInput = false; // so that next loop the function will go again.
		// ----- check array for the value at the coordinate-----
		if(arrayValues[user1][user2] == "G")
		{
			Continue = false;
			cout << "You hit a gopher!" << endl;
			cout << "GAME OVER" << endl;
			arrayBoard[user1][user2] = arrayValues[user1][user2];
		}
		else
		{
			arrayBoard[user1][user2] = arrayValues[user1][user2];
			
			// ---- uncovers all the neighboring cells if user hits a 0 -----
			if(arrayValues[user1][user2] == "0")
			{
				
			}
			
		}
		if(tries = 0)
		{
			Continue = false;
			cout << "Congratulations, You Won!" << endl;

		}	
		
		
	}while(Continue == true);
}

void printBoard(string a[][size])
{
	 //----- print the board -----
                for(int row=0; row< size; row++)
                {
                        for(int column = 0; column < size; column++)
                        {
                                cout << a[row][column];
                        }
			cout << endl;
                }

}

int inArray(int a, int b, int c)
{
	if( ( a > c ) || ( a < 0 ) )
	{
		return -1;
	}
	else if( (b > c) || (b < 0) )
	{
		return -1;
	}
	else
	{
		return 1;
	}
}
