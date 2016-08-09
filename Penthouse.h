#ifndef PENTHOUSE_H
#define PENTHOUSE_H

#include "Room.h"


class Penthouse : public Room
{
    public:
        Penthouse();
        virtual ~Penthouse();
        int choice();
        int interact();
    protected:
    private:
};

#endif
