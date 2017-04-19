#include <iostream>
#include <string>
#include <vector>
#include "Item.h"

#ifndef CASINO_H
#define CASINO_H

class Room
{
protected:
	Room *east; // direction pointers
	Room *west;
	Room *north;
	Room *south;
    int numRoom; // room value
	bool end; // exit room
	std::string name; // room name
	std::vector<Item> itRoom;
public:
	Room(int val, bool exit) // constructor
	{
	    name = " ";
	    north = NULL;
	    south = NULL;
	    east = NULL;
	    west = NULL;
	    this->end = exit;
	    this->numRoom = val;
	}
	Room *getNorth()
	{
	    return north;
	}
	Room *getSouth()
	{
	    return south;
	}
	Room *getEast()
	{
	    return east;
	}
	Room *getWest()
	{
	    return west;
	}
	virtual void setName(std::string desc)
	{
	    this->name = desc;
	}
	virtual std::string getName()
	{
	    return name;
	}
	virtual int getVal()
	{
	    return numRoom;
	}
	virtual bool isExit()
	{
	    return end;
	}
	virtual void setNorth(Room *next)
	{
	    this->north = next;
	    this->north->south = this;
	}
	virtual void setSouth(Room *next)
	{
	    this->south = next;
	    this->south->north = this;
	}
	virtual void setEast(Room *next)
	{
	    this->east = next;
	    this->east->west = this;
	}
	virtual void setWest(Room *next)
	{
	    this->west = next;
	    this->west->east = this;
	}
	virtual void display() // give info about room
	{
	    std::cout << "\nYou are in the " << getName()
                  << std::endl;

        if(north != NULL)
        {
            std::cout << "\nNorth is the " << north->getName()
                      << std::endl;
        }
        else
        {
            std::cout << "\nThere is no exit to the north!"
                      << std::endl;
        }
        if(south != NULL)
        {
            std::cout << "\nSouth is the " << south->getName()
                      << std::endl;
        }
        else
        {
            std::cout << "\nThere is no exit to the south!"
                      << std::endl;
        }
        if(east != NULL)
        {
            std::cout << "\nEast is the " << east->getName()
                      << std::endl;
        }
        else
        {
            std::cout << "\nThere is no exit to the east!"
                      << std::endl;
        }
        if(west != NULL)
        {
            std::cout << "\nWest is the " << west->getName()
                      << std::endl;
        }
        else
        {
            std::cout << "\nThere is no exit to the west!"
                      << std::endl;
        }
	}
	virtual Item *getIt(int d)
	{
	    return &itRoom[d];
	}
	virtual bool hasIt(unsigned int d)
	{
	    if(itRoom.size() > d)
        {
            return true;
        }
        else
            return false;
	}
	virtual void addIt(Item *inIt)
	{
	    itRoom.push_back(*inIt);
	}
	virtual void delItem(int d)
	{
	    itRoom.erase(itRoom.begin() + d);
	}


};

#endif //CASINO_H
