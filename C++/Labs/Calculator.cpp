/* A simple calculator program,
controlled by a menu and 
divided into separate functions
Sydney Petrehn
Section 5
September 19 2017
Lab number 4

 */

#include<iostream>
#include<cmath>
using namespace std;

//---------- Function Prototypes -----------
void print_menu();
double get_value();
double divide(double,double);
double surfaceA(double, double); // added surface area calculation
double volume( double, double); // added volume
double surfaceCone(double,double); // added surface area of a cone

//--------------  Main -------------------

int main()
{	
     double operand1, operand2,operand3, answer;
     int choice, valid_choice;
     do{
           print_menu();
           cin >> choice;
           valid_choice = 1;           // assume choice is valid

           switch(choice){
           case 0:                    // program will exit
                valid_choice = 0;  
		break;
           case 1:                    // addition
                  operand1 = get_value();
                  operand2 = get_value();
		valid_choice = 1;
                  answer = operand1 + operand2;
                   break;
            case 2:                    // division
                   operand1 = get_value();
                   operand2 = get_value();
		 valid_choice = 2;

                   answer = divide(operand1,operand2);
                   break;
	    case 3:                     // subtraction
		   operand1 = get_value();
		   operand2 = get_value();
			 valid_choice =3;

		   answer = operand1 - operand2;
			break;
	    case 4:
		   operand1 = get_value();
                   operand2 = get_value();
			 valid_choice = 4;

                   answer = surfaceA(operand1, operand2);
			break;
	    case 5:
		    operand1 = get_value();
                   operand2 = get_value();
			 valid_choice = 5;

                   answer = volume(operand1, operand2);
			break;
	    case 6:
		    operand1 = get_value();
                   operand2 = get_value();
			 valid_choice = 6;

                   answer = surfaceCone(operand1, operand2);
			break;


            default:
                   valid_choice = 0;   // choice is invalid
                   cout << "Invalid Choice." << endl;
            }
            if(valid_choice == 1 ){   // if choice is valid, print the answer
                   cout << endl  << operand1 << " + " << operand2 << " = " << answer << endl;
            }
	    else if( valid_choice == 2)
	    {
		cout << endl << operand1 << " % " << operand2 << " = " << answer << endl;
	    }
	    else if( valid_choice == 3)
	{
		cout << endl << operand1 << " - " << operand2 << " = " << answer << endl;
	}
		else if(valid_choice == 4)
	{
		cout << endl << " 2 * " <<  " 3.14 * " << operand1 << " * " << operand2 << " + " << " 2 * " << " 3.14 * " << pow(operand1, 2) << " = "  << answer << endl;
	}
       else if(valid_choice == 5)
	{
	 	cout << endl << " 3.14 * " << pow(operand1, 2) << " * " << operand2 << " = " << answer << endl;
	}
         else if(valid_choice == 6)
	{
		 cout << endl << " 3.14 " << operand1 << " ( " << operand1 << " + " << sqrt(pow(operand2, 2) + pow(operand1, 2)) << " = " << answer << endl;

	}
  
      }while(choice != 0);    // if not 0, loop back to start
     
}

//--------------  Functions -------------------
double divide(double dividend, double divisor)
{
      if(divisor == 0){
            return 0;  // avoids divide by zero errors
      }
      else
            return (dividend / divisor);
}
double surfaceA(double radius, double height)
{
	return (( 2 * 3.14 * radius * height) + ( 2 * 3.14 * pow(radius, 2)));
}

double volume(double radius, double height)
{
	return ( 3.14 * pow(radius, 2) * height);
}
double surfaceCone(double radius, double height)
{
	return ( 3.14 * radius * (radius + sqrt(pow(height, 2) + pow(radius, 2))));
}

//----------------- get_value function ----------------
double get_value()
{
      double temp_value;
      cout << "Please, enter a value: ";
      cin >> temp_value;
      cout << "Thanks." << endl;
      if(temp_value != 0)
	return temp_value;
}

//-------------------- print_menu function -------------
void print_menu()
{
     cout << endl;
     cout << "Add (1)" << endl;
     cout << "Divide (2)" << endl;
     cout << "Subtraction (3) " << endl;
	cout << "surface area (4)" << endl;
     cout << "volume  (5)" << endl;
     cout << "surface area cone (3) " << endl;

     cout << "Exit (0)" << endl;
     cout << "Enter your choice: ";
}


