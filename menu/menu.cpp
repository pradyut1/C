#include "menu.h"

//Menu class functions
Menu::Menu(String t, Selection s[])
{
    //determine number of items to be included in menu by searching for
    //Selection where selector value is null character ('\0')
    for (itemcnt=0; s[itemcnt].selector; itemcnt++)
        ;

    //allocate array to hold menu selection option items
    item = new Selection[itemcnt];

    //set title and populate array
    title = t;
    for (int i=0; i<itemcnt; i++)
        item[i] = s[i];
}

Menu::~Menu()
{
    delete[] item;
}

void Menu::set_selections(String t, Selection s[])
{
    //determine number of items to be included in menu by searching for
    //Selection where selector value is null character ('\0')
    for (itemcnt=0; s[itemcnt].selector; itemcnt++)
        ;

    //deallocate current Selection array
    delete[] item;
    
    //allocate array to hold menu selection option items
    item = new Selection[itemcnt];

    //set title and populate array
    title = t;
    for (int i=0; i<itemcnt; i++)
        item[i] = s[i];
}

char Menu::choice()
{
    char inchoice;
    int blankspace,
        botspace,
        topspace;

    blankspace = 21 - (itemcnt * 2);
    topspace = blankspace / 2;
    botspace = blankspace - topspace + 1;

    do {
        for (int j=0; j<topspace; j++)
            cout << '\n';
    
        cout << '\t' << title << "\n\n";

        for (int i=0; i<itemcnt; i++)
            cout << '\t' << item[i].selector
                 << '\t' << item[i].description << "\n\n";

        for (int j=0; j<botspace; j++)
            cout << '\n';

        cout << "\n\tSelection? ";
        cin >> inchoice;
        if ((inchoice>='a') && (inchoice<='z'))       //c is lowercase?
            inchoice = inchoice & 0xdf;                //convert to uppercase

    } while (!valid(inchoice));

    return inchoice;
}

bool Menu::valid(char c)
{
    for (int i=0; i<itemcnt; i++)
        if (c == (item[i].selector & 0xdf))
            return true;

    return false;
}

const Selection NULL_SELECTION;