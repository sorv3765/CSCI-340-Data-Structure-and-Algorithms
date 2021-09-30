/****************************************************************
           PROGRAM:   Binary Search Tree Class
           AUTHOR:    Shaniel Omar Rivas Verdejo
           LOGON ID:  z1123907
           DUE DATE:  3-30-2017

           PURPOSE: To implement a derived class to represent a binary search tree.
                    Since a binary search tree is also a binary tree, implement
                    your binary search tree class from the base class of binary
                    trees, which you implemented in your previous assignment.

           NOTES:     any relevant information that would be of
                      additional help to someone looking at the program.
****************************************************************/
        #include <iostream>
        #include <iomanip>
        #include <cstdlib>
        #include "assignment5.h"
        #include "assignment6.h"

/****************************************************************

           FUNCTION:   insert (Private)

           ARGUMENTS:  Node* node, int d

           RETURNS:    Nothing

           NOTES:     inserting all the data in each nodes
****************************************************************/

void BST::insert( Node*& node, int d)
{
	if(node==nullptr)
 	{
        	node = new Node(d);                     //create a new node with the input data
      	}
    	else if(d < node->data)                         //if the value of node less than the previous node
           	insert(node->left, d);                  //put into left subtree
     	else
           	insert(node->right, d);                 //put into right subtree
        }

        /****************************************************************

           FUNCTION:   insert (Public)

           ARGUMENTS:  int d

           RETURNS:    Nothing

           NOTES:     calling the private insert function with recursive
        ****************************************************************/
void BST::insert(int d)
{
   	insert(root, d);                                //recursive call
}
        /****************************************************************

           FUNCTION:   Search (Private)

           ARGUMENTS:  Node*& node, int d

           RETURNS:    Boolean

           NOTES:     searches for empty nodes
        ****************************************************************/

bool BST::search( Node*& node, int d )
{

       	if(node==NULL)                 //if its empty
             	return false;
        if ( node->data == d)                   //it found a match
              	return true;
    	else
	{
              	if(node->data<d)                       //if a node value is less than previous node then search the right subtree of that node
                      	return search(node->right, d);
            	else                   //if node value is greater than previous node then search the left subtree of that node
          	         return search(node->left, d);
        }
}

        /****************************************************************

           FUNCTION:   Search (Public)

           ARGUMENTS:  int d

           RETURNS:    Boolean

           NOTES:     calling private using recursive
        ****************************************************************/
bool BST::search( int d )
{
	 return search(root, d);                         //recursive call
}

        /****************************************************************

           FUNCTION:   remove (Private)

           ARGUMENTS:  Node*& node, int d

           RETURNS:    Boolean

           NOTES:     remove nodes
        ****************************************************************/
bool BST::remove( Node*& node, int d )
{
   	if(node==nullptr)
            	return false;
     	if(node->data > d)                              //remove the left subtree node
             	remove(node->left, d);
     	else if(node->data<d)                           //remove the right subtree node
                remove(node->right, d);
   	else
	{
          	if(node->left!=nullptr && node->right!=nullptr) //has two children
             	{
          		Node* pred;
                     	pred=node->left;

             		while(pred->right)
                      	{
                  		pred=pred->right;
                      	}

                      	node->data=pred->data;
                     	remove(node->left, pred->data);
             	}
            	else if(node->left==NULL && node->right==NULL)         //consider itself a leaf
             	{
              		delete node;
                    	node=NULL;
            	}
           	else                                            //node has one child
              	{
                      	Node* tempptr=node;
                      	if(node->left!=NULL)
                            	node=node->left;
                      	else
                             	node=node->right;

                    	tempptr=NULL;
                     	delete tempptr;
            	}
     	}

     	return true;
}

        /****************************************************************

           FUNCTION:   remove (Public)

           ARGUMENTS:  int d

           RETURNS:    Boolean

           NOTES:     calling the remove method by using recursive
        ****************************************************************/
bool BST::remove(int d)
{
	remove(root, d);                        //recursive call
      	return true;
}
        /****************************************************************

           FUNCTION:   sumOfRange (Public)

           ARGUMENTS:  const int lower, const int upper

           RETURNS:    Integer

           NOTES:     calling sumOfRange method by using recursive
        ****************************************************************/
int BST::sumOfRange(const int lower, const int upper)
{
   	return sumOfRange(root, lower, upper);  //recursive call
}

        /****************************************************************

           FUNCTION:   sumOfRange (Private)

           ARGUMENTS:  Node*& node, int lower, int upper

           RETURNS:    Integer

           NOTES:     finding the total nodes within the range
        ****************************************************************/
int BST::sumOfRange( Node*& node,const int lower, const int upper)
{
   	if(node==NULL)
            	return 0;

        if((node->data >=lower) &&( node->data <=upper))        //to see if its in range
                return node->data + sumOfRange(node->right, lower, upper) + sumOfRange(node->left, lower, upper);
        else                                    //it should add remaining nodes within the range
                return sumOfRange(node->left, lower, upper) + sumOfRange(node->right, lower, upper);
}
