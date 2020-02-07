/* Sydney Petrehn
   Assignment 4
   section 5
   A simple text based game
*/

#include <iostream>
using namespace std;

// ---------------- Functions (rooms) -------------
double kitchen (double g);
double diningRoom (double g);
double bedRoom (double g);
double entryWay (double g);
double staircase (double g);
double hallway (double g); 

// -------------- global variable -----------------------
// gold is in the structure
double KitchenHasVisit;
double BedRoomHasVisit;

// ------------------- Structures (Adventurer) ----------------------

typedef struct Adventurer // this will save the player 
{
   int gold;  // the amount of gold the player has
   double health; // the amount of health the player has
   char name[100]; // the name the player chooses (up to 100 characters)
} Adventurer;

Adventurer initializeAdventurer();// initializes the player
void printAdventurer(Adventurer); // will print out first time without any of the player input

// -----------------Main part of program --------------

int main ( ) 
{

// --------------- local variable decliration ----------------
bool Continue = true; // the player wants to continue the program
int roomChoice; // which room the player chooses to enter.

// ------------ creates the player -------------------

struct Adventurer player;// creates the player for given values
player = initializeAdventurer();// initializes the player

// ---------------- while loop to continue the program

while(Continue == true)

{ // start of while loop

// ---------------- room selection ------------------

cout << endl;
printAdventurer(player);// will print out the starting and all changes to the player

cout << "\n  Aquire more Gold by visiting rooms!\n" << endl;// intentially doing two endlines for more space

cout << "You are wandering a house. press (1)kitchen (2)dining room (3)bedroom (4)entryway (5)staircase  (6)hallway (0) to exit." << endl;
 // ^ will repeat every time the user goes back to the "main"

cin >> roomChoice; // what room the user chooses to go to

if( roomChoice == 1)
{
 player.gold = kitchen(player.gold);
  KitchenHasVisit++;
}
else if( roomChoice == 2)
{
  player.gold =  diningRoom(player.gold);
}
else if( roomChoice == 3)
{
  player.gold =  bedRoom(player.gold);
  BedRoomHasVisit++;
}
else if( roomChoice == 4)
{
   player.gold = entryWay(player.gold);
}
else if( roomChoice == 5)
{
   player.gold = staircase(player.gold);
}
else if( roomChoice == 6)
{
   player.gold =  hallway(player.gold);
}
else if(roomChoice == 0)
{
   Continue = false; // will exit the program
}

}// end of while loop
}   

double kitchen (double g)
{

 // -- user input to do extra stuff in this room 
 int Userinput;
 if(KitchenHasVisit == 0)
 {

 cout << "\n You enter the kitchen. \n You aquire 30 gold! \n";
 cout << "\n Explore? 1 - Yes 0 - No \n";
 cin >> Userinput;

 if(Userinput == 1) // user chose to explore
	{
		cout << "\n You look explore the room and find nothing.";
		g += 30;
	}

 }
 else
	{
		cout << "\nYou have been here before \n";
	}

 cout << "\nPress 0 to go back to the main house.\n";
 cin >> Userinput;
 if(Userinput == 0)
	{
		return g;
	}
}

double diningRoom (double g)
{
 int Userinput; // if user wants to leave the room
 cout << "You enter the dining room. \n You aquire 5 gold!";
 g += 5;
 cout << "\nPress 0 to go back to the main house.\n";
 cin >> Userinput;
 if(Userinput == 0)
        {
                return g;
        }
}

double bedRoom (double g)
{
 int Userinput; // if user wants to leave the room

 if(BedRoomHasVisit == 0)
	{
 		cout << "You enter the bed room. \n You lose 5 gold!";
 		g -= 5;
	}
 else
	{
		cout << "You have been here before.";
	}

 BedRoomHasVisit++;
 cout << "\nPress 0 to go back to the main house.\n";
 cin >> Userinput;
 if(Userinput == 0)
        {
                return g;
        }
}

double entryWay (double g)
{
 int Userinput; // if user wants to leave the room

 cout << "You enter the entry way. \n you aquire 15 gold!";
 g +=15;
  cout << "\nPress 0 to go back to the main house.\n";
 cin >> Userinput;
 if(Userinput == 0)
        {
                return g;
        }
}

double staircase (double g)
{
 int Userinput; // if user wants to leave the room
 cout << "You enter the stair case. \n you aquire 10 gold!";
 g += 10;
 cout << "\nPress 0 to go back to the main house.\n";
 cin >> Userinput;
 if(Userinput == 0)
        {
                return g;
        }
}

double hallway (double g)
{
 int Userinput; // if user wants to leave the room

 cout << "You enter the hall way. \n you aquire 10 gold!";
 g += 10;
 cout << "\nPress 0 to go back to the main house.\n";
 cin >> Userinput;
 if(Userinput == 0)
        {
                return g;
        }
}

Adventurer initializeAdventurer()
{
   Adventurer p;
   p.gold  = 0;
   p.health = 100;
   cout << "Enter Your Name ";
   cin >> p.name;
   return p;
}

void printAdventurer(Adventurer p)
{
   cout << " Gold: " << p.gold;
   cout << " Health: " << p.health;
   cout << " Name: " << p.name;
   cout << endl;
}
