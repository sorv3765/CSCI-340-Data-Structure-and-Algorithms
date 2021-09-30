/****************************************************************
   PROGRAM:   Heap and Heapsort
   AUTHOR:    Shaniel Omar Rivas Verdejo
   LOGON ID:  z1123907
   DUE DATE:  4-7-2017

   PURPOSE:  to write a C++ program to sort numbers using the heapsort
	     technique. Your program first builds a heap structure for
	     the numbers. Then, it retrieves these numbers from the heap
	     in a certain order and prints them out on stdout.


   NOTES:     any relevant information that would be of
              additional help to someone looking at the program.
****************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

//prototype
void build_heap(vector <int>&, int, bool (*)(int,int));
void heapify(vector <int>&, int,int, bool (*)(int,int));
bool less_than( int, int);
bool greater_than(int, int);
void heap_sort(vector <int>&, int, bool (*)(int,int));
int extract_heap(vector <int>&, int&, bool (*)(int,int));
void print_vector(vector <int>&, int, int);

/****************************************************************

   FUNCTION:   Build Heap

   ARGUMENTS:  vector integer , int heapsize, bool compar function

   RETURNS:    Nothing

   NOTES:     it builds a heap tree by inserting the nodes
****************************************************************/
void build_heap ( vector < int >& v, int heap_size, bool (*compar)(int, int) )
{

	for(int i=(heap_size/2); i>0; i--)						//start at the the root/parent then work the way down
	{
		heapify(v, heap_size, i, compar);					//recursive of heapify
	}
}

/****************************************************************

   FUNCTION:   Heapify

   ARGUMENTS:  vector integer v, int heapsize, int r, bool compar function

   RETURNS:    Nothing

   NOTES:     A tree at the root position r, assuming r’s two sub-trees are already heaps.
****************************************************************/
void heapify( vector < int >& v, int heap_size, int r, bool (*compar)(int, int) )
{
	int L= 2*r;									//represent the left
	int R=2*r+1;									//represent the right
	int largest=r;									//whichever the largest is the r

	if((L<=heap_size) && compar(v[L],v[r]))						//compare with is the largest value
		largest=L;								//left is the largest
	else
		largest=r;								//else the root/parent is the largest

	if(R<=(heap_size) && compar(v[R],v[largest]))					//compare with is the largest value
		largest=R;								//right is the largest

	if(largest!=r)									//if the rootparent isn't the largest
	{
		swap(v[r],v[largest]);							//replace the largest with the root/parent
		heapify(v, heap_size, largest, compar);					//recursive of the heapify
	}
}

/****************************************************************

   FUNCTION:  Less Than

   ARGUMENTS:  integer e1, integer e2

   RETURNS:    Boolean

   NOTES:     To compare two elements to see which is less than the other
****************************************************************/
bool less_than ( int e1, int e2 )
{
	if(e1<e2)									//if e1 is less than e2
		return true;
	else										//else e2 is less than e1
		return false;
}

/****************************************************************

   FUNCTION:  Greater Than

   ARGUMENTS:  integer e1, integer e2

   RETURNS:    Boolean

   NOTES:     To compare two elements to see which is larger than the other
****************************************************************/
bool greater_than ( int e1, int e2 )
{
	if(e1>e2)									//if e1 is greater than e2
		return true;
	else										//else e2 is greater than e1
		return false;
}

/****************************************************************

   FUNCTION:   Heap Sort

   ARGUMENTS:  vector integer v, int heapsize, bool compar function

   RETURNS:    Nothing

   NOTES:     Sorting the heap tree.
****************************************************************/
void heap_sort ( vector < int >& v, int heap_size, bool (*compar)(int, int) )
{
	build_heap(v, heap_size, compar);						//call the build heap method for building the heap

	for(int i=heap_size; i>0;)							//each value being sorted
	{
		extract_heap(v,i,compar);						//calling the extract heap method
	}

	reverse(v.begin()+1, v.end());							//reverse the order
}

/****************************************************************

   FUNCTION:   Extract Heap

   ARGUMENTS:  vector integer v, int heapsize, bool compar function

   RETURNS:    Integer

   NOTES:      extracts the root of the heap recorded in v.
****************************************************************/
int extract_heap ( vector < int >& v, int& heap_size, bool (*compar)(int, int) )
{
	int temp;									//creating a temp
	temp=v[1];									//the root position of the tree
	v[1]=v[heap_size];								//the position of the node to  move to the root
	v[heap_size]=temp;								//the root node ubble down
	heap_size--;									//the reduce the heap size
	heapify(v,heap_size,1,compar);							//calling the heapify method
	return temp;									//return the temp value
}

/****************************************************************

   FUNCTION:   Print Vector

   ARGUMENTS:  vector integer v, int pos, int size

   RETURNS:    Nothing

   NOTES:      print all the values in the order its being set
****************************************************************/
void print_vector ( vector < int >& v, int pos, int size )
{
	int cnt=0;
	for(int i=pos;i<=size; i++)						//for every position in the vector
	{
		cout << setw(5) << v[i];					//5 spaces between the value
		cnt++;								//count how many values
		if(cnt%8==0) cout<<endl;					//when it reaches 8 values start a new line
	}
	cout<<endl;
}


const int HEAP_SIZE = 50;
int main(int argc, char** argv)
{
    // ------- creating input vector --------------
    vector<int> v;
    v.push_back(-1000000);    // first element is fake
    for (int i=1; i<=HEAP_SIZE; i++)
        v.push_back( i );
    random_shuffle( v.begin()+1, v.begin()+HEAP_SIZE+1 );

    cout << "\nCurrent input numbers: " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing min heap ------------------
    cout << "\nBuilding a min heap..." << endl;
    build_heap(v, HEAP_SIZE, less_than);
    cout << "Min heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, less_than);
    cout << "Heap sort result (in ascending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing max heap ------------------
    cout << "\nBuilding a max heap..." << endl;
    build_heap(v, HEAP_SIZE, greater_than);
    cout << "Max heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, greater_than);
    cout << "Heap sort result (in descending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    return 0;
}
