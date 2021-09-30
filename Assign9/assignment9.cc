/****************************************************************
   PROGRAM:   Simple Graph
   AUTHOR:    Shaniel Omar Rivas Verdejo
   LOGON ID:  z1123907
   DUE DATE:  4-27-2017

   PURPOSE:  To write a C++ program to implement several graph
	     algorithms on simple graphs. These graphs are
	     implemented with adjacency list representation.

   NOTES:     any relevant information that would be of
              additional help to someone looking at the program.
****************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "assignment9.h"

using namespace std;
//------- Global Variables-----------
vector<bool> visited;				//visited order of all vertices
vector<int> output;				//current order of traversing
vector<pair<int,int>> edges;			//record all the paths of edges
//-----------------------------------


/****************************************************************

   FUNCTION:	 Get Size

   ARGUMENTS:  	None

   RETURNS:    	Integer

   NOTES:     	get the size and return it.
****************************************************************/
int graph::get_size() const
{
	return size;
}

/****************************************************************

   FUNCTION:   	Constructor

   ARGUMENTS:  constant char* filename

   RETURNS:    nothing

   NOTES:     it reads off the file to get the characters or integers.
****************************************************************/
graph::graph(const char* filename)
{
	// read from file, whatever is the first character it's size
	ifstream ifs(filename);
	ifs >> size;
	labels.resize(size);
	adj_list.resize(size);

	for(int i=0; i<size; ++i)		//then next characters are labels
	{
		ifs >> labels[i];		//putting the labels
	}

	for(int i=0; i<size ; ++i)	// next rows & columns are integers
	{
		char temp;
	ifs >> temp;

		for(int j=0; j<size ; j++)
		{

			int x;
			ifs >> x;
			if(x==1)			//it try find edges betweein vertices
			{
				adj_list[i].push_back(j);
			}
		}
	}
	// then next characters until size are all labels
	ifs.close();
}

graph::~graph()
{
	adj_list.clear();				//delet the memory of  adj-list

}

/****************************************************************

   FUNCTION:   	Depth_First

   ARGUMENTS:  	Integer v

   RETURNS:    	Nothing

   NOTES:     	Is used to traverse a graph in the depth-first traversal/search Algorithm
****************************************************************/
void graph::depth_first(int v)
{
	if(!visited[v])					//if not visited
		output.push_back(v);			//put it in the output

	visited[v]=true;

	list<int>::iterator it;

	for(it=adj_list[v].begin(); it!=adj_list[v].end(); it++ )
	{
		if(!visited[*it])
		{
			edges.push_back(make_pair(v, *it));	//putting pair of two vertices
			depth_first(*it);			//recursive call it
		}
	}

}

/****************************************************************

   FUNCTION:   	Traverse

   ARGUMENTS:  	None

   RETURNS:    	Nothing

   NOTES:     	Is to use to traverse a graph with depth_first method
****************************************************************/
void graph::traverse()
{
	visited.resize(size);
	int i;

	//for each vertex that is not visited, do a depth first traversal
	for(i=0; i<size; i++)
	{
		if(!visited[i])
			depth_first(i);			//use depth_first method again
	}

	/************* Print out the graph in traversal order  **********************/
	cout << "------- traverse of graph ------" << endl;
	cout << endl;

	vector<int>::iterator out;

	for(out=output.begin(); out!=output.end(); out++)
	{
		cout <<labels[ *out] << " ";			//all the labels listed across
	}

	cout << endl;

	for(unsigned int i=0;i<edges.size();i++)
	{
		cout <<"(" << labels[edges[i].first] << "," << labels[ edges[i].second]<< ") " ;	//all the paths(edges) between labels(vertices)
	}

	cout << endl << endl;
	cout << " --------- end of traverse -------" << endl << endl;


}

/****************************************************************

   FUNCTION:   	Print

   ARGUMENTS:  	None

   RETURNS:    Nothing

   NOTES:     Print out the graph and the number of vertices
****************************************************************/
void graph::print()const
{
	cout << endl;
	cout << "Number of vertices in the graph: " << ": " << size;
	cout << endl << endl;
	cout << "-------- graph  --------" << endl << endl;

	list<int>::const_iterator it;
	int i;

	for(i=0; i<size; i++ )
	{
		cout << labels[i] << ": ";		//all the vertices

		for(it = adj_list[i].begin(); it!=adj_list[i].end(); it++)
		{
			cout << labels[*it] << ", ";	//all the paths for each vertices
		}

		cout << endl;
	}
	cout << endl;
	cout << "------- end of graph -------" << endl;
	cout << endl;
}


#define ASSIGNMENT9_TEST
#ifdef 	ASSIGNMENT9_TEST

int main(int argc, char** argv)
{
    	if ( argc < 2 )
	{
        	cerr << "args: input-file-name\n";
        	return 1;
    	}

    	graph g(argv[1]);

	g.print();

    	g.traverse();

    	return 0;
}

#endif
