#ifndef _INVESTMENT_H
#define _INVESTMENT_H

#include "mystring.h"

class InventoryItem
{
private:
    int id;
    String name;
    double uprice;
    int quanty;

public:
    //constructors
    InventoryItem() : id(0), uprice(0), quanty(0)
    {}
    InventoryItem(int idno, String nme, double uprc, int qty)
        : id(idno), name(nme), uprice(uprc), quanty(qty)
    {}

    //Accessor Functions
    int getID() const
    {return id;}
    String getName() const
    {return name;}
    double getUnitPrice() const
    {return uprice;}
    int getQuantity() const
    {return quanty;}
    double getValue() const
    {return uprice * quanty;}
    bool operator==(InventoryItem itm);

    //Mutator / Modifier Functions :
    void setID(int idno)
    {id = idno;}
    void setName(String nme)
    {name = nme;}
    void setUnitPrice(double uprc)
    {uprice = uprc;}
    void setQuantity(int qty)
    {quanty = qty;}

    //Input/Output Functions :
    void Read();
    void Display();
};

//used to construct linked list of InventoryItems for Inventory class objects
class InvNode
{
private:
    InventoryItem invItem;
    InvNode *next;

public:
    InvNode(InventoryItem iItm, InvNode *n) : invItem(iItm), next(n)
    {}

    friend class Inventory;
};

class Inventory
{
private:
    String owner;
    InvNode *first;
    int itmCount;

public:
    //constructors/destructor
    Inventory() : first(nullptr), itmCount(0)
    {}
    Inventory(String ownr) : owner(ownr), first(nullptr), itmCount(0)
    {}
    ~Inventory();

    //Accessor Functions :
    String getOwner() const
    {return owner;}
    int getItemCount() const
    {return itmCount;}
    double Value() const;
    InventoryItem Find(int idno);

    //Mutator/Modifier Functions :
    void setOwner(String ownr)
    {owner = ownr; }
    bool Insert(InventoryItem itm);
    bool Remove(int idno);

    //Input/Output Functions
    void Display();
};


extern const InventoryItem NULL_ITEM;

#endif