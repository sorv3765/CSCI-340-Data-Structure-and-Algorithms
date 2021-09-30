#ifndef ASSIGNMENT4_H
#define ASSIGNMENT4_H
#include <queue>
#include <iostream>
#include <iomanip>

using namespace std;

class Stack
{
    private:
        std::queue<int> q1, q2;
    public:
        bool empty() const;
        int size() const;
        int top();
        void push(const int& val);
        void pop();
};

#endif
