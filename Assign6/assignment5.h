#ifndef ASSIGNMENT5
#define ASSIGNMENT5


using namespace std;

class binTree;
class BST;

class Node
{
        Node(int d)
        {
                data=d;
                left=nullptr;
                right=nullptr;
        }

        friend class binTree;
	friend class BST;

        private:
                int data;
                Node* left;
                Node* right;

};

class binTree
{
    public:
        binTree();				// default constructor
        virtual void insert( int );		// inserts a node in tree
        int height() const;			// returns height of tree
        unsigned size() const;			// return size of tree
        void inorder( void(*)(int) );		// inorder traversal of tree
        void preorder( void(*)(int) );		// preorder traversal
        void postorder( void(*)(int) );		// postorder traversal

    protected:
        Node* root;				//root of tree

    private:
        void insert( Node*&, int );		//private version of insert()
        int height( Node* ) const;		//private version of height()
        unsigned size( Node* ) const;		//private version of size()
	void inorder( Node*, void(*)(int) );	//priveate version of inorder()
	void preorder( Node*, void(*)(int) );	//private version of preorder()
	void postorder( Node*, void(*)(int) );	//private version of postorder()
};

#endif
