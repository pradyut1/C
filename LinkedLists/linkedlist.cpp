#include "linkedlist.h"

//constructors and destructors
LnkdList::~LnkdList()
{
    for (Node *delptr=first; first; delptr=first) {
        first = first->next;           //set first to point to next node in list
        delete delptr;                 //delete node first pointed to originally
    }
}

//access functions
bool LnkdList::Find(int v)
{
    for (Node *findptr=first; findptr; findptr=findptr->next)
        if (findptr->data == v)
            return true;

    return false;
}

int LnkdList::Size()
{
    int result=0;

    for (Node *nodeptr=first; nodeptr; nodeptr=nodeptr->next)
        result++;

    return result;
}

int LnkdList::Count(int v)
{
    int result=0;

    for (Node *nodeptr=first; nodeptr; nodeptr=nodeptr->next)
        if (nodeptr->data == v)
            result++;

    return result;
}

//modifier functions
void LnkdList::Insert(int v)
{
    //allocate node with value v, pointing to current first node in list
    Node *temp = new Node;

    temp->data = v;
    temp->next = first;

    first = temp;       //set first to point to newly allocated node
}

void LnkdList::InsertEnd(int v)
{
    //allocate node with value v, pointing to NULL (it will be last node)
    Node *temp = new Node,
         *curr;                   //used to traverse list to find last node

    temp->data = v;
    temp->next = nullptr;

    if (first == nullptr)         //i.e., list is empty
        first = temp;             //add node as only node in list
    else {
        //use curr to traverse list to reach the end of list
        //note: expression "curr->next" is equivalent to "(*curr).next"
        for (curr=first; (curr->next)!= nullptr; curr=curr->next)
            ;

        curr->next = temp;        //place node at current end of list
    }
}

bool LnkdList::Remove(int v)
{
    Node *delptr;                 //holds address of node to be deleted
    
    if (first == nullptr)         //list is empty
        return false;

    if (first->data == v) {       //first list node contains v; should remove
        delptr = first;           //keep address of node to be removed
        first = first->next;      //set first to point to next node in list
        delete delptr;            //deallocate node to be removed
        return true;
    }

    //traverse list until prevptr points to a node that points to a node
    //that contains value to be removed
    for (Node *prevptr=first; prevptr->next != nullptr; prevptr=prevptr->next)
        if ((prevptr->next)->data == v) {     //desired node found
            delptr = prevptr->next;            //hold address of desired node
            prevptr->next = (prevptr->next)->next;   //unlink from list
            delete delptr;
            return true;
        }

    return false;
}

//input/output functions
void LnkdList::Display()
{
    int linebrkcnt=0;             //line break counter to control line breaks

    for (Node *temptr=first; temptr; temptr=temptr->next) {
        if (linebrkcnt == 5) {
            linebrkcnt = 0;
            cout << endl;
        }

        cout << temptr->data << '\t';
        linebrkcnt++;
    }
}