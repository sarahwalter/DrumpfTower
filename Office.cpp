/*********************************************************************
** Program Filename: Office.cpp
** Author: Sarah Walter
** Date: August 6, 2016
** Description: This is the implementation file for the Office class.
*********************************************************************/

#include "Office.h"

Office::Office()
{
    name = "Office";
}

Office::~Office()
{
    //dtor
}


/*********************************************************************
** Function: int Office::interact()
** Description: Gives the interaction options to the player. If the player
** interacts with the computer, the delete room scenario unfolds.
** Parameters: User (int) input
*********************************************************************/
int Office::interact()
{
    int pick, ret = 0;

    /* std::cout << "Interact O" << std::endl; debugging */
    std::cout << "You look around the office." << std::endl;

    do
    {
        std::cout << "What do you approach?" << std::endl;
        std::cout << "1. Computer" << std::endl;
        std::cout << "2. Piggy bank" << std::endl;
        std::cout << "3. Bookcase" << std::endl;
        std::cin >> pick;
    }while(pick < 1 || pick > 3);

    switch(pick)
    {
    case 1:
        std::cout << "You look at the computer and see a message from Russian hackers. They contain Hillary's Caesar-ciphered emails!" << std::endl;
		std::cout << "You start to unencrypt them, but the office starts flooding!" << std::endl;
        std::cout << "The water is coming so fast, you only have one move before you drown! Choose wisely..." << std::endl;
        ret = 6;
        flooded = true;
        break;
    case 2:
        std::cout << "You approach the piggy bank. You smash it, and you discover votes hidden inside it. Bravo!" << std::endl;
        ret = 2;
        break;
    case 3:
        std::cout << "What a beautiful bookcase! You are drawn to one ancient looking book. You try to get it out, but the bookcase starts shaking...";
        std::cout  << std::endl << "The bookcase rotates and opens the secret passage to the conference room!" << std::endl;
        ret = 3;
        break;
    }

    return ret;
}
