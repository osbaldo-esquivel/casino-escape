#include "Room.h"

class Gift: public Room
{
public:
    Gift(std::string desc):Room(10, true)
    {
        this->setName(desc);
    }
};
