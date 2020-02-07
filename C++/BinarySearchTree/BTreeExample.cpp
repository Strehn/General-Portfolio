/*  btree.cpp  
 *
 *  Binary Search Tree Implementation with Deletion.
 */


#include <iostream>

#include "btree.h"

using namespace std;

//#define DEBUG_DELETE


//  ~BinarySearchTree() 
//    Delete BST object

BinarySearchTree::~BinarySearchTree()
{
  DeleteBST( rootPtr );
}


// IsLeaf()                                       
//   Test if a node is a leaf

bool  BinarySearchTree::IsLeaf( TreePtr treePtr)
{
  return ((treePtr->leftPtr  == NULL) &&
	  (treePtr->rightPtr == NULL)    );
}


// DeleteBST()                                       
//   Delete an entire BST.  All memory is released
//   using a "PostOrder" traversal method.

void BinarySearchTree::DeleteBST( TreePtr& treePtr )
{
  if( treePtr != NULL )
    {
      DeleteBST( treePtr->leftPtr );
      DeleteBST( treePtr->rightPtr );
      
      delete  treePtr;
      treePtr = NULL;
    }
}


// DeleteNode()                                       
//   Delete a single node.

void BinarySearchTree::DeleteNode( DATA_TYPE val )
{
#ifdef  DEBUG_DELETE
  cout << "DeleteNode::Deleting:  " << val << endl;
#endif

  DeleteNode( rootPtr, val );
}


void BinarySearchTree::DeleteNode(
				  TreePtr& treePtr, DATA_TYPE val )
{
#ifdef  DEBUG_DELETE
  cout << "DeleteNode::val:  " << val << endl;
#endif

  if( treePtr == NULL )
    {
      return;
    }
  else if( val == treePtr->data )
    {
      DeleteNodeItem( treePtr );
      //  was rootPtr---unexpected results
    }
  else if( val < treePtr->data )
    {
#ifdef  DEBUG_DELETE
      cout << "DeleteNode::treePtr->data:  " << treePtr->data << endl;
      cout << "     looking left" << endl;
#endif
      
      DeleteNode( treePtr->leftPtr, val );
    }
  else
    {
#ifdef  DEBUG_DELETE
      cout << "DeleteNode::treePtr->data:  " << treePtr->data << endl;
      cout << "     looking right" << endl;
#endif
      
      DeleteNode( treePtr->rightPtr, val );
    }
}


void BinarySearchTree::DeleteNodeItem(
				      TreePtr& treePtr )
{
  TreePtr delPtr;
    
  if( IsLeaf(treePtr) )
    {
#ifdef  DEBUG_DELETE
      cout << "DeleteNodeItem::found leaf node" << endl;
#endif
       
      delete treePtr;
      treePtr = NULL;
    }
  else if( treePtr->leftPtr == NULL )
    {
#ifdef  DEBUG_DELETE
      cout << "DeleteNodeItem::left is NULL" << endl;
#endif
      
      delPtr = treePtr;
      treePtr = treePtr->rightPtr;
      delPtr->rightPtr = NULL;
      delete delPtr;
    }
  else if( treePtr->rightPtr == NULL )
    {
#ifdef  DEBUG_DELETE
      cout << "DeleteNodeItem::right is NULL" << endl;
#endif
      
      delPtr = treePtr;
      treePtr = treePtr->leftPtr;
      delPtr->leftPtr = NULL;
      delete delPtr;
    }
  else
    {
#ifdef  DEBUG_DELETE
      cout << "DeleteNodeItem::has two children" << endl;
      cout << "    calling ProcessLeftMost()" << endl;
#endif
      
      DATA_TYPE  replacementItem;
        
      ProcessLeftMost( treePtr->rightPtr, replacementItem );
      treePtr->data = replacementItem;
#ifdef  DEBUG_DELETE       
      cout << "DeleteNodeItem::replacementItem:  " << replacementItem << endl;
#endif
    }
}


