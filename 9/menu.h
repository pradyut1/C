#ifndef _MENU_H
#define _MENU_H

#include "mystring.h"

class Selection {
private:
    char selector;           //character entered by user to select menu option
    String description;      //description of selection option

public:
    Selection(): selector('\0')
    {}
    Selection(char s, String d): selector(s), description(d)
    {}

    friend class Menu;
};

class Menu {
private:
    String title;       //menu title to be displayed
    Selection *item;    //pointer to array of menu items
    int itemcnt;        //number of menu items

    bool valid(char c);

public:
    //constructors and destructors
    Menu(): item(NULL), itemcnt(0)
    {}
    Menu(String t, Selection s[]);     //build menu with the n selections in s
    ~Menu();

    //access functions
    char choice();                      //display menu and return user selection

    //modifier functions
    void set_selections(String t, Selection s[]);
};

extern const Selection NULL_SELECTION;
#endif