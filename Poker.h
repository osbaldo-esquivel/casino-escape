#include "Room.h"

class Poker:public Room
{
public:
    Poker(std::string desc):Room(5, false)
    {
        this->setName(desc);
    }
};
