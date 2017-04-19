#include <iostream>
#include <string>
#include <vector>
#include "Room.h"

#ifndef PERSON_H
#define PERSON_H

class Person
{
private:
	std::string name; // user name
	double cash; // user cash
	std::vector<std::string> inv; // user inventory
public:
	Person()
	{
		cash = 500.00;
		name = " ";
	}
	void setName(std::string n)
	{
		this->name = n;
	}
	std::string getName()
	{
		return name;
	}
	double getCash()
	{
		return cash;
	}
	void setCash(double c)
	{
		this->cash = c;
	}
	void removeCash(double c)
	{
	    cash -= c;
	}
	void addCash(double c)
	{
	    cash += c;
	}
};

#endif // PERSON_H
