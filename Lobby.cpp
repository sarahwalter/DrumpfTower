/*********************************************************************
** Program Filename: Lobby.cpp
** Author: Sarah Walter
** Date: August 6, 2016
** Description: This is the implementation file for the Lobby class.
*********************************************************************/

#include "Lobby.h"

Lobby::Lobby()
{
    name = "Lobby";
}

Lobby::~Lobby()
{
    //dtor
}


/*********************************************************************
** Function: int Lobby::interact()
** Description: Handles interaction with the doorman. User can decide if
** they want to bribe him for a hint or not.
** Parameters: User (char) input
*********************************************************************/
int Lobby::interact()
{
    char ch;
    // std::cout << "Interact Lobby" << std::endl; for debugging

    std::cout << "You see a doorman. He looks like he knows something. Do you want to talk to him (Y/N)?" << std::endl;
    std::cin >> ch;

    if(ch == 'Y' || ch == 'y')
    {
        int pick;
        std::cout << "You have decided to approach the doorman." << std::endl << std::endl;
        std::cout << "- I can help you with the election, but I want to a place in your cabinet afterwards, do you accept?" << std::endl;

        do
        {
            std::cout << "1. OK, I accept" << std::endl;
            std::cout << "2. Nah, I'll manage myself" << std::endl;
            std::cin >> pick;
        } while(pick < 1 || pick > 2);

        if(pick == 1)
            return 1;
    }

    return 0;
}
