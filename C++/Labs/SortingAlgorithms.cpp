/* Sydney Petrehn
   Lab 11
   Sorting Algorithm

*/

#include<iostream>
#include<fstream>
#include<ctime>


using namespace std;

const int size = 2000;

// ----- function fragments -----
int arraySearch(string a[], int b, string c);
void arraySort(string a[], int b);
int arrayBubble(string a[], int b, string c);

int main()
{
        // ------ Variables ---------
        string arrayNames[size];
	//string arraySorted[];
	ifstream infile;        
	string nameSearch;
	int inarray;

	// ------ Opens the File ------
        infile.open("namedata.txt");
        if(!infile)
        {
                cout << "Unable to open file" << endl;
        }
        
        // ------ Saves data from file to array -----
        // data arrays
        for(int i = 0; i < size; i++)
        {

                infile >> arrayNames[i];
        }
	
	int sum = 0;

	cout << "What name do you want to search for?" << endl;
	cin >> nameSearch;
	
	// ----- determine if name in array and prints time-----

	double start_s=clock();
	inarray = arraySearch(arrayNames, size, nameSearch);
	
	if(inarray != -1)
	{
		cout << "The name: " << nameSearch << " is in the array at the location:" << inarray << endl;
	}
	else
	{
		cout << "The name: " << nameSearch << " is not in the array" << endl;
	}
	// runs 20 times and determines the average
	 sum + inarray;	
         sum += arraySearch(arrayNames, size, "Douglas");
         sum += arraySearch(arrayNames, size, "Fate");
         sum += arraySearch(arrayNames, size, "Roy");
         sum += arraySearch(arrayNames, size, "Author");
         sum += arraySearch(arrayNames, size, "Bella");
         sum += arraySearch(arrayNames, size, "Pete");
         sum += arraySearch(arrayNames, size, "Mallie");
         sum += arraySearch(arrayNames, size, "James");
         sum += arraySearch(arrayNames, size, "Hugh");
         sum += arraySearch(arrayNames, size, "Sam");
         sum += arraySearch(arrayNames, size, "August");
         sum += arraySearch(arrayNames, size, "Isaac");
	 sum += arraySearch(arrayNames, size, "Nella");
         sum += arraySearch(arrayNames, size, "Claudia");
         sum += arraySearch(arrayNames, size, "Park");
         sum += arraySearch(arrayNames, size, "Garrett");
         sum += arraySearch(arrayNames, size, "Fay");
         sum += arraySearch(arrayNames, size, "Elmer");
         sum += arraySearch(arrayNames, size, "Aimee");
	
	 double stop_s=clock();

        cout<< "the average time to sort the unsorted list is time: " << 1.0* (stop_s - start_s) << endl;
	
	sum = sum / 20;
	cout << "The average amount of comparisons on the nonsorted array was: " << sum << endl;

	// ----- sort the array -----
	arraySort(arrayNames, size);
	
/*	// ----- print the array -----
	for(int i = 0; i < size; i++)
	{
		cout << arrayNames[i] << endl;
	}
*/	
 	 sum = 0;

	// ----- binary sort the array and find the name in the sorted array -----
	// print out the amount of time to sort the array

        int start_t=clock();
	 sum += arrayBubble(arrayNames, size, nameSearch);
         sum += arrayBubble(arrayNames, size, "Douglas");
	 sum += arrayBubble(arrayNames, size, "Fate");
	 sum += arrayBubble(arrayNames, size, "Roy");
	 sum += arrayBubble(arrayNames, size, "Author");
	 sum += arrayBubble(arrayNames, size, "Bella");
	 sum += arrayBubble(arrayNames, size, "Pete");
	 sum += arrayBubble(arrayNames, size, "Mallie");
	 sum += arrayBubble(arrayNames, size, "James");
	 sum += arrayBubble(arrayNames, size, "Hugh");
	 sum += arrayBubble(arrayNames, size, "Sam");
	 sum += arrayBubble(arrayNames, size, "August");
	 sum += arrayBubble(arrayNames, size, "Isaac");
	 sum += arrayBubble(arrayNames, size, "Nella");
	 sum += arrayBubble(arrayNames, size, "Claudia");
	 sum += arrayBubble(arrayNames, size, "Park");
	 sum += arrayBubble(arrayNames, size, "Garrett");
	 sum += arrayBubble(arrayNames, size, "Fay");
	 sum += arrayBubble(arrayNames, size, "Elmer");
	 sum += arrayBubble(arrayNames, size, "Aimee");

	 int stop_t=clock();

        cout<< "the average time to sort the unsorted list is time: " << ((stop_t - start_t)/double(CLOCKS_PER_SEC)*1000) / 20 << endl;

	
	sum = sum / 20;

	cout << "The average number of comparisons on the alphabetical sorted array were: " << sum << endl;
	
 
}

int arraySearch(string a[], int b, string c)
{
	for(int i = 0; i < b; i++)
	{
		if(a[i] == c)
		{
			return i;
			
		}
	}	
	return -1;
}

void arraySort(string a[], int b)
{
	string temp;
	int counter = 1;
	do
	{
		for(int i = 1; i < b; i++)
		{
			if(a[i] < a[i-1])
			{
				temp = a[i-1];
				a[i-1] = a[i];
				a[i] = temp;
			}
		}
		counter++; 
	 }while(counter < b);
	cout << "The program took: " << counter << " times to sort the array alphabetically." << endl;
}

int arrayBubble(string a[], int b, string c)
{
	bool found = false;
	int first = 0;
	int counter = 0;
	int position;
	int last = b;
	while( (found != true) && (first <= last) )
	{
		int middle = (first + last) / 2;
		
		if(a[middle] == c)
		{
			found = true;
			position = middle;			
			counter++;	
			return counter;
		}
		else if(a[middle] > c)
		{
			last = middle -1;
			counter++;
		}
		else
		{
			first = middle + 1;
			counter++;
		} 
	}
}
