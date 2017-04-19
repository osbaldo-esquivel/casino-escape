#include "Room.h"

class Craps:public Room
{
public:
    Craps(std::string desc):Room(3, false)
    {
        this->setName(desc);
    }
};
