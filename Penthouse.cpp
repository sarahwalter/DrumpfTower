/*********************************************************************
** Program Filename: Penthouse.cpp
** Author: Sarah Walter
** Date: August 6, 2016
** Description: This is the implementation file for the Penthouse class.
*********************************************************************/

#include "Penthouse.h"

Penthouse::Penthouse()
{
    name = "Penthouse";
}

Penthouse::~Penthouse()
{
    //dtor
}

int Penthouse::interact()
{
    // std::cout << "Interact P" << std::endl; for debugging
    std::cout << "You look around the Penthouse... You've got this election in the bag!" << std::endl;
    std::cout << "Nothing left to do but count your votes... Congratulations!" << std::endl;

    return 3;
}
