#ifndef SECRET_PASSAGE_H
#define SECRET_PASSAGE_H

#include "Room.h"


class Secret_passage : public Room
{
    public:
        Secret_passage();
        virtual ~Secret_passage();
        int choice();
        int interact();
    protected:
    private:
};

#endif 
