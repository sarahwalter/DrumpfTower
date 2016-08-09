#ifndef LOBBY_H
#define LOBBY_H

#include "Room.h"

class Lobby : public Room
{
    public:
        Lobby();
        virtual ~Lobby();
        int choice();
        int interact();
    protected:
    private:
};

#endif 
