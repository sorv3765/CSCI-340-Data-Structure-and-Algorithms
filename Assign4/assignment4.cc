/****************************************************************
   PROGRAM:   Stack
   AUTHOR:    Shaniel Omar Rivas Verdejo
   LOGON ID:  z1123907
   DUE DATE:  2-28-2017

   PURPOSE:  To implement the Stack class using STL queues

   NOTES:     any relevant information that would be of
              additional help to someone looking at the program.
****************************************************************/
#include <iostream>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include "assignment4.h"

using namespace std;

/****************************************************************

   FUNCTION:   Empty

   ARGUMENTS:  takes nothing

   RETURNS:    boolean

   NOTES:     checks to see if empty or not.
****************************************************************/
bool Stack::empty() const
{
	if(q1.empty() and q2.empty())		//check to see fi both q1 and q2 is empty
		return true;
	else
		return false;
}

/****************************************************************

   FUNCTION:   Size

   ARGUMENTS:  takes nothing

   RETURNS:    integer

   NOTES:     count the size of the Queue
****************************************************************/
int Stack::size() const
{
	return q1.size();	//count to see what size of both q1 and q2 if it's not empty
}

/****************************************************************

   FUNCTION:   Generate Random Number

   ARGUMENTS:  takes nothing

   RETURNS:    integer

   NOTES:     picks the value on the top of the stack
****************************************************************/
int Stack::top()
{
	if(!q1.empty())				//when q1 have something the take the top value of the stack
		return q1.back();
	else					//otherwise if q1 is empty then take the top value of q2
		return q2.back();
}

/****************************************************************

   FUNCTION:   Push

   ARGUMENTS:  constant int val

   RETURNS:    Nothing

   NOTES:     add the value into the queue
****************************************************************/
void Stack::push(const int& val)
{
	q1.push(val);			//add value in q1
}

/****************************************************************

   FUNCTION:   Pop

   ARGUMENTS:  takes nothing

   RETURNS:    Nothing

   NOTES:     removes the value and place elsewhere
****************************************************************/
void Stack::pop()
{
if(q1.empty())
	return;

		while(q1.size()!=1)		//while q1 is not equal to 1
		{
			int t=q1.front();
			q1.pop();		//remove form q1
			q2.push(t);		//from q1 put it in q2
		}

		q1.pop();

		while(q2.size()!=0)		//while q2 is not empty
		{
			int t=q2.front();
			q2.pop();		//remove it from q2
			q1.push(t);		//from q2 put it in q1
		}

}

int main()
{
    Stack s;
    string op;
    int val = 0;

   cout << "operation -- size front end" << endl;
   cin >> op;
   while ( !cin.eof() ) {
        if ( op == "push" ) {
            cin >> val;
            s.push( val );
            cout << op << " " << val << "    -- ";
        }
        else if ( op == "pop" ) {
            s.pop();
            cout << op << "       -- ";
        }
        else {
            cerr << "Error input: " << op << endl;
            return 1;
        }
        cout << setw(3) << s.size() << setw(5) << s.top() << endl;
        cin >> op;
    }

    while ( !s.empty() )
        s.pop();
    cout << "End -- size of Stack is: " << s.size() << endl;

    return 0;
}
