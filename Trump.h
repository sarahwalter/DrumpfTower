#ifndef TRUMP_H
#define TRUMP_H

#include <iostream>
#include <vector>
#include "Room.h"

class Trump
{
    public:
        Trump();
        ~Trump();
        void move();
        Room* getLocation();
        void setLocation(Room*);
        bool addVotes(std::string);
        int readVotes();
		int countVotes();
		
    private:
        std::vector<std::string> votes;
        Room* location;
};

#endif
