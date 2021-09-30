/****************************************************************
   PROGRAM:   Search Algoithm
   AUTHOR:    Shaniel Omar Rivas Verdejo
   LOGON ID:  z1123907
   DUE DATE:  1-31-2017

   PURPOSE:  To write and implement a C++ program to implement two
	      search algorithms (linear search and binary search) on
              randomly generated integers stored in vectors.

   NOTES:     any relevant information that would be of
              additional help to someone looking at the program.
****************************************************************/

#include <iostream>			//input and output
#include <algorithm>			//sorting
#include <vector>			//vector
#include <iomanip>			//organzie

const int DATA_RANGE = 100;
const int DATA_SIZE = 100;
const int DATA_SEED = 7;
const int SEARCH_SEED = 9;

using namespace std;

/****************************************************************

   FUNCTION:   Linear Search

   ARGUMENTS:  input vector named inputVec, x, comparisons

   RETURNS:    Boolean

   NOTES:      simply starts searching for x from the beginning of
               vector to the end, but it stops searching when there
               is a match. If the search is successful, it returns
               true; otherwise, it returns false. You need to save
               the number of comparisons (between x and a vector
               element) conducted in this search in the parameter comparisons.
****************************************************************/

bool linear_search(const vector<int>& inputVec, const int x, int& comparisons)
{
	vector<int>::const_iterator it;				//declare a public member called it

	comparisons=0;						//set comparison to equal to 0

	for(it=inputVec.begin(); it!=inputVec.end(); ++it)	//running a loop from beginning to end
	{
		comparisons++;					//count it for comparison later

		if(x==*it)					// to see if they found a match in the search
	 		return true;
	}

	return false;
}

/****************************************************************

   FUNCTION:   Binary Search

   ARGUMENTS:  constant vector inputVec, const int x, int comparison

   RETURNS:    Boolean

   NOTES:      where x is the searched item in vector inputVec. If
               the search is successful, it returns true; otherwise,
               it returns false. The same as above, you need to save
               the number of comparisons in the parameter comparisons.
****************************************************************/
bool binary_search(const vector<int>& inputVec, const int x, int& comparisons)
{
	vector<int>::const_iterator bs;			//declare a public member called bs

	int low=0;					//initliaze it to 0
	int middle=0;					//initiliaze it to 0
	int high=inputVec.size()-1;			//intialize it to the size of the vector

	comparisons=0;					//set it to 0

	while(low <= high)				//run a loop or a search
	{
		middle=(high+low)/2;			//search to see if value match the value in the middle
		comparisons++;				//count it if it match

		if(x==inputVec[middle])			//check to see if it match
			return true;
		else if(x<inputVec[middle])		//if not match then will search the first half
			high=middle-1;
		else					//if not match then it will search the one next to it.
			low=middle+1;
	}

	return false;					//otherwise its not been found.
}

/****************************************************************

   FUNCTION:   Print

   ARGUMENTS:  constant vector called vec

   RETURNS:    Return Nothing

   NOTES:      Print out what matches and have been found.
****************************************************************/
void print_vec( const vector<int>& vec )
{
	vector<int>::const_iterator result;			//declare a public member called result

	int count=0;						//set it to 0

	for(result=vec.begin(); result!=vec.end(); result++)	//runs a loop to see what the result are and print them out
	{
		cout << setw(6) <<*result;			//puts 6 spaces between each result
		count++;

		if(count%10==0)					//make a new line after every 10 results
		cout << endl;
	}
}

/****************************************************************

   FUNCTION:   Average Comparison

   ARGUMENTS:  constant vectorof inputVec, searchVec, bool search

   RETURNS:    Return Nothing

   NOTES:      It compares the two searches and average them out.
****************************************************************/
void average_comparisons(const vector<int>& inputVec, const vector<int>& searchVec, bool (*search)(const vector<int>&, const int, int&) ) {
    int i, comparison=0, sum=0, found = 0;
    bool res;

    for(i=0; i<(int)searchVec.size(); i++)
	{
        	res = search( inputVec, searchVec[i], comparison );	//search to find which matches when comapring two searches
        	sum += comparison;

		if ( res )						//once its found the matches it counts it...
			found++;
    	}
    cout << found << " numbers are found. The average number of comparisons in each search: " << (double)sum/(double)searchVec.size() << endl << endl;
}

int random_number() {
    return rand()%DATA_RANGE+1;
}

int main ()
{

    // -------- create unique random numbers ------------------//
    vector<int> inputVec(DATA_SIZE);
    srand(DATA_SEED);
    generate(inputVec.begin(), inputVec.end(), random_number);
    sort(inputVec.begin(), inputVec.end());
    vector<int>::iterator it = unique(inputVec.begin(), inputVec.end());
    inputVec.resize( it - inputVec.begin() );
    random_shuffle( inputVec.begin(), inputVec.end() );

    cout << "------ Data source: " << inputVec.size() << " unique random numbers ------" << endl; 
    print_vec(inputVec);
    cout << endl;

    // -------- create random numbers to be searched ---------//
    vector<int> searchVec(DATA_SIZE/2);
    srand(SEARCH_SEED);
    generate(searchVec.begin(), searchVec.end(), random_number);

    cout << "------ " << searchVec.size() << " random numbers to be searched: ------" << endl;
    print_vec(searchVec);
    cout << endl;

    cout << "Linear search: ";
    average_comparisons(inputVec, searchVec, linear_search);
    cout << "Binary search: ";
    average_comparisons(inputVec, searchVec, binary_search);

    sort(inputVec.begin(), inputVec.end());
    cout << "------- numbers in data source are now sorted ---------" << endl << endl;
    cout << "Linear search: ";
    average_comparisons(inputVec, searchVec, linear_search);
    cout << "Binary search: ";
    average_comparisons(inputVec, searchVec, binary_search);

    return 0;

}


