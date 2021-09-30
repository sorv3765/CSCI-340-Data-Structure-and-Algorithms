/****************************************************************
   PROGRAM:   Binary Search Tree Class
   AUTHOR:    Shaniel Omar Rivas Verdejo
   LOGON ID:  z1123907
   DUE DATE:  3-10-2017

   PURPOSE:  this computer assignment, you are to write a C++ program
	     to implement classes to represent a binary tree
	     (of integers)

   NOTES:     any relevant information that would be of
              additional help to someone looking at the program.
****************************************************************/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "assignment5.h"

using namespace std;

const int MAX_SIZE = 40;
const int MAX_COUNT = 40;
const int WIDTH = 5;
const int ROW_SIZE = 8;

int mcount = 0;
int rcount = 0;

void display(int d)
{
    if ( mcount < MAX_COUNT ) 
	{
        	cout << setw(WIDTH) << d;
        	mcount++;
        	rcount++;

		if ( rcount == ROW_SIZE )
		{
            		cout << endl;
            		rcount = 0;
        	}
    	}
}

/*
#define BINTREE_MAIN
#ifdef BINTREE_MAIN
*/

/****************************************************************

   FUNCTION:   Class binTree

   ARGUMENTS:  Nothing

   RETURNS:    

   NOTES:     Constructor
****************************************************************/
binTree::binTree()
{
	root = nullptr;					//the root is the start of the tree declaring it
}

/****************************************************************

   FUNCTION:   Insert

   ARGUMENTS:  int d

   RETURNS:    Nothing

   NOTES:     calling the insert function from private
****************************************************************/
void binTree::insert(int d)
{
	insert(root,d);
}

/****************************************************************

   FUNCTION:   Insert (Private version)

   ARGUMENTS:  Node*& root, int x

   RETURNS:    Nothing

   NOTES:     Putting data in the tree
****************************************************************/
void binTree::insert( Node*& node, int x)
{
	if(node==nullptr)			//if there nothing then the first value is the root
		node=new Node(x);
	else
	{
		if(height(node->left) <= height(node->right))		// height of left subtree less than equal to height of right subtree then insert new data into the left subtree
			insert(node->left, x);
		else
			insert(node->right, x);				//insert new data into the right subtree
	}
}

/****************************************************************

   FUNCTION:   Height

   ARGUMENTS:  Nothing

   RETURNS:    Integer

   NOTES:      Calling the height function from private
****************************************************************/
int binTree::height() const
{
	return height(root);
}

/****************************************************************

   FUNCTION:   Height (Private Version)

   ARGUMENTS:  Node root

   RETURNS:    Integer

   NOTES:     Counting the height of the tree
****************************************************************/
int binTree::height( Node* node) const
{
	if(node==nullptr)
		return -1;

	int hr=height(node->right);		//height of right
	int hl=height(node->left);		//height of left

	if(hr > hl)				//if height of right greater than height of left
		return hr+1;
	else
		return hl+1;
}

/****************************************************************

   FUNCTION:   Size

   ARGUMENTS:  Nothing

   RETURNS:    Unsigned

   NOTES:     Calling the size function from Private
****************************************************************/
unsigned binTree::size() const
{
	return size(root);
}

/****************************************************************

   FUNCTION:   Size (Private)

   ARGUMENTS:  Node* root

   RETURNS:    Unsigned

   NOTES:     Counting the size of the Node on both left and right
****************************************************************/
unsigned binTree::size( Node* node) const
{
	if(node==nullptr)
		return 0;

	return size(node->left) + 1 + size(node->right);
}

/****************************************************************

   FUNCTION:   Inorder

   ARGUMENTS:  Void *p and  integer

   RETURNS:    Nothing

   NOTES:     this calling the inorder function from Private
****************************************************************/
void binTree::inorder(void(*p)(int))
{
	inorder(root, p);
}

/****************************************************************

   FUNCTION:   Inorder (Private)

   ARGUMENTS:  Node* root, void *p, and integer

   RETURNS:    Nothing

   NOTES:     Creates the inorder process of the tree
****************************************************************/
void binTree::inorder( Node* node, void(*p)(int) )
{
	if(node!=NULL)
	{
		inorder(node->left,p);			//start with the left subtree
		p(node->data);				//then the node
		inorder(node->right,p);			//then the right subtree
	}

}

/****************************************************************

   FUNCTION:   Preorder

   ARGUMENTS:  void *p and integer

   RETURNS:    Nothing

   NOTES:     Calling the preoder function form private
****************************************************************/
void binTree::preorder( void(*p)(int) )
{
	preorder(root, p);
}

/****************************************************************

   FUNCTION:   Preorder (Private)

   ARGUMENTS:  Node * root, void *p, and integer

   RETURNS:    Nothing

   NOTES:     Creates the preorder process of the tree
****************************************************************/
void binTree::preorder( Node* node, void(*p)(int) )
{
	if(node!=NULL)
	{
		p(node->data);				//start with node
		preorder(node->left, p);		//then the left subtree
		preorder(node->right, p);		//then the right subtree
	}
}

/****************************************************************

   FUNCTION:   Postorder

   ARGUMENTS:  void *p and integer

   RETURNS:    Nothing

   NOTES:     Calling the postorder function from private
****************************************************************/
void binTree::postorder( void(*p)(int) )
{
if(root!=NULL)
	postorder(root, p);
}

/****************************************************************

   FUNCTION:   Postorder (Private)

   ARGUMENTS:  Node* root, void *p, and integer

   RETURNS:    Nothing

   NOTES:     Creates a postorder process of the tree
****************************************************************/
void binTree::postorder( Node* node, void(*p)(int) )
{
	if(node!=NULL)
	{
		postorder(node->left, p);			//starts with left subtree
		postorder(node->right, p);			//then right subtree
		p(node->data);					//then to the node
	}
}
//#endif