void BinarySearchTree::ProcessLeftMost(
				       TreePtr& treePtr, DATA_TYPE& theItem )
{
  if( treePtr->leftPtr != NULL )
    ProcessLeftMost( treePtr->leftPtr, theItem );
  else
    {
      theItem = treePtr->data;
      TreePtr delPtr = treePtr;
      treePtr = treePtr->rightPtr;
      delPtr->rightPtr = NULL;
      delete  delPtr;  
    }  
}


// AddNode()           
//   Add (insert) new item into the BST, whose 
//   root node is pointed to by "rootPtr".  If 
//   the data already exists, it is ignored.
void BinarySearchTree::AddNode(string Name, int d, string cate, string ur, string act[])
{
  TreePtr newPtr;

  newPtr = new BSTreeNode;

  // Add new data in the new node's data field
      newPtr->seriesName = Name;
      newPtr->date = d;
   for(int j = 0; j < 128; j++)
      {
      newPtr->actors[j] = act[j];
      }
  newPtr-> category = cate;
  newPtr-> url = ur;
 
  newPtr -> leftPtr = NULL;
  newPtr->rightPtr = NULL;
   
  //  If the BST is empty, insert the new data in root
  if( rootPtr == NULL )
    {
      rootPtr = newPtr;
    }
  else   //  Look for the insertion location
    {
      TreePtr   treePtr = rootPtr;
      TreePtr   targetNodePtr;
      
      while( treePtr != NULL )
	{
	  targetNodePtr = treePtr;
	  if( Name == treePtr->seriesName ) 
	    // Found same data; ignore it. 
	    return;
	  else if( Name < treePtr->seriesName ) 
	    // Search left subtree for insertion location
	    treePtr = treePtr->leftPtr; 
	  else   //  newData > treePtr->data 
	    // Search right subtree for insertion location
	    treePtr = treePtr->rightPtr; 
	}

      //  "targetNodePtr" is the pointer to the
      //  parent of the new node.  Decide where 
      //  it will be inserted.
      if( Name < targetNodePtr->seriesName )
	targetNodePtr->leftPtr = newPtr;
      else  // insert it as its right child
	targetNodePtr->rightPtr = newPtr;
    }
}


// SearchNodeInBST()            
//   Find a given node by "key" in BST.  If successful,
//   it returns the pointer that points to the node
//   with "key"; otherwise, it returns NULL.  It uses
//   preorder traversal.

BinarySearchTree::TreePtr 
BinarySearchTree::SearchNodeInBST(
				  TreePtr treePtr, DATA_TYPE key )
{
  if( treePtr != NULL )
    {
      if( key == treePtr->data )
	return  treePtr;
      else if( key < treePtr->data ) 
	// Search for "key" in left subtree
	return SearchNodeInBST( treePtr->leftPtr, key );
      else   // (key > tree_ptr->data) 
	// Search for "key" in right subtree
	return SearchNodeInBST( treePtr->rightPtr, key );
    } 
  else
    {
      return NULL;
    } 
} 

void BinarySearchTree::SearchNode( DATA_TYPE searchKey )
{
  TreePtr srchPtr = NULL;

  srchPtr = SearchNodeInBST( rootPtr, searchKey );
  if( srchPtr != NULL )
    {
      cout << "\n Node: " << srchPtr->data << " was found in the BST" << endl;
    }
  else
    {
      cout << "\n Node: " << searchKey << " was not found" << endl;
    }
}


// PrintTree()
//   Print a BST tree uses InOrder traversal by default.

void BinarySearchTree::PrintTree() 
{ 
  PrintBST_InOrder( rootPtr );
}


// PrintInOrder()
//   Print BST using InOrder traversal

void BinarySearchTree::PrintInOrder()
{
  PrintBST_InOrder( rootPtr );
}


void
BinarySearchTree::PrintBST_InOrder(
				   TreePtr treePtr )
{
  if( treePtr != NULL)
    {
      // Print left BST subtree
      PrintBST_InOrder( treePtr->leftPtr );
      // Print Root node data
      cout << treePtr->data << endl;
      // Print right BST subtree
      PrintBST_InOrder( treePtr->rightPtr );
    }
} 


