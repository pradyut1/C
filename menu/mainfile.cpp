#include <iostream>
#include <conio.h>
#include "mystring.h"
#include "menu.h"

using namespace std;

void A_routine();
void B_routine();
void C_routine();
void D_routine();
void E_routine();

void main()
{
    //the following constructs are used to supply the data needed instantiate
    //the main application menu
    String menu_title = "My Menu";
    Selection menu_options[] = {
                        Selection('A', "Selection 1"),
                        Selection('B', "Selection 2"),
                        Selection('C', "Selection 3"),
                        Selection('D', "Selection 4"),
                        Selection('E', "Selection 5"),
                        Selection('Q', "Terminate Program"),
                        NULL_SELECTION};

    Menu mainMenu(menu_title, menu_options);

    char action;

    do {
        switch (action = mainMenu.choice()) {
            case 'A': A_routine();
                break;
                
            case 'B': B_routine();
                break;

            case 'C': C_routine();
                break;

            case 'D': D_routine();
                break;

            case 'E': E_routine();
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

void A_routine()
{
    //A_routine actions;
    cout << "A_routine actions" << endl;
}

void B_routine()
{
    //B_routine actions;
    cout << "B routine actions" << endl;
}

void C_routine()
{
    //C_routine actions;
    cout << "C routine actions" << endl;
}

void D_routine()
{
    //D_routine actions;
    cout << "D routine actions" << endl;
}

void E_routine()
{
    //E_routine actions;
    cout << "E routine actions" << endl;
}