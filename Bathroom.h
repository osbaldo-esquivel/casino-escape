#include "Room.h"

class Bathroom:public Room
{
public:
    Bathroom(std::string desc):Room(1, false)
    {
        this->setName(desc);
    }
};
