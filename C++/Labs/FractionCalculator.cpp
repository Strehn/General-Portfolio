/* Sydney Petrehn
   Lab 7
   Section 5
*/

#include <iostream>
using namespace std;

//---- fraction class----

class fraction
{
	private:
	 int numerator; // private data member
         int denominator; // private data member
	public:
	 // ------ functions the user can choose
	 fraction(); // constructor which creates the fraction
	 void printImproper(); // public 
	 void printMixed();   // public
	 void printDecimal(); // public
	 void add(fraction, fraction); //public
	 void subtract(fraction, fraction); //public
	 void multiply(fraction, fraction); // public
	 void divide(fraction, fraction); // public
	 void integerAdd(); // extra credit
};

int main()
{
	// ----- Variables -----
	int choice;

	// ----- Create Fractions ------
	fraction fraction1;
	fraction fraction2;
	fraction fraction3;

	// ----- user chooses what to do with fractions	
 	do
	{
             	cout << "What would you like to do with the fractions?\n";
        	cout << "Print Improper Fraction (1) \n Print Mixed Fraction (2) \n Print Decimal (3) \n Add Fractions (4) \n Subtract Fractions (5) \n Multiply Fractions (6) \n  Divide Fractions (7) \n Add an integer (8) \n Exit (0) \n";
        	cin >> choice;
        	switch(choice)
		{
        	case 1:
        		fraction1.printImproper();
			fraction2.printImproper();
			fraction3.printImproper();

			break;
       		case 2:
        	    	fraction1.printMixed();
			fraction2.printMixed();
			fraction3.printMixed();
        	    	break;
        	
		case 3:
			fraction1.printDecimal();
			fraction2.printDecimal();
			fraction3.printDecimal();
			break;
	      	case 4:
			fraction1.add(fraction1,fraction2);
			break;
		case 5:
			fraction1.subtract(fraction1,fraction2);
			break;
		case 6:
			fraction1.multiply(fraction1,fraction2);
			break;
		case 7:
			fraction1.divide(fraction1,fraction2);
			break;
		case 8:
			fraction1.integerAdd();
			break;
		} // end of switch
   	} while(choice != 0);

        // if the user chooses to exit then this code will run
	cin.ignore();
        cout << "Press enter to exit." << endl;
        cin.ignore();
        return 0;

}

// ------ Constructor, creates a new fraction

fraction::fraction()
{
        cout << " Enter the numerator" << endl;
        cin >> numerator;
        cout << "Enter the denominator" << endl;
	cin >> denominator;
	
	if( denominator == 0 )
	{
		numerator = 0;
		denominator = 1;
	}
}

// allows user to print as an inproper fraction
void fraction::printImproper()
{
	cout << "Fraction as an improper is " << numerator << "/" << denominator << endl << endl;
}

void fraction::printMixed()
{
	int mixedD, mixedN, mixedV;
	mixedV = numerator/denominator;
	mixedN = numerator%denominator;
	mixedD = denominator;

	cout << "fraction as a mixed fraction is " << mixedV << " "  << mixedN << "/" << mixedD << endl << endl;
}

void fraction::printDecimal()
{
	double dec =(double)  numerator/(double) denominator;
	cout << "Fraction as a decimal is " << dec  << endl << endl;
}

void fraction::add(fraction x, fraction y)
{
	int addedN;
	int addedD;
	
	if(x.denominator == y.denominator)
	{
		addedN = x.numerator + y.numerator;
		addedD = x.denominator;
	}
	else
	{
		addedD = x.denominator * y.denominator;
		addedN = (x.numerator * y.denominator) + (y.numerator * y.denominator);
	}	

	cout << endl << "Added Fraction is " << addedN << "/" << addedD << endl << endl;
}

void fraction::subtract(fraction x, fraction y)
{
	int subN;
        int subD;
        
        if(x.denominator == y.denominator)
        {
                subN = x.numerator - y.numerator;
                subD = x.denominator;
        }
        else
        {
                subN = (x.numerator * y.denominator) - (y.numerator * y.denominator);
                subD = x.denominator * y.denominator;
        }

        cout << endl << "Subtracted Fraction is " << subN << "/" << subD << endl << endl;
}

void fraction::multiply(fraction x, fraction y)
{
	int Denom = x.denominator * y.denominator;
	int Num = x.numerator * y.numerator;

	cout << endl << "Multiplied Fraction is " << Num << "/" << Denom << endl << endl;
}

void fraction::divide(fraction x, fraction y)
{
	int Denom = y.numerator; // to divide you cross multiply which is why this is the numerator
	int Num = y.denominator;// this is denom to reverse the fraction

	int dNum = x.numerator * Num;
	int dDenom = x.denominator * Denom;
	
	cout << endl << "Divided Fraction is " << dNum << "/" << dDenom << endl << endl;
}

void fraction::integerAdd()
{
	int Cnum = numerator + (denominator) ;
	int Cdem = denominator;
	cout << numerator << "/" << denominator << "Plus 1 is:" << Cnum << "/" << Cdem << endl << endl;
}

