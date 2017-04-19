#include <iostream>
#include <cstdlib>
#include <ctime>

#ifndef DICE_H
#define DICE_H

class Dice
{
public:
	// set number of sides
	Dice(int numSides)
	{
		this->numSides = numSides;
	}

	// return random value for side
	virtual int rollDice() const
	{
		return (rand() % numSides) + 1;
	}
protected:
	int numSides;
};

#endif // DICE_H