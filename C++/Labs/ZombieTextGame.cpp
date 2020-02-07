/* Sydney Petrehn
   Assignment 8
   October 17 2017
   Assignment edited to be Customized, added intro, 
   modified to make easier to read, created a new score variable,
   edited square class to add in a the score variable, changed vicotry
   conditions to be based on the new score variable.
*/

#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;


//Declaration of the square class
class square
{
  private:
    int move;
    string message;
    char symbol;
    int health;
  public:
    square();
    void print();
    int action();
    void set(int,char,string,int);
    int chealth();
};

// Function Prototypes
void print_board(square[], int, int);
void read_board(square[]);
void check_position(int &);

// Global variables
const int board_length = 20;

int main()
{
	// ---- introduction -----
	cout << endl << "WELCOME TO THE ZOMBIE APOCALYPSE GAME" << endl;
	cout << "Your goal is to get to safety" << endl;
	cout << "If you get blocked by a horde you move back two squares" << endl;
	cout << "Your health also goes down if you fight a zombie" << endl;
	cout << "You can be helped by strangers and they will move you forward 1 square" << endl << endl;
	
	// ---- variables ----
	int current_player = 1, roll;
  	int player1_position = 0, player2_position = 0, player1_health = 80, player2_health = 80;
  	square the_board[board_length];  // declare an array of squares
 	srand(time(NULL));
  	read_board(the_board);
 	print_board(the_board,player1_position,1);
  	print_board(the_board,player2_position,2);
  	
	// ----- plays the game -----
	do
	{
      		cout<<"\n\n\nPlayer "<<current_player<<" type enter to roll.\n";
      		cin.ignore();
      		roll = 1 + (rand() % 5);
      		cout << "Player: " << current_player << " rolled a " << roll <<".\n";
      		if(current_player == 1)
		{
        		 player1_position += roll;
         		check_position(player1_position);
			player1_health -= the_board[player1_position].chealth();
         		player1_position += the_board[player1_position].action();
         		check_position(player1_position);
			cout << endl << "Player 1 health: " << player1_health << endl;
		}
     		else	
		{
        		player2_position += roll;
        		check_position(player2_position);
			player2_health -= the_board[player2_position].chealth();
			player2_position += the_board[player2_position].action();
        		check_position(player2_position);
			cout << endl << "Player 2 health: " << player2_health << endl;
	   	}
     		print_board(the_board,player1_position,1);
     		print_board(the_board,player2_position,2);
     		current_player = (current_player % 2) + 1;
  	}while((player1_position<board_length-1) && (player2_position<board_length-1));
  	
	// ----- Determins the winner using health ----
	if(current_player == 1)
	{
		if(player1_health <= 0)
		{
			cout << "Player 2 Wins" << endl;
		}
		else
		{
			current_player = (current_player % 2) + 1;
  			cout << "\nPlayer " << current_player << " Wins!!!\n";
  			cin.ignore();
  			return 0;
		}
	}
	else
	{
		if(player2_health <= 0)
		{
			cout << "Player 1 Wins" << endl;
		}
		else
		{
			 current_player = (current_player % 2) + 1;
                        cout << "\nPlayer " << current_player << " Wins!!!\n";
                        cin.ignore();
                        return 0;
                }
	}
}


void read_board(square b[]){
     ifstream infile;
     infile.open("game.txt");
     int square_number, square_move, square_health;
     string square_message;
     char square_symbol;
     while(!infile.eof()){
         infile >> square_number >> square_move >> square_symbol >> square_health;
         getline(infile,square_message);
         if(square_number < board_length)
               b[square_number].set(square_move,square_symbol,square_message, square_health);
     }
}

void print_board(square b[], int player_position, int player_number){
     for(int i = 0; i < board_length; i++){
         if(i != player_position)
             b[i].print();
        else
             cout << player_number;
    }
    cout << "|SAFETY| \n";
    cout << "\n";
}
void check_position(int &p){
    if(p < 0)
         p = 0;
    if(p >= board_length)
         p = board_length-1;
}


// Functions of the class square
square::square(){
     symbol = '|';
     move = 0;
     message = "";
     health = 0;
}
int square::action(){
     cout << message << endl;
     return move;
}
void square::print(){
     cout << symbol;
}
void square::set(int m, char s, string a_message, int h){
     move = m;
     symbol = s;
     message = a_message;
     health -=  h;
}

int square::chealth()
{
	return health;
}
