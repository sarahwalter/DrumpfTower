#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include <vector>

class Trump;

class Room
{
protected:
    std::string name;
    bool flooded;

    struct Exit                 // exit from a space
    {
        Room* dest;            // pointer to another space
        std::string descr;      // description of the path
        bool open;              // state open/closed of exit

        Exit( Room* d1, std::string d2, bool o = true)
        {
            dest = d1;
            descr = d2;
            open = o;
        }
    };

    std::vector<Exit> exits;    // all of the exits

    public:
        Room();
        virtual ~Room();

        int choice();
        virtual int interact() = 0;
        std::string getName();
        void setExit(Room* ,std::string , bool = true);
        Room* getExit(int = 0);
        void openPassages();
        void openPassage(Room*);
        void closePassage(Room*);
        bool isFlooded();
};

#endif 
