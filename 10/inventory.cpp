#include <fstream>
#include <iomanip>
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

void Inventory::Report()
{
    double totValue = 0;
    //output report heading
    cout << right << setw(45) << "INVENTORY ITEM REPORT"
        << left
        << "\n\nOWNER: " << owner
        << setw(14) << "\n\nITEM #"
        << setw(25) << "ITEM NAME"
        << setw(11) << "U. PRICE"
        << setw(9) << "QTY"
        << "VALUE\n\n"
        << right;       //in preparation for first detail line

    //process and output detail lines
    cout << setprecision(2) << setiosflags(ios::fixed | ios::showpoint);

    for (InvNode *ptr = first; ptr; ptr = ptr->next) {
        cout << setfill('0') << setw(5) << ptr->invItem.getID() << setfill(' ')
            << setw(9) << ' '
            << left << setw(21) << ptr->invItem.getName()
            << right << setw(11) << ptr->invItem.getUnitPrice()
            << setw(8) << ptr->invItem.getQuantity()
            << setw(12) << ptr->invItem.getValue() << endl;

        totValue += ptr->invItem.getValue();
    }

    //output report footing
    cout << "\n\nTOTALS:" << right << setw(59) << totValue
        << "\n# OF ITEMS"
        << setw(8) << itmCount << endl;
}

void Inventory::Save(String fn)
{
    ofstream outFile;
    char *filename;
    int intValue;                      //used to output an int value
    double doubleValue;                //used to output a double value

    //prepare file to receive data
    if (fn.SubString(".") == -1)       //if fn does not include an extension
        fn.Append(".inv");             //append default extension

    filename = new char[fn.Length() + 1];
    fn.ToCstring(filename);    
    outFile.open(filename, ios::out | ios::binary);
    delete[] filename;
    
    //output Inventory object data member values
    intValue = owner.Length();
    outFile.write(reinterpret_cast<char*>(&intValue), sizeof(int));
    outFile << owner;
    outFile.write(reinterpret_cast<char*>(&itmCount), sizeof(int));

    //output inventory item data
    for (InvNode *ptr = first; ptr; ptr = ptr->next) {
        intValue = ptr->invItem.getID();
        outFile.write(reinterpret_cast<char*>(&intValue), sizeof(int));
        intValue = ptr->invItem.getName().Length();
        outFile.write(reinterpret_cast<char*>(&intValue), sizeof(int));
        outFile << ptr->invItem.getName();
        doubleValue = ptr->invItem.getUnitPrice();
        outFile.write(reinterpret_cast<char*>(&doubleValue), sizeof(double));
        intValue = ptr->invItem.getQuantity();
        outFile.write(reinterpret_cast<char*>(&intValue), sizeof(int));
    }

    outFile.close();
}

bool Inventory::Load(String fn)
{
    ifstream inFile;
    char *filename;
    InventoryItem inputItm;
    InvNode *INptr,                    //used to remove and insert InvNodes
        *newNodeptr;                   //pointer to new node to be inserted
    int intValue,                      //used to input an int value
        ID,                            //used to input inventory item ID number
        Quantity;                      //used to input inventory item quantity
    double UPrice;                     //used to input inventory item unit price
    char *cStringValue,                //used to input Cstring value
        *Name;                         //used to input inventory item name
    bool result;                       //used to return result of load operation

    //prepare file to receive data
    if (fn.SubString(".") == -1)       //if fn does not include an extension
        fn.Append(".inv");             //append default extension

    filename = new char[fn.Length() + 1];
    fn.ToCstring(filename);
    inFile.open(filename, ios::in | ios::binary);

    if (inFile) {                      //file successfully opened
        //remove any existing inventory data
        while (first) {
            INptr = first;
            first = first->next;
            delete INptr;
        }

        //input Inventory object data member values
        inFile.read(reinterpret_cast<char*>(&intValue), sizeof(int));
        cStringValue = new char[intValue + 1];
        inFile.read(cStringValue, intValue);
        cStringValue[intValue] = '\0';
        owner = cStringValue;

        inFile.read(reinterpret_cast<char*>(&itmCount), sizeof(int));

        //input inventory item data
        INptr = nullptr;

        for (int i = 0; i < itmCount; i++) {
            inFile.read(reinterpret_cast<char*>(&ID), sizeof(int));
            inFile.read(reinterpret_cast<char*>(&intValue), sizeof(int));
            Name = new char[intValue + 1];
            inFile.read(Name, intValue);
            Name[intValue] = '\0';
            inFile.read(reinterpret_cast<char*>(&UPrice), sizeof(double));
            inFile.read(reinterpret_cast<char*>(&Quantity), sizeof(int));

            newNodeptr = new InvNode;
            newNodeptr->invItem =
                InventoryItem(ID, Name, UPrice, Quantity), nullptr;
            delete[] Name;

            if (INptr == nullptr)
                first = newNodeptr;
            else
                INptr->next = newNodeptr;

            INptr = newNodeptr;
        }

        if (INptr)
            INptr->next = nullptr;

        inFile.close();
        result = true;
    }

    else           //if (infile)
        result = false;

    return result;
}