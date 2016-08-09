/*********************************************************************
** Program Filename: Room.cpp
** Author: Sarah Walter
** Date: August 6, 2016
** Description: This is the implementation file for the Room class.
*********************************************************************/

#include "Room.h"

Room::Room()
{
	exits.clear();
	flooded = false;
}

Room::~Room()
{
	//dtor
}

std::string Room::getName()
{
	return name;
}


/*********************************************************************
** Function: int Room::choice()
** Description: Tells the user which room they are in, and prompts them
** for their next move. They decide between searching the room, moving,
** or counting their votes.
*********************************************************************/
int Room::choice()
{
	int choice;

	std::cout << "You are in the " << name << std::endl;
	std::cout << "What do you want to do?" << std::endl;

	do
	{
		std::cout << "1. Look around and search the room" << std::endl;
		std::cout << "2. Move to another room" << std::endl;
		std::cout << "3. Count the votes in your briefcase" << std::endl;
		std::cin >> choice;
		std::cout << std::endl;
	} while (choice < 1 || choice > 3);

	return choice;
}


/*********************************************************************
** Function: Room* Room::getExit(int numExit)
** Description: Displays the movement options to the user if they decide
** to exit the room.
** Pre-Conditions: User has chosen to move from the room
*********************************************************************/
Room* Room::getExit(int numExit)
{
	char choice = ' ';
	//std::cout << "You are in " << name << "." << std::endl;

	std::cout << std::endl << "Where would you like to go? " << std::endl;

	/* Let user choose */
	if (numExit == 0)
	{
		for (int i = 0; i < static_cast<int>(exits.size()); i++)
		{
			/* Show open exits */
			if (exits[i].open)
			{
				std::cout << i + 1 << ") " << exits[i].descr << std::endl;
			}
		}


		while (numExit < 1 || numExit > static_cast<int>(exits.size()))
		{
			std::cout << "Enter a number: " << std::endl;
			std::cin >> choice;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			numExit = static_cast<int>(choice)-static_cast<int>('0');
		}
	}

	return exits[numExit - 1].dest;
}


/*********************************************************************
** Function: void Room::setExit(Room* s1, std::string s2, bool o)
** Description: Open all exits (pointers) from the room. Already open exits
** won't be affected.
*********************************************************************/
void Room::setExit(Room* s1, std::string s2, bool o)
{
	exits.push_back(Exit(s1, s2, o));
}

void Room::openPassages()
{
	for (unsigned i = 0; i < exits.size(); i++)
		exits[i].open = true;
}


/*********************************************************************
** Function: void Room::openPassage(Room* r)
** Description: Opens door to a specific room. 
*********************************************************************/
void Room::openPassage(Room* r)
{
	std::string name_to_open = r->getName();

	for (unsigned i = 0; i < exits.size(); i++)
	{
		if (name_to_open == exits[i].dest->getName())
			exits[i].open = true;
	}
}


/*********************************************************************
** Function: void Room::closePassage(Room* r)
** Description: Closes passages leading to the office when it floods.
*********************************************************************/
void Room::closePassage(Room* r)
{
	std::string name_to_close = r->getName();

	for (unsigned i = 0; i < exits.size(); i++)
	{
		if (name_to_close == exits[i].dest->getName())
			exits[i].open = false;
	}
}


/*********************************************************************
** Function: bool Room::isFlooded()
** Description: Check to see if office is flooded so we know to close it.
*********************************************************************/
bool Room::isFlooded()
{
	return flooded;
}
