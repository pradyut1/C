#include <iostream>
#include <conio.h>
#include "inventory.h"
#include "mystring.h"
#include "menu.h"

using namespace std;

void InsertRoutine(Inventory &inv);
void FindRoutine(Inventory &inv);
void DeleteRoutine(Inventory &inv);
void SummaryRoutine(Inventory &inv);
void SaveToFileRoutine(Inventory &inv);
void LoadFromFileRoutine(Inventory &inv);

void main()
{
    Inventory inv1;
    
    //the following constructs are used to supply the data needed instantiate
    //the main application menu
    String menu_title = "My Menu";
    Selection menu_options[] = {
                        Selection('I', "Insert Item into Inventory"),
                        Selection('F', "Find Item in Inventory"),
                        Selection('D', "Display Inventory Data"),
                        Selection('S', "Display Inventory Summary Data"),
                        Selection('R', "Remove Item From Inventory"),
                        Selection('P', "Generate Inventory Report"),
                        Selection('X', "Save to File"),
                        Selection('Y', "Load from File"),
                        Selection('Q', "Terminate Program"),
                        NULL_SELECTION};

    Menu mainMenu(menu_title, menu_options);

    char action;

    do {
        switch (action = mainMenu.choice()) {
            case 'I': InsertRoutine(inv1);
                break;
                
            case 'F': FindRoutine(inv1);
                break;

            case 'D': inv1.Display();
                break;

            case 'S': SummaryRoutine(inv1);
                break;

            case 'R': DeleteRoutine(inv1);
                break;

            case 'P': inv1.Report();
                break;

            case 'X': SaveToFileRoutine(inv1);
                break;

            case 'Y': LoadFromFileRoutine(inv1);
                break;

            case 'Q': cout << "\nProgram terminated normally\n" << endl;
                break;
        }

        if (action != 'Q') {
            cout << "\n\nPress a key to continue ";
            _getch();
        }
    } while (action != 'Q');
}

void InsertRoutine(Inventory &inv)
{
    InventoryItem invItm;
    
    cout << "Enter the requested item data" << endl;
    invItm.Read();
    if (inv.Insert(invItm))
        cout << "Item successfully added to inventory" << endl;
    else
        cout << "Request failed: Item already exists in inventory" << endl;
}

void FindRoutine(Inventory &inv)
{
    InventoryItem itm;
    int itmID;
    
    cout << "Enter item ID #: ";
    cin >> itmID;
    itm = inv.Find(itmID);

    if (itm == NULL_ITEM)
        cout << "No item found with ID # " << itmID << endl;
    else
        itm.Display();
}

void DeleteRoutine(Inventory &inv)
{
    int itmID;
    
    cout << "Enter ID # if item to be remove from inventory: ";
    cin >> itmID;

    if (inv.Remove(itmID))
        cout << "Item successfully removed" << endl;
    else
        cout << "Item not found" << endl;
}

void SummaryRoutine(Inventory &inv)
{
    cout << "Inventory Owner: " << inv.getOwner()
        << "\nNumber of Inventory Items: " << inv.getItemCount()
        << "\tInventory Value: " << inv.Value() << endl;
}

void SaveToFileRoutine(Inventory &inv)
{
    String fileName;

    cout << "Enter filename: ";
    cin >> fileName;

    inv.Save(fileName);

    cout << "Data saved" << endl;
}

void LoadFromFileRoutine(Inventory &inv)
{
    String fileName;

    cout << "Enter filename: ";
    cin >> fileName;

    if (inv.Load(fileName))
        cout << "Data loaded" << endl;
    else
        cout << "File not found" << endl;
}