#include <iostream>
#include "mystring.h"
#include "inventory.h"

using namespace std;

/*
void main()

{
    Inventory invObj("Warehouse 1");
    InventoryItem itma, itmb, itmc, itmd,
        itm1(1001, "item 1", 10, 1),
        itm2(1002, "item 2", 20, 2),
        itm3(1003, "item 3", 30, 3),
        itm4(1004, "item 4", 40, 4),
        itm5(1005, "item 5", 50, 5);

    invObj.Insert(itm1);
    invObj.Display();

    InvNode node1(itm1, nullptr);

    cout << node1.

}
*/

void main()
{
    Inventory invObj("Warehouse 1");
    InventoryItem itma, itmb, itmc, itmd,
        itm1(1001, "item 1", 10, 1),
        itm2(1002, "item 2", 20, 2),
        itm3(1003, "item 3", 30, 3),
        itm4(1004, "item 4", 40, 4),
        itm5(1005, "item 5", 50, 5);

    invObj.Display();

    invObj.Insert(itm1);
    invObj.Insert(itm2);
    invObj.Insert(itm3);
    invObj.Insert(itm4);
    invObj.Insert(itm5);

    invObj.Display();
    
    if (itma == NULL_ITEM)
        cout << "1 correct\n";
    else
        cout << "1 incorrect\n";
    if (itm1 == NULL_ITEM)
        cout << "2 incorrect\n";
    else
        cout << "2 correct\n";

    itma = invObj.Find(1001);
    itmb = invObj.Find(1003);
    itmc = invObj.Find(1005);
    itm1 = invObj.Find(1000);

    itma.Display();
    itmb.Display();
    itmc.Display();
    itm1.Display();

    if (invObj.Remove(1003))
        cout << "3 correct\n";
    else
        cout << "3 incorrect\n";
    if (invObj.Remove(1003))
        cout << "4 incorrect\n";
    else
        cout << "4 correct\n";
    if (invObj.Remove(1001))
        cout << "5 correct\n";
    else
        cout << "5 incorrect\n";
    if (invObj.Remove(1005))
        cout << "6 correct\n";
    else
        cout << "6 incorrect\n";
    invObj.Display();

    cout << endl;

    
}

