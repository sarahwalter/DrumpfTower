/*********************************************************************
** Program Filename: Trump.cpp
** Author: Sarah Walter
** Date: August 6, 2016
** Description: This is the implementation file for the Trump (player) class.
*********************************************************************/

#include "Trump.h"

Trump::Trump()
{
	votes.clear();
}

Trump::~Trump()
{
	//dtor
}


/*********************************************************************
** Function: void Trump::move()
** Description: Move the player based on user input.
** Parameter: User input
*********************************************************************/
void Trump::move()
{
	Room* newLocation = getLocation()->getExit();

	if (!newLocation->isFlooded())
		setLocation(newLocation);
	else
		std::cout << "You can't move there. It's flooded!" << std::endl;
}


/* Get location of player */
Room* Trump::getLocation()
{
	return location;
}


/* Set location of player */
void Trump::setLocation(Room* room)
{
	location = room;
}


/*********************************************************************
** Function: bool Trump::addVotes(std::string room)
** Description: Add votes found to Trump's briefcase.
** Parameter: Votes added (stored based on name of location discovered)
*********************************************************************/
bool Trump::addVotes(std::string room)
{
	bool found = false;
	for (unsigned i = 0; i < votes.size(); i++)
	{
		if (votes[i] == room)
		{
			found = true;
			return false;
		}
	}

	if (!found)
		votes.push_back(room);

	return true;
}


/*********************************************************************
** Function: int Trump::readVotes()
** Description: Tell the user what votes they do/don't have
*********************************************************************/
int Trump::readVotes()
{
	if (votes.empty())
		std::cout << "You currently don't have any votes!" << std::endl;
	else
	{
		std::cout << "You currently have votes from the: ";
		for (unsigned i = 0; i < votes.size(); i++)
		{
			std::cout << votes[i];
			if (i == (votes.size() - 1))
				std::cout << ".";
			else
				std::cout << ", ";
		}

		std::cout << std::endl << std::endl;
	}

	return (int)votes.size();
}


/*********************************************************************
** Function: int Trump::countVotes()
** Description: Count the number of votes to track progress.
*********************************************************************/
int Trump::countVotes()
{
    return (int)votes.size();
}
