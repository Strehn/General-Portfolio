 /* sydney Petrehn
   Assignment 9
   Section 5
*/

#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;


// ----------  declaration of the pet class

class pet{
   private:
      int hunger;           // private data member
      string name;          // private data member
      int happy;            // private data member
      string species;       // private data member
	int sleepy;
   public:
      pet();                // constructor
      void play();          // public member function
      void feed();          // public member function
      void print();         // public member function
      int check_health();   // public member function
      void random();
      void sleep();
      void pname();
};

int main()
{
   pet pet[4];// added an array of pet objects so each pet is different
   int choice;
   int health_check1=1;
   int health_check2=1;
   int health_check3=1;
   int health_check4=1;   
 
   do{
	int randomInt = ((rand() % 10)%10)+1;

       pet[0].print();
       pet[1].print();
       pet[2].print();
       pet[3].print();

       cout << "\n Which pet do you want to play with?\n";

       if(health_check1 == 1)
	{
	cout << "\n 1) "; 
	pet[0].pname(); 
        }
	if(health_check2 == 1)
	{
	 cout << "\n 2)";
        pet[1].pname();
        }
	if(health_check3 ==1 )
	{
	 cout << "\n 3)";
        pet[2].pname();

	}
       if(health_check3 == 1)
	{
	 cout << "\n 3) ";
        pet[3].pname();

	}

	cin >> choice;
	
	// pet 1
	if(choice == 1)
	{
         cout << "What would you like to do with your pet?\n";
         cout << " Play (1) \n Feed (2) \n Sleep (3) \n  Exit (0) \n";
         cin >> choice;
         switch(choice){
       case 1:
           pet[0].play();
           break;
       case 2:
           pet[0].feed();
           break;
       case 3:
	   pet[0].sleep();
	   break;
      }
      	pet[randomInt].random();
	health_check1 = pet[1].check_health();
	}

	// pet 2
	if(choice == 2)
        {
       cout << "What would you like to do with your pet?\n";
       cout << " Play (1) \n Feed (2) \n Sleep (3) \n  Exit (0) \n";
       cin >> choice;
       switch(choice){
       case 1:
           pet[1].play();
           break;
       case 2:
           pet[1].feed();
           break;
       case 3:
           pet[1].sleep();
           break;
      }
        pet[randomInt].random();
        health_check2 = pet[2].check_health();
        }

	// pet 3
	if(choice == 3)
        {
       cout << "What would you like to do with your pet?\n";
       cout << " Play (1) \n Feed (2) \n Sleep (3) \n  Exit (0) \n";
       cin >> choice;
       switch(choice){
       case 1:
           pet[2].play();
           break;
       case 2:
           pet[2].feed();
           break;
       case 3:
           pet[2].sleep();
           break;
      }
        pet[randomInt].random();
        health_check3 = pet[3].check_health();
        }

	// pet 4
	if(choice == 4)
        {
       cout << "What would you like to do with your pet?\n";
       cout << " Play (1) \n Feed (2) \n Sleep (3) \n  Exit (0) \n";
       cin >> choice;
       switch(choice){
       case 1:
           pet[3].play();
           break;
       case 2:
           pet[3].feed();
           break;
       case 3:
           pet[3].sleep();
           break;
      }
        pet[randomInt].random();
        health_check4 = pet[4].check_health();
        }

   }while(choice != 0 && ((health_check1 && health_check2 && health_check3 && health_check4) != 0));
   cin.ignore();
   cout << "Press enter to exit." << endl;
   cin.ignore();
   return 0;
}

/* Constructor, creates a new pet with starting values. */
pet::pet(){
     hunger = 50;
     happy = 50;
     sleepy = 50;
     cout << "Pet's name? (One word) ";
     cin >> name;
     cout << "What species is your pet? (Example: dog, cat, bird)" << endl;
     cin >> species;
}

/* Member function play(), allows playing with a pet. */
void pet::play(){
	cout << name << " ";
    int choice = 0;
    cout << "What should we play?\n";
    cout << " Fetch (1) \n Roll over (2) \n";
    cin >> choice;
    switch(choice){
    case(1):
         happy += 10;
         hunger += 5;
	 sleepy += 10;
         cout << "Your pet fetches a ball and brings it back to you. How Fun!" << endl; // i added this
	 break;
    case(2):
         happy += 5;
         hunger += 1;
	 sleepy += 5;
	 cout << "Your pet rolls over on the ground. How cute!." << endl; // i added this
         break;
    default:
         cout << "Not a valid choice." << endl;
   }
}

/* Member function feed(), allows the user to feed a pet. */
void pet::feed(){
	cout << name << " ";
    int choice = 0;
    cout << "What should we eat?" << endl; // i added this
    cout << " Treats (1) \n Candy (2) \n Animal Food (3) \n"; // gives options
    cin >> choice;
    switch(choice)
    {
    case(1):
	happy += 10;
	hunger -= 5;
	sleepy += 5;
	cout << " That was yummy" << endl;	
	break;
    case(2):
	happy += 20;
	hunger -= 1;
	sleepy += 5;
	cout << "That made me happy, but im still hungry!" << endl;
	break;
    case(3):
	happy += 3;
	hunger -= 20;
	sleepy += 5;
	cout << "Im full!" << endl;
	break;
    default:
	cout << "Not a valid choice." << endl;
    } // end of switch
}
// prints out the pets name
void pet::pname()
{
	cout << name;
}
/* Member function print(), prints information about a pet. */
void pet::print(){
    cout << "\nYour pet " << name << " is ";
    cout << "Happy: " << happy << endl;
    cout << "Hungry: " << hunger << endl;
    cout << "Species: " << species << endl;
    cout << "Sleepiness: " << sleepy << endl << endl;
}

/* Member function check_health(), checks the health of a pet. */
int pet::check_health(){
    if(hunger >= 100){
         cout << "\nYour pet has starved.\n";
         return 0;
    }
    if(happy <= 0){
         cout << "\nYour pet has died of a broken heart.\n";
         return 0;
    }
    if(sleepy >=100)
	{
		cout << "\n Your pet has died from sleep deprivation. \n";
		return 0;
	}
    return 1;
}


void pet::sleep()
{
	cout << "Your pet sleeps" << endl;
	happy += 10;
	sleepy -= 50;
	hunger += 5;
}

void pet::random()
{
	cout << "A Random Event is happening to " << name << "." << endl;
	srand((unsigned)time(0));
	int randomInt;
	for(int i = 0; i < 10; i++)
	{
		randomInt = ((rand()%10) + 1);
	}
	switch(randomInt)
	{
	case(1):
		cout << "Your pet fights a skunk. Happiness is down." << endl;
		happy -= 20;
		sleepy += 5;
		break;
	case(2):
		break;
	case(3):
		cout << "Your pet finds food. Hunger goes down;" << endl;
		hunger -= 5;
		break;
	case(4):
		break;
	case(5):
		cout << "Your pet plays with the cat." << endl;
		happy +=10;
		hunger += 10;
		sleepy += 10; 
		break;
	case(6):
		break;
	case(7):
		break;
	case(8):
		break;
	case(9):
		break;

	}
}
