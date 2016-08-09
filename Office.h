#ifndef OFFICE_H
#define OFFICE_H

#include "Room.h"


class Office : public Room
{
    public:
        Office();
        virtual ~Office();
        bool enter(Trump*);
        int choice();
        int interact();
    protected:
    private:
};

#endif 
