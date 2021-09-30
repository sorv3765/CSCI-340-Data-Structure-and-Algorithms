#include <iostream>
#include <algorithm>
#include <vector>

const int DATA_RANGE = 100;
const int DATA_SIZE = 100;
const int DATA_SEED = 7;
const int SEARCH_SEED = 9;

bool linear_search(const vector<int>& inputVec, const int x, int& comparisons)
{
	return find(inputVec.begin(), inputVec.end(), x), inputVec.begin());
}

bool binary_search(const vector<int>& inputVec, const int x, int& comparisons)
{

}

void print_vec( const vector<int>& vec )
{

}

void average_comparisons(const vector<int>& inputVec, const vector<int>& searchVec, bool (*search)(const vector<int>&, const int, int&) ) {
    int i, comparison=0, sum=0, found = 0;
    bool res;
    for (i=0; i<(int)searchVec.size(); i++) {
        res = search( inputVec, searchVec[i], comparison );
        sum += comparison;
        if ( res )
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


