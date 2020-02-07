 /*  The game of NIM
     Sydney Petrehn
     Section 5
     Assignment 3
     Edited to change the output, print the rules first, have running commentary, 
     the program wont lost if it doenst have to, removed the magic numbers from the code, shows the amount of objects remaining
     plays multiple games in a row without having to restart 
 */

 #include<iostream>     // include two libraries
 #include<cstdlib>
 using namespace std;

 int main()             // main() starts the actual program 
 {

    // ---------------- Variable declarations ---------------------

    int num_objects = 23; // the amount of objects at start of game 
    int current_player = 1; // the current player (Computer or person)
    int move; // the number or objects being taken out 
    int MinimumMove = 1; // the minimum move
    int MaxMove = 3; // the maximum move
    bool Continue = true; // if the player wants to continue the game or not
    int CGamesWon = 0; // the amount of games the computer has won
    int PGamesWon = 0; //  the amount of games the player has won
    int  WantContinue; // player does or doesnt want to continue (y/n)

	// ----------------- Outputs the rules of the game --------------------
	cout << "The goal of the game NIM is to remove all but one of the objects. \n You can only take away 3 objects at a time. \n each player takes a turn. \n You are player 1 \n";

	// ------------- loops the game so the game doesnt have to restart after each game and prints how many games won for player and computer. ---------
	while(Continue = true)
	{ // start of while loop
 	
	 num_objects = 23; // To ensure when looping the game will continue properly

    // ----------- Beginning of the main game loop ----------------

    do {                                      
       if (current_player == 1) {    // conditional: if
            cout << "Player 1 enter your move (1-3): ";  // output
            cin >> move;                 // input
            while (move < MinimumMove || move > MaxMove  || move > num_objects){
               cout << "Illegal move. \nEnter a new move (1-3): ";
               cin >> move;
            }
       } else {                          // controlling the AI / Computer
            do {                         // make sure move is legal
               	if(num_objects == 3) // will not lose if it doesnt have to
		{
			move = 2; // will remove two to wim
		}
		else if(num_objects == 2)
		{
			move = 1; // will remove one to win
		}
		else if(num_objects == 4)
		{
			move = 3; // will remove three to win
		}
		else
		{
			move =  MinimumMove + rand() % MaxMove;    // random computer move
		}
            } while (move < MinimumMove || move > MaxMove || move > num_objects);
        cout << "Computer removed " << move << endl;
       }// end of AI

       num_objects = num_objects - move;  // implement the move
       cout << num_objects << " objects remaining.\n";

	// ---------- loop for the number of objects remaining printed in a row ---------------
	for(int j=0; j <= num_objects; j++)
	{
		cout << "#"; // represents the amount of objects remaining
	}

       current_player = (current_player + 1) % 2;  // switch players
	
	// -------- running commentary ------------------------
	
	if( num_objects == 1)
	{
		cout << " \n Someone is about to win! \n";
	}
	if( num_objects >= 16)
	{
		cout << " \n It is still early in the game! \n";
	}
	if( num_objects == 11)
	{
		cout << " \n The game is halfway over! \n";
	}
	if( num_objects == 5)
	{
		cout << " \n Someone is about to win! \n";
	}

   } while (num_objects > 0);                    

   // ------------  end of the game loop --------------------------
   cout << "Player " << current_player << " wins!!! Congratulations!\n"; // winning message
   cout << "Player " << ((current_player + 1) % 2)  << " LOSES, sorry!\n"; // loosing message 

	if(current_player  == 1)
	{
		PGamesWon++;
	}
	else
	{
		CGamesWon++;
	}
	cout << "\n Computer has won \n" << CGamesWon; // amount of times computer has won
	cout << "\n Player has won\n" << PGamesWon; // amount of times player has won
 
   // ---------- allows user to exit the program ------------------
   cout << "\n Continue? yes = 1 no = 0 \n";
   cin >> WantContinue;
   
   if(WantContinue == 0)
	{
		Continue = false;
		break;
	}
  
  } // end of while loop 
}
