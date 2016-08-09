/*********************************************************************
** Program Filename: Dungeon.cpp
** Author: Sarah Walter
** Date: August 6, 2016
** Description: This is the implementation file for the Dungeon class.
*********************************************************************/

#include "Dungeon.h"

Dungeon::Dungeon()
{
    name = "Dungeon";
}

Dungeon::~Dungeon()
{
    //dtor
}


/*********************************************************************
** Function: int Dungeon::interact()
** Description: Handles user's interaction with items in the room.
** Parameters: User (int) input
*********************************************************************/
int Dungeon::interact()
{
    int pick;
    // std::cout << "Interact Dungeon" << std::endl << std::endl;  for debugging
    std::cout << "You look around the Dungeon." << std::endl;

    do
    {
        std::cout << "What do you approach?" << std::endl;
        std::cout << "1. Suit of armor" << std::endl;
        std::cout << "2. Bernie's rumpled, lipstick stained suit" << std::endl;
        std::cout << "3. Portrait of Vladimir Putin" << std::endl;
        std::cin >> pick;
    }while(pick < 1 || pick > 3);

    switch(pick)
    {
    case 1:
        std::cout << "You approached and opened up the suit of armor. Nothing but dust in there. You back away disappointed." << std::endl;
        break;
    case 2:
        std::cout << "You go through Bernie's suit and find some votes! Congrats!" << std::endl;
        return 2;
    case 3:
        std::cout << "You angrily tear the portrait of Putin off the wall. You have discovered a secret passage!" << std::endl;
        return 3;
    }

    return 0;
}
