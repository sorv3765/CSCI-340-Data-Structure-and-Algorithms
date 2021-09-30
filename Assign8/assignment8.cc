/****************************************************************
   PROGRAM:   Hashing with Linear Probing
   AUTHOR:    Shaniel Omar Rivas Verdejo
   LOGON ID:  z1123907
   DUE DATE:  4-21-2017

   PURPOSE:  To write a C++ program to create, search, print, and
	     manage an item inventory.

   NOTES:     any relevant information that would be of
              additional help to someone looking at the program.
****************************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include "assignment8.h"

using namespace std;

/****************************************************************

   FUNCTION:   Constructor

   ARGUMENTS:  Integer S

   RETURNS:    Nothing

   NOTES:     create a hash table dynamically (with new operator) and other data memebers properly initialized
****************************************************************/
HT::HT(int s=11)
{
	hTable= new vector<Entry>(s);
	table_size=s;
        item_count=0;
}

/****************************************************************

   FUNCTION:   Destructor

   ARGUMENTS:  None

   RETURNS:    Nothing

   NOTES:      memory is released here with delete..
****************************************************************/
HT::~HT()
{
	delete hTable;
}

/****************************************************************

   FUNCTION:   Search

   ARGUMENTS:  constant string key

   RETURNS:    Integer

   NOTES:      Searches the hash table for a record with a given key
****************************************************************/
int HT::search(const string&key)
{
	int pos=hashing(key);
	for(int i=0; i<table_size; i++)
	{
		if(pos==table_size)
			pos=0;

		Entry e=(*hTable)[pos];

		if(e.key==key)		//compute hash table for record with given key
		{
			return pos;	//return the positionof found item
			pos++;
		}
	}
	return -1;
}

/****************************************************************

   FUNCTION:   Insert

   ARGUMENTS:  constant Entry e

   RETURNS:    Boolean

   NOTES:      Inserts item e in the hash table
****************************************************************/
bool HT::insert(const Entry& e)
{
	if(item_count==table_size)
		return false;

	int x = search(e.key);		//searching for the items

	if(x != -1)			//check if the item's key exist in the table or not
		return false;

	int pos=hashing(e.key);
	int i = pos;

	do
	{
		if(i==table_size)				//if position equal table size then position starts at 0
			i=0;

		Entry e1=(*hTable)[i];

		if((e1.key=="---") || (e1.key=="+++"))		//for if its empty or was deleted in the past insert it there...

		{
			(*hTable)[i].key=e.key;
			(*hTable)[i].description=e.description;
			item_count++;
			return true;
		}

		i++;						//increment the positions

	}while(pos!= i);
	return false;
}

/****************************************************************

   FUNCTION:   Remove

   ARGUMENTS:  constant string key

   RETURNS:    Boolean

   NOTES:      Remove itemwith given key
****************************************************************/
bool HT::remove(const string& key)
{
	int pos=search(key);

	if(pos==-1)					//if position not found
		return false;

	Entry e1=(*hTable)[pos];

	if(e1.key!="+++")				//it removes the entry of the given key
	{
		(*hTable)[pos].key="+++";		//setting it to "+++"
		item_count--;				//decrease the item count
		return true;
	}
	return false;
}

/****************************************************************

   FUNCTION:   Print

   ARGUMENTS:  None

   RETURNS:    Nothing

   NOTES:      Prints the existing entries in the hash table
****************************************************************/
void HT::print()
{
	cout << "----Hash Table----" << endl;
	for(int i=0; i<table_size; i++)
	{
		Entry e1=(*hTable)[i];
		if((e1.key!="---") && (e1.key!="+++"))
			cout << i << " : "<<e1.key<<" "<<e1.description<<endl;;
	}
	cout<< "-------------------" << endl;
}

/****************************************************************

   FUNCTION:   Get Entry

   ARGUMENTS:  constant string line

   RETURNS:

   NOTES:     takes a line of input and parses it to create a new Entry
****************************************************************/
Entry* get_entry(const string& line)
{
	Entry* e=new Entry();					//creating a new entry
	e->key=line.substr(2,3);
	e->description=line.substr(6,line.length()-6);

	return e;

}

/****************************************************************

   FUNCTION:   Get Key

   ARGUMENTS:  constant string line

   RETURNS:

   NOTES:     takes a line of input and parses it to return the item-key
****************************************************************/
string get_key(const string& line)
{
	return line.substr(2,3);
}


// key is in form of letter-letter-digit
// compute sum <-- ascii(pos1)+ascii(pos2)+ascii(pos3)
// compute sum%htable_size
int HT::hashing(const string& key)
{
   return ((int)key[0] + (int)key[1] + (int)key[2])%table_size;
}





int main(int argc, char** argv )
{
    	if ( argc < 2 )
	{
        	cerr << "argument: file-name\n";
        return 1;
    	}

    HT ht;
    ifstream infile(argv[1], ios::in);
    string line;
    infile >> line;
    while ( !infile.eof() )
	{
        	if ( line[0] == 'A' )
		{
            		Entry* e = get_entry( line );
            		ht.insert( *e );
            		delete e;
        	}
       		 else
		{
            		string key = get_key(line);
            		if ( line[0] == 'D' )
			{
                		cout << "Removing " << key << "...\n";
                		bool removed = ht.remove( key );

				if ( removed )
                    			cout << key << " is removed successfully...\n\n";
    		            	else
                    			cout << key << " does not exist, no key is removed...\n\n";
            		}
            		else if ( line[0] == 'S' )
			{
                		int found = ht.search( key );
                		if ( found < 0 )
                    			cout << key << " does not exit in the hash table ..." << endl << endl;
                		else
                   			cout << key << " is found at table position " << found << endl << endl;
            		}
            		else if ( line[0] == 'P' )
			{
                		cout << "\nDisplaying the table: " << endl;
                		ht.print();
            		}
            		else
                		cerr << "wrong input: " << line << endl;
        	}
        infile >> line;
    	}

    infile.close();
    return 0;
}
