   /* The fortune Teller -
      Sydney Petrehn
      Session 5 
      Computer Science 120 Lab #1

    * a simple program introducing some
    * fundimental programming concepts.	
    Modified to ask for age,
    Use Age to calculate the new magic number
    Give another output option if the number is over 20
    Extra Work: added a fourth input (shoe size)  from the user and used to calc. the magic number
	*/


#include<iostream> // include a library
using namespace std;

int main()  // main() starts the program

{
	// -------------- Variable Declarations ------------------
 	int favorite;  // create a variable to store the favorite number
        int disliked;  // create a variable to store the disliked number
	int lucky;     // create a variable to store the lucky number
	int age ;      // create a veriable to store the age
	int shoeSize; // create a variable to store the shoe size        

	// ------------- Get user input -------------------------
	cout << "Enter your favorite number (no decimals): ";  // output
	cin >> favorite;  		// user input
	cout << "Enter a number you don't like (no decimals): "; // disliked number
	cin >> disliked;
	cout << "Enter your age: ";  // age
	cin >> age;
	cout << "Enter your shoe size (no decimals): "; // shoe size
	cin >> shoeSize;
	lucky = (favorite * disliked - shoeSize + (age % 10) % 10);
	cout << endl << "Your secret, lucky number is: " << lucky << endl;
	if(lucky < 0){  // conditional, calues less than 0
		cout << "Try to be less negative." << endl;
	}
	if(lucky >= 0 && lucky < 5){ // 0 to 4 inclusive
		cout << "Think bigger!" << endl;
	}
	if(lucky >= 5 && lucky < 9){ // 5 to 8 inclusive
		cout << "Today you should embrace technology." << endl;
	}
	if(lucky == 9){ // exactly 9
		cout << "Today is your lucky day!" << endl;
	}
	if(lucky >= 10) // if lucky is greater than or equal to 20 
	{
		cout << " Today is not your lucky day!" << endl;
	}
	
	// ---------- Code to help the program exit "gracefully" -----
	cin.ignore();
 	cout << "Press enter to quit." << endl;
	cin.ignore();
	return 0;
}
