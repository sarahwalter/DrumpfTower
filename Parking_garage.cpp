/*********************************************************************
** Program Filename: Parking_garage.cpp
** Author: Sarah Walter
** Date: August 6, 2016
** Description: This is the implementation file for the Parking_garage class.
*********************************************************************/

#include "Parking_garage.h"

Parking_garage::Parking_garage()
{
    name = "Parking garage";
}

Parking_garage::~Parking_garage()
{
    //dtor
}


/*********************************************************************
** Function: int Parking_garage::interact()
** Description: Handles interaction in the parking garage. If the user
** interacts with the limo, they fall asleep and lose the game!
** Parameters: User (int) input
*********************************************************************/
int Parking_garage::interact()
{
    int pick, ret;
    // std::cout << "Interact Parking Garage" << std::endl << std::endl; for debugging
    std::cout << "You look around the Parking Garage." << std::endl;

    do
    {
        std::cout << "What do you approach?" << std::endl;
        std::cout << "1. White van" << std::endl;
        std::cout << "2. Limo" << std::endl;
        std::cout << "3. Portrait of Hillary Clinton" << std::endl;
        std::cin >> pick;
    }while(pick < 1 || pick > 3);

    switch(pick)
    {
    case 1:
        std::cout << "You approach and open the doors to the white van, and find some votes! Congrats!" << std::endl;
        ret = 2;
        break;
    case 2:
        std::cout << "You approach and open the limo. Hillary Clinton is sitting inside! She shoots you with horse tranquillizer and you fall asleep. "
        << "Looks like no election win for you this year..." << std::endl;
        ret = 4;
        break;
    case 3:
        std::cout << "You angrily tear the portrait of Hillary Clinton from the wall. You have discovered a secret passage!" << std::endl;
        return 3;
    }

    return ret;
}
