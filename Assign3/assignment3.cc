/****************************************************************
   PROGRAM:   Sieve of Eratosthenes
   AUTHOR:    Shaniel Omar Rivas Verdejo
   LOGON ID:  z1123907
   DUE DATE:  2-17-2017

   PURPOSE:  to write and implement a C++ program to find and print
	     all prime numbers within a range [lower upper] using the
	     algorithm known as the Sieve of Eratosthenes. The program
	     will have basic interactive user interface to take input
	     values of lower and upper and allow the user to continue
	     or quit the game.

   NOTES:     any relevant information that would be of
              additional help to someone looking at the program.
****************************************************************/

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <set>

using namespace std;

/****************************************************************

   FUNCTION:   sieve

   ARGUMENTS:  set s, const int lower, const int upper

   RETURNS:    Nothing

   NOTES:     it remove all the numbers that are not prime
****************************************************************/
void sieve( set<int>& s, const int lower, const int upper)
{

	// insert elements into set up to given limit
	for(int i= lower; i < upper + 1; i++)
	{
		s.insert(i);
	}
	// loop through each key ( 2,3..n )
	for(int i = 2; i*i < upper; i++)
	{
		// remove multiples of i such that i * i >= n
		for(int j = 2; j*i<= upper; j ++)
		{
			s.erase(j*i);
		}
	}
}

/****************************************************************

   FUNCTION:   Print Prime

   ARGUMENTS:  constant set int s, const int lower, const int upper

   RETURNS:    Nothing

   NOTES:     Prints all the numbers that are prime
****************************************************************/
void print_primes( const set<int>& s, const int lower, const int upper)
{
	int count = 0;

	set <int>::iterator it;

	//once it counted 8 values it makes a new line and count another 8 values
	for(it = s.begin(); it != s.end(); it++)
	{
		if(count == 8)
		{
			count = 0;
			cout << endl;
		}
		count++;
		//put 6 spaces between the values
		cout << *it << setw(6) << "  ";
	}

	cout << endl;
}

/****************************************************************

   FUNCTION:   Run Game

   ARGUMENTS:  set int s

   RETURNS:    Nothing

   NOTES:     runs through the game
****************************************************************/
void run_game(set<int>& s)
{
	char again;

	do
	{
		cout << "Lets the game begin!!! " << endl;

		//asking for a lower bound
		int lower;
		cout << "Pick a Lowerbound: ";
		cin >> lower;

		if(lower<2)
		{
			lower=2;
		}

		//askign for upper bound
		int upper;
		cout << "Pick an Upperbound: ";
		cin >> upper;

		//making sure that the lower isnt higher than the upper
		if(lower>=upper)
		{

			cerr << "lower error, try again! ";
			cin >> lower;
			cout << "Do you want to change the upperbound? ";
			cin >> again;

			if(again== 'Y' or 'y')
			{
				cout << "Pick a new upperbound then ";
				cin >> upper;
			}
			else
			{
				upper=upper;
			}

		}
		//run it
		sieve(s, lower, upper);
		print_primes(s, lower, upper);

		cout << "Would you like to run the game again?" << endl;
		cin >> again;
		cout << endl;

	}
	while(again== 'Y' or again=='y');

	if(again!= 'Y' or 'y')
                {
                        cout << " OK!! Come back and play next time!!" << endl;
                }

}

int main()
{
	set<int>s;
	run_game(s);

    return 0;
}
