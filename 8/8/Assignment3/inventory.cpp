#include "inventory.h"

const InventoryItem NULL_ITEM;

//InventoryItem Class Member Functions

//InventoryItem Class Accessor Functions
bool InventoryItem::operator==(InventoryItem itm)
{
    return (id == itm.id) && (name == itm.name) && (uprice == itm.uprice)
        && (quanty == itm.quanty);
}

//InventoryItem Class Input/Output Functions
void InventoryItem::Read()
{
    cout << "Enter Item Identification Number: ";
    cin >> id;
    cout << "Enter Item Name: ";
    cin >> name;
    cout << "Enter Unit Price: ";
    cin >> uprice;
    cout << "Enter Quantity: ";
    cin >> quanty;
}


void InventoryItem::Display()
{
    cout << "\nID Number: " << id
        << "\tItem Name: " << name
        << "\nUnit Price: " << uprice
        << "\tQuantity: " << quanty << endl;
}


//Inventory Class Member Functions

//constructors/destructor

Inventory::~Inventory()
{
    InvNode *INptr;

    while (first) {               //while first is pointing to a node
        INptr = first;            //node pointed to by first is to be deleted
        first = first->next;      //set first to point to next node
        delete INptr;             //deallocate node first originally pointed to
    }
}

//Accessor Functions :

double Inventory::Value() const
{
    double total = 0;

    for (InvNode *INptr = first; INptr; INptr = INptr->next)
        total += INptr->invItem.getValue();

    return total;
}



InventoryItem Inventory::Find(int idno)
{
    InventoryItem result;         //default initial value is NULL_ITEM
    InvNode *ptr;

    for (ptr = first; ptr && ptr->invItem.getID() != idno; ptr = ptr->next)
        ;

    if (ptr)
        result = ptr->invItem;

    return result;
}

//Mutator/Modifier Functions :

bool Inventory::Insert(InventoryItem itm)
{
    InvNode *INptr,
        *ptr;
    bool result = false;

    if ((first == nullptr) || (first->invItem.getID() > itm.getID())) {
        INptr = new InvNode(itm, first);
        first = INptr;
        itmCount++;
        result = true;
    }
    else if (itm.getID() != first->invItem.getID()) {  //itm not first in list
        for (ptr = first; ptr->next && ptr->next->invItem.getID() < itm.getID(); ptr = ptr->next)
            ;
        if ((ptr->next == nullptr) || (ptr->next->invItem.getID() > itm.getID())) {
            INptr = new InvNode(itm, ptr->next);
            ptr->next = INptr;
            itmCount++;
            result = true;
        }
    }

    return result;
}

bool Inventory::Remove(int idno)
{
    InvNode *ptr,
        *tptr;
    bool result = false;

    if (first && first->invItem.getID() == idno) {    //first node to be removed
        ptr = first;
        first = first->next;
        delete ptr;
        itmCount--;
        result = true;
    }
    else {
        for (ptr = first; (ptr->next) && (ptr->next->invItem.getID() < idno); ptr = ptr->next)
            ;
        if ((ptr->next != nullptr) && (ptr->next->invItem.getID() == idno)) {
            tptr = ptr->next;
            ptr->next = ptr->next->next;
            delete tptr;
            itmCount--;
            result = true;
        }
    }

    return result;
}

//Input/Output Functions
void Inventory::Display()
{
    cout << "Inventory Owner: " << owner
        << "\nItem Count: " << itmCount
        << "\tInventory Value: " << Value() << endl;
    
    for (InvNode *ptr = first; ptr; ptr = ptr->next) {
        ptr->invItem.Display();
        cout << endl;
    }
}