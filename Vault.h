#include "Room.h"

class Vault:public Room
{
public:
    Vault(std::string desc):Room(8, false)
    {
        this->setName(desc);
    }
};