// PrintPreOrder() 
//   Print BST using PreOrder traversal

void BinarySearchTree::PrintPreOrder()
{
  PrintBST_PreOrder( rootPtr );
}


void
BinarySearchTree::PrintBST_PreOrder( 
				    TreePtr treePtr )
{
  if( treePtr != NULL )
    {
      // Print node data
      cout << treePtr->data << endl;
      // Print left subtree
      PrintBST_PreOrder( treePtr->leftPtr );
      // Print right subtree
      PrintBST_PreOrder( treePtr->rightPtr );
    }
}


// PrintPostOrder()
//   Print BST using PostOrder traversal

void BinarySearchTree::PrintPostOrder()
{
  PrintBST_PostOrder( rootPtr );
}


void
BinarySearchTree::PrintBST_PostOrder(
				     TreePtr treePtr )
{
  if( treePtr != NULL )
    {
      // Print left BST subtree
      PrintBST_PostOrder( treePtr->leftPtr );
      // Print right BST subtree
      PrintBST_PostOrder( treePtr->rightPtr );
      // Print node data
      cout << treePtr->data << endl;
    }
}

// PrintBackwardPostOrder()
//   Print BST using PostOrder traversal

void BinarySearchTree::PrintBackwardPostOrder()
{  
  PrintBST_BackwardPostOrder( rootPtr, 0 );
}


void
BinarySearchTree::PrintBST_BackwardPostOrder(
					     TreePtr treePtr, int depth )
{
  const int INDENT = 4;
   
  if( treePtr != NULL )
    {
      // Print right BST subtree
      PrintBST_BackwardPostOrder( treePtr->rightPtr, depth+1 );
      // Print data in root node
      //cout << setw(INDENT*depth) << " ";
      for( int i = 0 ; i < INDENT*depth ; i++ )
	cout << " ";
      cout << treePtr->data << endl;
      // Print left BST subtree
      PrintBST_BackwardPostOrder( treePtr->leftPtr, depth+1 ); 
    }
}

void BinarySearchTree::printactor(string name)
{
  TreePtr treePtr = rootPtr;

  cout<< "Actors under the movie: " << name << endl; 
  if( treePtr!=NULL)
    {
      if( name == treePtr-> seriesName)
	{
	  for(int j = 0; j < 15; j++)
	    {
	      cout << treePtr-> actors[j];
	    }
	}
      else if(name < treePtr-> seriesName)
	{
	  treePtr = treePtr-> leftPtr;
	}
      else
	{
	  treePtr = treePtr-> rightPtr;
	}
    }

}

void BinarySearchTree::printshow(string name)
{
  TreePtr treePtr = rootPtr;

  cout<< "Movies under the actor: " << name << endl;
  if( treePtr!=NULL)
    {
      for(int j = 0; j < 15; j++)
	{
	  while(treePtr!=NULL)
	    {// loops through each time for the amount of actors to check all of them
	  if(treePtr-> actors[j] == name)
	    {
	      cout<< treePtr-> seriesName;
	    }
	      treePtr = treePtr-> leftPtr;
	    }
	}
      treePtr = rootPtr-> rightPtr;
      for(int j = 0; j< 15; j++)
	{
	  while(treePtr!=NULL)
	    {
	      if(treePtr-> actors[j] == name)
		{
		  cout<< treePtr-> seriesName;
		}
		treePtr = treePtr-> rightPtr;
	    }
	}
    }
}

void BinarySearchTree::printtime(int x)
{
  TreePtr treePtr = rootPtr;
  int start = x;
  int end  = x+10;
  cout << "movies in the decade:" << x << endl;

  if(treePtr != NULL)
    {
      if((treePtr -> date < end) && (treePtr -> date > start))
	{
	  cout<< treePtr -> seriesName;
	}
      treePtr = treePtr-> leftPtr;
    }
  treePtr = rootPtr -> rightPtr;
  if(treePtr!=NULL)
    {
      if((treePtr -> date < end) && (treePtr -> date > start))
        {
          cout<< treePtr -> seriesName;
        }
      treePtr = treePtr-> rightPtr;
    }
}
