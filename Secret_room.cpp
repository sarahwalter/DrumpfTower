/*********************************************************************
** Program Filename: Secret_room.cpp
** Author: Sarah Walter
** Date: August 6, 2016
** Description: This is the implementation file for the Secret_room class.
*********************************************************************/

#include "Secret_room.h"

Secret_room::Secret_room()
{
	name = "Secret room";
}

Secret_room::~Secret_room()
{
	//dtor
}

int Secret_room::interact()
{
	// for debugging std::cout << "Interact SR" << std::endl;
	std::cout << "You found a secret room! The room contains only a table, and on it are votes. You pick them up. You are a lucky duck!" << std::endl << std::endl;

	return 2;
}
