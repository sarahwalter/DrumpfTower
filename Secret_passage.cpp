/*********************************************************************
** Program Filename: Secret_passage.cpp
** Author: Sarah Walter
** Date: August 6, 2016
** Description: This is the implementation file for the Secret_passage class.
*********************************************************************/

#include "Secret_passage.h"

Secret_passage::Secret_passage()
{
    name = "Secret passage";
}

Secret_passage::~Secret_passage()
{
    //dtor
}

int Secret_passage::interact()
{
    std::cout << "Nothing but vents and air ducts here. You better get out of here as soon as possible. There might be some bad gasses in here..." << std::endl;
    return 5;
}
