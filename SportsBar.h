#include "Room.h"

class SportsBar:public Room
{
public:
    SportsBar(std::string desc):Room(7, false)
    {
        this->setName(desc);
    }
};
