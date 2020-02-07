
/*   Sydney Petrehn
     Assignment 11
     Adventure game similar to ones we have created before
*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>

using namespace std;

class area{
	string location;
	public:
	void read(ifstream& infile); // function which will read a string from file
	string getLocation();
};

int main(){
	int playerx = 1;
	int playery = 1;
	int playerinput;
	area board[4][4]; // this needs to be the area class
	bool Continue = true;
	int validInput;
	int N,S,E,W;
	string location;

	//-----OPens the file to get the data -----
	ifstream infile;
	infile.open("life.txt");
	if(!infile)
	{
		cout << "Unable to open file" << endl;
	}		
	// ----- gets data into the board using the class -----
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			board[i][j].read(infile);
		}
	}
	infile.close(); // file no longer needed

	// ----- game starts -----
	while(Continue == true)
	{	
		N = playerx - 1;
		S = playerx + 1;
		E = playery + 1;
		W =  playery -1;

		// ---- check to make sure the locations are still in the bounds of the game -----
		// --- wraps the program around ----
		if(N == -1)
			N = 3;
		else if(S == 4)
			S = 0;
		else if(E == 4)
			E = 0;
		else if(W == -1)
			W = 3;
		// ----- player location -----
		location = board[playerx][playery].getLocation();
		
		while(validInput!= 1)
		{		
			cout<< "You are in a " << location << endl; 
			cout<< " to the North is a " << board[N][playery].getLocation();
			cout<< " to the West is a " << board[playerx][W].getLocation();
			cout<< " to the East is a " << board[playerx][E].getLocation();
			cout<< " to the South is a " << board[S][playery].getLocation() << endl; 
			cout<< "Would you like to move (1)North (2)East (3)South (4)West? (0)Exit" << endl;
			cin >> playerinput;
		
			if(playerinput > 4 || playerinput < 0)
			{
				cout << "Invalid direcion to move" << endl;
			}
			else if((playerinput == 0)|| (playerinput == 1) ||(playerinput == 2)||(playerinput == 3) ||(playerinput == 4))
			{
				validInput = 1;
				exit;
			}
			
		} // end of while loop

		validInput = 0; //  make the while loop next iteration				

		// ---- move the player based on the input -----
		switch(playerinput)
		{
		case(0):
			cout<< "END GAME" << endl;
			Continue = false;
			break; 
		case(1):
			cout<< "You move North" << endl;
			playerx = N;
			break;
		case(2):
			cout<< "You move East" << endl;
			playery = E;
			break;
		case(3):	
			cout << "You move South" << endl;
			playerx = S;
			break;
		case(4):
			cout << "You move West" << endl;
			playery = W;
			break;	
		}
	} // end of the game while loop
}

void area::read(ifstream& infile)
{
	infile >> location; 
}

string area::getLocation(){
	return location;
}


