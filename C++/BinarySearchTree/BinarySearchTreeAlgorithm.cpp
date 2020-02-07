/* Sydney Petrehn
   binary search tree program for a TV channel
   prog4.cpp
 *   Test Binary Search Tree (BST)
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

#include "btree.h"

// ----- FUNCTION PROTOTYPES -----
void GetName(BinarySearchTree t);
void PrintAActors(BinarySearchTree t);
void PrintASA(BinarySearchTree t);
void PrintTimeFrame(BinarySearchTree t);

int main()
{

  // ----- VARIABLES -----
  ifstream infile;
  bool cont = true;
  const int MAX_LINE = 128;
  string line;
  string seriesName;
  int  Sdate, Edate;
  string category, url;
  string actors[30]; // double because there can be a lot of actors
  string actline;
  // ----- OPEN THE FILE & CHECK -----
  infile.open("tvDB.txt");
  if(!infile)
    {
      cout << "unable to open file" << endl;
    }

  // ----- MAKE THE BINARY TREE -----
  BinarySearchTree t;

  // ----- PUT ALL DATA INTO BINARY TREE -----    
  getline(infile, line);
  
  while(!infile.eof()) // loops until end of fhile
      {
	seriesName = line.substr(0, (line.find("(") -1)); // finds just the name
	// date
	string temp = line.substr((line.find("C") +1), 4);
	stringstream ss(temp); // finds the year
	ss >> Sdate;
	
	// handles the next couple lines that are easy to obtain
	cout<< "here" << endl;

	getline(infile,category);
	getline(infile, url);

	cout<< seriesName << Sdate;
	cout<< "here" << endl;
	// obtains all the actors names
	int j = 0;
	while(line > "  ")
	  {
	    if(line.substr(2) >" ")
	      {
		break;
	      }
	    getline(infile, line);
	    actors[j] = line;
	    j++;
	  }
       
	// ----- PUTS THE VALUES INTO THE BINARY SEARCH TREE -----
	t.AddNode(seriesName, Sdate, category, url, actors);
      }
  cout<< "here" << endl;

  // ----- FUNCTION TO DISPLAY ALL SHOWS (ONLY TITLES) -----
  GetName(t);

  // ----- FUNCTION TO DISPLAY ALL ACTORS OF A GIVEN SHOW -----
  PrintAActors(t);

  // ----- FUNCTION TO DISPLAY ALL SHOWS OF A GIVEN ACTOR -----
  PrintASA(t);

  // ----- FUNCTION TO DISPLAY ALL SHOWS RELEASED BETWEEN 1972 AND 1982
  // AND ANOTHER DECADE RANGE OF MY CHOICE -----
  PrintTimeFrame(t);

  return 0;
}

// ----- FUNCTION IMPLEMENTATION -----
void GetName(BinarySearchTree t)
{
  // print inorder traversal of the tree
  t.PrintInOrder();

}

void PrintAActors(BinarySearchTree t)
{
  // displays all actors of a given show
  // ----- VARIABLES -----                                                                         
  string sname[4];

  sname[0] = "The Office";
  sname[1] = "The Prisoner";
  sname[2] = "Matlock ";
  sname[3] = "Northern Exposure ";

  // ----- SEARCH THROUGH FOR GIVEN SHOWS -----                                                    
  t.printactor(sname[0]);
  t.printactor(sname[1]);
  t.printactor(sname[2]);
  t.printactor(sname[3]);
}

void PrintASA(BinarySearchTree t)
{
  // displays all shows of a given actor
  // ----- VARIABLES -----
  string names[6];
  
  names[0] = "Majel Barrett";
  names[1] = "Angela Cartwright";
  names[2] = "Mark Harmon";
  names[3] = "Bill Mumy";
  names[4] = "Andy Griffith ";
  names[5] = "John Cullum ";

  // ----- SEARCH THROUGH FOR GIVEN ACTORS -----
  t.printshow(names[0]);
  t.printshow(names[1]);
  t.printshow(names[2]);
  t.printshow(names[3]);
  t.printshow(names[4]);
  t.printshow(names[5]);
}

void PrintTimeFrame(BinarySearchTree t)
{
  // displays all shows released between a decade
  // ----- VARIABLES -----
  int start, start2, end, end2;
  
  start2 = 1972;
  
  // ----- SEARCH THROUGH TREE AND PRINT OUT DATA -----
  t.printtime(start2);
  t.printtime(1960);
}
