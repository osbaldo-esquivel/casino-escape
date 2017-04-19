#include "Room.h"
#include "Dice.h"

class BlackJack:public Room
{
public:
    BlackJack(std::string desc):Room(2, false)
    {
        this->setName(desc);
    }
};
