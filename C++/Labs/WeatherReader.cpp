/* Sydney PEtrehn
   Lab 8
   October 17
*/

#include<iostream>
#include<fstream>
using namespace std;

const int size = 30;

int main()
{
	// ------ Variables ---------
	int arrayDate[size], arrayYear[size];
	string arrayMonth[size];
	double arrayHigh[size], arrayLow[size], arrayPrecip[size], arraySnow[size], arraySnowDepth[size];
	ifstream infile;
	double high;
	double low;
	double aHigh;
	double aLow;
	double snowChange;	
	double amountChange;
	string x;

	// ------ Opens the File ------
	infile.open("weather.txt");
	if(!infile)
	{
		cout << "Unable to open file" << endl;
	}
	infile >> x;
	infile >> x;
	infile >> x;
        infile >> x;
	infile >> x;
        infile >> x;
		
	// ------ Saves data from file to array -----
	// data arrays
	for(int i = 0; i < size; i++)
	{
		
		infile >> arrayDate[i];
		infile >> arrayMonth[i];
		infile >> arrayYear[i];
		infile >> arrayHigh[i];
		infile >> arrayLow[i];
                infile >> arrayPrecip[i];
                infile >> arraySnow[i];
                infile >> arraySnowDepth[i];
	}
	
	// ---- Calculating high from Data ------
	high = arrayHigh[0];
	for(int i = 0; i <= size; i++)
	{
		if(high < arrayHigh[i])
		{
			high = arrayHigh[i];
		}// end of if
	}// end of for loop
	cout << "Highest recorded temperature: " << high << endl;

	// ----- Calculating low from Data-------
	low = arrayLow[0];
	for(int i = 0; i <= size; i++)
	{
		if(low > arrayLow[i])
		{
			low = arrayLow[i];
		}// end of if
	}// end of for
	cout << "Lowest recorded temperature: " << low << endl;

	//-----  Calculating average high ----
	for(int i = 0; i <= size; i++)
	{
		aHigh += arrayHigh[i];	
	}
	aHigh = aHigh / 31; // 31 because 31 days recorded
	cout << "Average Highest Temperature: " << aHigh << endl;

	//-----  Calculating Average Low -----
	aLow = 0;
	for(int i = 0; i<= size; i++)
	{
		aLow += arrayLow[i];
	}
	aLow = aLow / 31;
	cout << "Average Lowest Temperature: " << aLow << endl;
	
	// ----- Reports the daily change in snow depth
	cout << "Starting day 1: Snow is 9.02 the change is as follows:" << endl;
	snowChange = arraySnowDepth[0];
	for(int i = 1; i <= size; i++) // starting at 1 so that the day 0 and day 1 are compared
	{
		amountChange = snowChange -  arraySnowDepth[i];// minus to get the amount
		cout << "The change in snow depth for day " << (i+1) << " is: " << -amountChange << endl;
		snowChange = arraySnowDepth[i];
	}

}// end of main

