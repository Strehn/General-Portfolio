/* sydney petrehn
   lab 5
    26 September 2017
   program which creates a data structure for the game
   i used gold so i will store that and i will also store the players name
   i also will add in health
*/

#include<iostream>
using namespace std;


typedef struct Adventurer // this will save the player names 
{
   int gold;  // the amount of gold the player has
   double health; // the amount of health the player has
   char name[100]; // the name the player chooses (up to 100 characters)
} Adventurer;

Adventurer initializeAdventurer();
void printAdventurer(Adventurer); // will print out first time without any of the player input

int main(){
  struct Adventurer player1; // first player
  player1 = initializeAdventurer(); // creates the player1 structure as a new adventurer
  printAdventurer(player1); // original value of the player
  player1.gold++;  // gains gold
  printAdventurer(player1); // shows how the program has changed
  
  struct Adventurer player2; // second player
  player2 = initializeAdventurer(); // gets all the information for the player
  printAdventurer(player2); // prints out the second player
  player2.health--; // takes away health
  printAdventurer(player2); // shows how player 2 has changed
}

Adventurer initializeAdventurer(){
   Adventurer p;
   p.gold  = 0;
   p.health = 100;
   cout << "Enter Your Name ";
   cin >> p.name;
   return p;
}

void printAdventurer(Adventurer p){
   cout << " Gold: " << p.gold;
   cout << " Health: " << p.health;
   cout << " Name: " << p.name;
   cout << endl;
}
