#include <iostream>
#include "linkedlist.h"

void main()
{
    LnkdList list;

    for (int i=0; i<16; i++)
        list.InsertEnd(i*2);

    list.Display();

    cout << "\n\n";

    list.Remove(6);
    list.Remove(0);
    list.Remove(30);
    list.Insert(14);
    list.InsertEnd(28);
    list.Display();

    cout << endl;
}