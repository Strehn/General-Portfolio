/* Sydney Petrehn
   Lab 12
int pop();
     int dequeue();
     void delete(int a);
     void deleteString(string x);
   Node class
*/

#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class node{
   private:
     string name;
     node *next;
     node *prev;
     int ID;
   public:
     void set(string x, int a, node *n) {next = n; ID = a; name = x;}
     void queue(string x, int a);
     void setnext(node *n){next = n;}
     void setprev(node *n){prev = n;}
     void setdata(int d){ID = d;}
     void setname(string x){name = x;}
     void print();
     string search(int a);
     void insert(string x, int a);
     int pop();
     int dequeue(node* head);
     void del(int a);
     void deleteString(string x);
     int getID(node *n){return ID;}
};

void node::print()
{
   cout << ID << "  " << name << endl;
  
   if(next != NULL)
   next -> print();
}

string node::search(int a)
{
	if(ID == a )
	{
		return name;
	}
	if(next == NULL)
	{
	 	return "";
	}
	return next -> search(a);
}
void node::queue(string x, int a)
{
	if(next == NULL)
	{
		node *newnode = new node();
		newnode -> setname(x);
		newnode -> setdata(a);
		newnode -> setnext(NULL);
		next = newnode;
	}
	else
	{
		next -> queue(x,a);
	}
}
int node::pop()
{
	node *temp = next;
	node *value = temp -> next;
	int deletionID;

	if(value == NULL)
	{
		deletionID = 1;
		delete value;
		next = NULL; // deletes the last node by breaking the link
		return deletionID;
	}
	else
	{
		next -> pop();	
	}
}
int node::dequeue(node* head)
{
		int theID = next -> ID;
		node *temp;
		temp = next;
		next = next -> next;
		delete temp;
		return theID;
		

}
void node::del(int a)
{
	if( next -> ID == a) // gets the right ID
	{
			node *temp;
			temp = next;
			next = next -> next;
			delete temp;
	}
	else
	{
		next -> del(a);
	}
}
void node::deleteString(string x)
{
	if(next -> name == x) // gets the right name
	{
		node *temp;
		temp = next;
		next = next -> next;
		delete temp;
		
	}
	else
	{
		next -> deleteString(x);
	}
}

void node::insert(string x, int a)
{
	if(next == NULL)
	{
		node *newnode = new node();
                newnode -> setname(x);
                newnode -> setdata(a);
                newnode -> setnext(NULL);
                next = newnode;

	}
	else if(next -> ID < a)
	{
		node *newnode = new node();
                newnode -> setname(x);
                newnode -> setdata(a);
                newnode -> setnext(next);
                next = newnode;
        }
        else
        {
                next -> insert(x,a);
        }

}

int main()
{
	int a;
	string x; 
	node *head, *temp;
	head = new node();
	//head -> setnext(NULL);
	head -> queue("TIM",10);
	head -> queue("SALLY",1);	
	head -> insert("ADE",50);
	head -> insert("JIM", 70);
	head -> insert("JEN", 65);
	head -> insert("WYAT", 80);
	head -> insert("HUE", 20);
	head -> print();

	cout <<"through the pop funciton the list now looks like:" << endl;
	// ----- the two other delete funcitons -----
	int popValue = head -> pop();
	cout << " the funciton returned: " << popValue << endl;
	head -> print();

	cout << "through the deque function the list now looks like:" << endl;
	int dequeueValue = head -> dequeue(head);
	cout << "the funciton returned: " << dequeueValue << endl;
	head -> print();

	// ----- using the delete with the ID -----
	cout << "What ID do you want to delete?" << endl;
	cin >> a;
	head -> del(a);
	head -> print(); // prints the function after hte node i sdeleted

	// ---- using the delete with the string -----
	cout << "What string do you want to delete?" << endl;
	cin >> x;
	head -> deleteString(x);
	head -> print(); // prints the list after the node has been deleted

}

