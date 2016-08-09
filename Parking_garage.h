#ifndef PARKING_GARAGE_H
#define PARKING_GARAGE_H

#include "Room.h"


class Parking_garage : public Room
{
    public:
        Parking_garage();
        virtual ~Parking_garage();
        int choice();
        int interact();
    protected:
    private:
};

#endif 
