#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

vector<bool> visited;
vector<int> output;
vector<pair<int,int> > edges;

class graph
{
    private:
        int size;
        std::vector< list<int> > adj_list;
        std::vector< char > labels;
        void depth_first( int );
    public:
        graph( const char* filename );
        ~graph();
        int get_size() const;
        void traverse( ) ;
        void print ( ) const;
};

int graph::get_size() const
{
	return size;
}

graph::graph(const char* filename)
{
	// read from file, whatever is the first character it's size
	ifstream ifs(filename);
	size=ifs.get();
//	ifs.get();			// ignore the newline after size
	char c;
	for(int i=0; i<size; ++i)		//then next characters are labels
	{
		c=ifs.get();
		if(isalpha(c))
		{
			labels.push_back(c);
			++i;
		}
	}

	for(int i=0; i<size ; ++i)	// next rows & columns are integers
	{
		list<int> mylist;
		c=ifs.get();			//declare c
		for(int j=0; j<size ; j++)
		{
			c=ifs.get();
			if(c==1)
			{
				adj_list[i].push_back(j);
			}
		}
	}
	// then next characters until size are lables
	ifs.close();
}

void graph::depth_first(int v)
{
	if(!visited[v])				//if not visited
	{		
		output.push_back(v);	//put it in the output
		visited[v]=true;

		list<int>::iterator it;

		for(it=adj_list[v].begin(); it!=adj_list[v].end(); it++ )
		{
			if(!visited[*it])
			{
				edges.push_back(make_pair(v, *it));				//putting pair of two vertices
				depth_first(*it);
			}
		}
	}
}

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

	
	cout << "------- traverse of graph ------" << endl;
	
	vector<int>::iterator out;
	for(out=output.begin(); out!=output.end(); out++)
	{
		cout << output[i] << " ";
	}
	
	cout << endl;

	vector<int>::iterator edg;

	for(edg=output.begin(); edg!=output.end(); edg++)
	{
		cout << edges << ", ";
	}

	cout <<" --------- end of traverse -------" << endl;

	
}

void graph::print()const
{
	cout << "Number of vertices in the graph: " << ": " << size;
	cout << endl;
	cout << "-------- graph  --------" << endl;
	list<int>::const_iterator it;

	for(int i=0; i<size; i++ )
	{
		cout << labels[i] << ": ";
	
		for(it = adj_list[i].begin(); it!=adj_list[i].end(); it++)
		{
			cout << labels[*it] << ", ";
		}
	
		cout << endl;
	}
	
	cout << "------- end of graph -------" << endl;
	cout << endl;
	}

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

//    	g.traverse();

    	return 0;
}

#endif
