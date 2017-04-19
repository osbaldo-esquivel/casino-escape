#include "Room.h"

class Gym:public Room
{
public:
    Gym(std::string desc):Room(4, false)
    {
        this->setName(desc);
    }
};
