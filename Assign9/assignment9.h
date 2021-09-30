#ifndef ASSIGNMENT9_H
#define ASSIGNMENT9_H
#include <vector>
#include <list>

class graph
{
    private:
        int size;
        std::vector< std::list<int> > adj_list;
        std::vector< char > labels;
        void depth_first( int );
    public:
        graph( const char* filename );
        ~graph();
        int get_size() const;
        void traverse( ) ;
        void print ( ) const;
};

#endif
