#include "Room.h"

class Vip:public Room
{
public:
    Vip(std::string desc):Room(9, false)
    {
        this->setName(desc);
    }
};
