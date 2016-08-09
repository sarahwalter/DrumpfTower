#ifndef DUNGEON_H
#define DUNGEON_H

#include "Room.h"

class Dungeon : public Room
{
    public:
        Dungeon();
        virtual ~Dungeon();
        int choice();
        int interact();
    protected:
    private:
};

#endif
