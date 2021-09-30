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

#define BINTREE_MAIN
#ifdef BINTREE_MAIN

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
void binTree::insert( Node*& root, int x)
{
	if(root==nullptr)			//if there nothing then the first value is the root
		root=new Node(x);
	else
	{
		if(height(root->left) <= height(root->right))		// height of left subtree less than equal to height of right subtree then insert new data into the left subtree
			insert(root->left, x);
		else
			insert(root->right, x);				//insert new data into the right subtree
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
int binTree::height( Node* root) const
{
	if(root==nullptr)
		return -1;

	int hr=height(root->right);		//height of right
	int hl=height(root->left);		//height of left

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
unsigned binTree::size( Node* root) const
{
	if(root==nullptr)
		return 0;

	return size(root->left) + 1 + size(root->right);
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
void binTree::inorder( Node* root, void(*p)(int) )
{
	if(root!=nullptr)
	{
		inorder(root->left,p);			//start with the left subtree
		p(root->data);				//then the node
		inorder(root->right,p);			//then the right subtree
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
void binTree::preorder( Node* root, void(*p)(int) )
{
	if(root!=0)
	{
		p(root->data);				//start with node
		preorder(root->left, p);		//then the left subtree
		preorder(root->right, p);		//then the right subtree
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
	postorder(root, p);
}

/****************************************************************

   FUNCTION:   Postorder (Private)

   ARGUMENTS:  Node* root, void *p, and integer

   RETURNS:    Nothing

   NOTES:     Creates a postorder process of the tree
****************************************************************/
void binTree::postorder( Node* root, void(*p)(int) )
{
	if(root!=0)
	{
		postorder(root->left, p);			//starts with left subtree
		postorder(root->right, p);			//then right subtree
		p(root->data);					//then to the node
	}
}

int main()
{
    vector<int> v(MAX_SIZE);
    for (int i=1; i<MAX_SIZE; i++)
        v[i] = i;
    random_shuffle( v.begin(), v.end() );

    binTree bt;
    vector<int>::iterator it;
    for (it=v.begin(); it!=v.end(); it++)
        bt.insert( *it );

    cout << "Height: " << bt.height() << endl;
    cout << "Size: " << bt.size() << endl;
    cout << "In order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.inorder( display );
    cout << "\n\nPre order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.preorder( display );
    cout << "\n\nPost order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.postorder( display );

    cout << endl;

return 0;
}
#endif
