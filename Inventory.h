#include "Item.h"
#include <string>
#include <vector>

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory
{
private:
    std::vector<Item> inv;
    std::vector<std::string> invItems;
public:
    Inventory();
    void delItem(int d)
    {
        inv.erase(inv.begin() + d);
    }
    void addItem(Item *it)
    {
        inv.push_back(*it);
        invItems.push_back(it->getDesc());
    }
    bool hasIt(int d)
    {
        if(inv.size() > d)
        {
            return true;
        }
        else
            return false;
    }
    Item *getItem(int d)
    {
        return &inv[d];
    }
    int getSize()
    {
        return inv.size();
    }
    bool hasStr(std::string inStr)
    {
        if(std::find(invItems.begin(), invItems.end(), inStr) != invItems.end())
        {
            return true;
        }
        else
            return false;
    }
};

#endif // INVENTORY_H
