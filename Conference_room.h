#ifndef CONFERENCE_ROOM_H
#define CONFERENCE_ROOM_H

#include "Room.h"


class Conference_room : public Room
{
    public:
        Conference_room();
        virtual ~Conference_room();
        int choice();
        int interact();
    protected:
    private:
};

#endif
