#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <iostream>

using namespace std;

//NodeInt struct used in implementation of basic linked list
struct Node {
    int data;
    Node *next;
};

//basic list of ints implemented with dynamic allocation
class LnkdList {
private:
    Node *first;                   //points to first node in list or NULL

public:
    //constructors and destructors
    LnkdList(): first(nullptr)        //initialize empty list
    {}
    ~LnkdList();                   //deallocate all nodes in list

    //access functions
    bool Find(int v);             //true if v in list, else false
    int Size();                   //number of list values, including duplicates
    int Count(int v);             //number of occurences of v in list

    //modifier functions
    void Insert(int v);           //insert node with data value v at list start
    void InsertEnd(int v);        //insert node with data value v at list end
    bool Remove(int v);           //delete node with value v and return true
                                  //return false if no node with value v in list

    //input/output functions
    void Display();               //display int values contained in list nodes
};

#endif