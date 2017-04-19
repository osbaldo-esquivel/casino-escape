#include <iostream>
#include <string>

#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

class Item
{
private:
    std::string desc;
    int value;
public:
    Item(std::string itDesc, int val)
    {
        desc = itDesc;
        value = val;
    }
    int getVal()
    {
        return value;
    }
    void setVal(int inVal)
    {
        value = inVal;
    }
    std::string getDesc()
    {
        return desc;
    }
};

#endif // ITEM_H_INCLUDED
