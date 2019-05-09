#pragma once

#include <stdexcept>
#include "IntListNode.h"

using namespace std;

class IntegerList {    // a singly linked list
public:
    IntegerList();    // empty list constructor
    ~IntegerList();    // destructor
    int& front();    // return front element
    void addFront(int e);    // add to front of list
    void removeFront();   // remove front item list
    void print();
    int size() const;   // list size
    void AddAtPosition(int e, int p);
    int  sum();   // returns the sum of the nodes in the list
    int  sum(IntListNode* node);   // recursive function, used by above function
    double avg();
    void addTail(int num);
    void addTail(IntListNode * node, int num);
    int findNum(int num);
    int findNum(int num, IntListNode * node);
    int numofTimes(int num);
    int numofTimes(int num, IntListNode * node);
    void reverseList();
private:
    IntListNode* head;   // head of the list
    int     n;   // number of items
};


