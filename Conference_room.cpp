/*********************************************************************
** Program Filename: Conference_room.cpp
** Author: Sarah Walter
** Date: August 6, 2016
** Description: This is the implementation file for the Conference_room class.
*********************************************************************/

#include "Conference_room.h"

Conference_room::Conference_room()
{
    name = "Conference room";
}

Conference_room::~Conference_room()
{
    //dtor
}


/*********************************************************************
** Function: int Conference_room::interact()
** Description: Gives the interaction options to the player for the conference room.
** Parameters: User (int) input
*********************************************************************/
int Conference_room::interact()
{
    int pick, ret;

    // std::cout << "Interact CR" << std::endl; //for debugging
    std::cout << "You look around the Conference room." << std::endl;

    do
    {
        std::cout << "What do you approach?" << std::endl;
        std::cout << "1. Statue of George Washington" << std::endl;
        std::cout << "2. Tanning booth" << std::endl;
        std::cout << "3. Painting of Mexico" << std::endl;
        std::cin >> pick;
    }while(pick < 1 || pick > 3);

    switch(pick)
    {
    case 1:
        std::cout << "You approach the statue of George, and notice a small door behind it. You found a passage to the Penthouse!" << std::endl;
        ret = 3;
        break;
    case 2:
        std::cout << "You approach the tanning booth. You get a sweet spray tan! Now you look beautiful! No votes though..." << std::endl;
        ret = 5;
        break;
    case 3:
        std::cout << "You angrily tear the painting of Mexico off of the wall! You found the votes!" << std::endl;
        ret = 2;
        break;
    }

    return ret;
}
