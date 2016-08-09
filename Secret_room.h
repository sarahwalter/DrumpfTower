#ifndef SECRET_ROOM_H
#define SECRET_ROOM_H

#include "Room.h"


class Secret_room : public Room
{
    public:
        Secret_room();
        virtual ~Secret_room();
        int choice();
        int interact();
    protected:
    private:
};

#endif
