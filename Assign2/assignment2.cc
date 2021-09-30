/****************************************************************
   PROGRAM:   Search Algoithm
   AUTHOR:    Shaniel Omar Rivas Verdejo
   LOGON ID:  z1123907
   DUE DATE:  2-09-2017

   PURPOSE:  To write and implement a C++ program to implement two
              search algorithms (linear search and binary search) on
              randomly generated integers stored in vectors.

   NOTES:     any relevant information that would be of
              additional help to someone looking at the program.
****************************************************************/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iomanip>


const int DATA_SIZE = 200;
const int SEARCH_SIZE = 100;
const int DATA_SEED = 7;
const int SEARCH_SEED = 9;

const int LOW= 1;
const int HIGH= 200;

using namespace std;

/****************************************************************

   FUNCTION:   Generate Random Number

   ARGUMENTS:  constant vector inputVec, const int x, int comparison

   RETURNS:    Nothing

   NOTES:     it randomly pick a number
****************************************************************/
void genRndNums( vector<int>& v, int seed )
{
	int i;
	srand(seed);

	for(i=0;i<v.size(); i++)						//generate random number between 1 and 200
	{
		v[i]=rand()%(HIGH - LOW + 1) + LOW;
	}
}

/****************************************************************

   FUNCTION:   Linear Search

   ARGUMENTS:  input vector named inputVec, x,

   RETURNS:    Integer

   NOTES:     It simply starts searching for x from the beginning
	      of vector v to the end, but it stops searching when
              there is a match. If the search is successful, it
              returns the position (starting at 0) of found item;
              otherwise, it returns -1.
****************************************************************/
int linearSearch( const vector<int>& inputVec, int x)
{
	vector<int>::const_iterator it;                         		//declare a public member

        it=find(inputVec.begin(), inputVec.end(), x);     			//find the number from begin to end

                if(it!=inputVec.end())                                 		//
                       return distance(inputVec.begin(), it);
		else
			return -1;

        return -1;

}

/****************************************************************

   FUNCTION:   Binary Search

   ARGUMENTS:  constant vector inputVec, const int x

   RETURNS:    Integer

   NOTES:     A binary search algorithm, where x is the searched item
              in vector inputVec. If the search is successful, it
              returns the position (starting at 0) of found item;
              otherwise, it returns -1.
****************************************************************/
int binarySearch( const vector<int>& inputVec, int x)
{
	pair<vector<int>::const_iterator, vector<int>::const_iterator>  bounds;	//declare a public member for bounds

	bounds=equal_range(inputVec.begin(), inputVec.end(), x);		//putting the range of where the search will be between two bounds

	if(bounds.first!=bounds.second)
		return distance(inputVec.begin(), bounds.first);
	else
		return -1;
}

/****************************************************************

   FUNCTION:   Search

   ARGUMENTS:  constant vector inputVec, const vector searchVec, int *p

   RETURNS:    Integer

   NOTES:     Matching the two searches
****************************************************************/
int search( const vector<int>& inputVec, const vector<int>& searchVec,
            int (*p)( const vector<int>&, int) )
{
	int success=0;
	int temp;

	for(int i=0; i < searchVec.size(); i++)					//it will search for a match between input vector and search vector
	{
		temp= p(inputVec, searchVec[i]);

		if(temp!=-1)							//if it matches then count as a succesful for each match
		{
			success++;
		}
	}

	return success;
}

/****************************************************************

   FUNCTION:   Binary Search

   ARGUMENTS:  constant vector inputVec

   RETURNS:    Nothing

   NOTES:     sort the number in ascending order
****************************************************************/
void sortVector (vector<int>& inputVec)
{
	sort(inputVec.begin(), inputVec.end());					//sort it in ascending order
}

void printStat (int totalSucCnt, int vec_size)
{
	double percentage;

	percentage=((float)totalSucCnt/(float)vec_size)*100;			// calculate the percentage of total success counts

cout << "Successful searches: " << percentage << "%";

}

/****************************************************************

   FUNCTION:   Print

   ARGUMENTS:  constant vector called vec

   RETURNS:    Return Nothing

   NOTES:      Print out what matches and have been found.
****************************************************************/
void print_vec( const vector<int>& vec )
{
	vector<int>::const_iterator result;                     //declare a public member

        int count=0;                                            //set it to 0

        for(result=vec.begin(); result!=vec.end(); result++)    //runs a loop to print every numbers
        {
                cout << setw(5) <<*result;                      //puts 5 spaces
                count++;

                if(count%12==0)                                 //make a new line after every 12 numbers
                cout << endl;
        }
}

int main()
{
    vector<int> inputVec(DATA_SIZE);
    vector<int> searchVec(SEARCH_SIZE);
    genRndNums(inputVec, DATA_SEED);
    genRndNums(searchVec, SEARCH_SEED);

    cout << "----- Data source: " << inputVec.size() << " randomly generated numbers ------" << endl;
    print_vec( inputVec );
    cout << endl << "----- " << searchVec.size() << " random numbers to be searched -------" << endl;
    print_vec( searchVec );

    cout << "\nConducting linear search on unsorted data source ..." << endl;
    int linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on unsorted data source ..." << endl;
    int binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    sortVector( inputVec );

    cout << "\nConducting linear search on sorted data source ..." << endl;
    linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on sorted data source ..." << endl;
    binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    return 0;
}
