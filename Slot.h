#include "Room.h"

class Slot: public Room
{
public:
    Slot(std::string desc):Room(6, false)
    {
        this->setName(desc);
    }
};
