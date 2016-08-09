/*********************************************************************
** Program Filename: Game.cpp
** Author: Sarah Walter
** Date: August 6, 2016
** Description: This is the implementation file for the Game class.
*********************************************************************/

#include "Game.h"


/* Constructor to create the game spaces and exits */
Game::Game()
{
    lobby = new Lobby;
    dungeon = new Dungeon;
    garage = new Parking_garage;
    secret_room = new Secret_room;
    office = new Office;
    conf_room = new Conference_room;
    penthouse = new Penthouse;
    secret_pass = new Secret_passage;

    trump = new Trump;

    lobby->setExit(dungeon, "Go to the dungeon");
    lobby->setExit(garage, "Go to the garage");
    lobby->setExit(conf_room, "Take the elevator to the conference room");
    lobby->setExit(office, "Take the elevator to the office");

    dungeon->setExit(lobby, "Go to the lobby");
    dungeon->setExit(conf_room, "Go up the spiral staircase to conference room");
    dungeon->setExit(garage, "Go to the garage");
    dungeon->setExit(secret_room, "Enter the secret room", false);

    garage->setExit(lobby, "Go to the lobby");
    garage->setExit(office, "Go up the garage stairs to the office");
    garage->setExit(dungeon, "Go to the dungeon");
    garage->setExit(secret_room, "Enter the secret room", false);

    secret_room->setExit(dungeon, "Go back to the dungeon");
    secret_room->setExit(garage, "Go back to the garage");

    office->setExit(garage, "Take the stairs down to garage");
    office->setExit(lobby, "Take the elevator to lobby");
    office->setExit(conf_room, "Go to the conference room");
    office->setExit(secret_pass, "Go trough the secret tunnel to the conference room", false);

    conf_room->setExit(lobby, "Take the elevator to lobby");
    conf_room->setExit(dungeon, "Go down the spiral staircase to the dungeon");
    conf_room->setExit(office, "Go into the office");
    conf_room->setExit(penthouse, "Enter the penthouse", false);

    secret_pass->setExit(conf_room, "Crawl to the conference room");

    penthouse->setExit(conf_room, "Go back to the conference room");

    trump->setLocation(lobby);

    displayTheme();
}


/* Destructor */
Game::~Game()
{
    delete lobby;
    delete dungeon;
    delete garage;
    delete secret_room;
    delete office;
    delete conf_room;
    delete penthouse;
    delete secret_pass;

    delete trump;
}


/*********************************************************************
 ** Function: void Game::displayTheme()
 ** Description: Prints the theme of the game to the console.
 ** Post-Conditions: Theme is displayed.
 *********************************************************************/
void Game::displayTheme()
{
    std::cout << "THEME: Donnie's Grand Adventure!" << std::endl << std::endl;
	std::cout << "Welcome to Drumpf Tower! The goal is to collect " << std::endl;
	std::cout << "fake votes that you (Donald) need to win the election. To " << std::endl;
	std::cout << "find out how to win the game, look for and interact with the doorman " << std::endl;
	std::cout << "here in the lobby. Once you get all the votes, make your way to " << std::endl;
	std::cout << "the Penthouse to use them and win the election! " << std::endl << std::endl;
}


/*********************************************************************
 ** Function: void Game::displayHint()
 ** Description: Tell TA how to win the game as well as how to access the
 ** secret (added) room feature.
 ** Pre-Conditions: User interacts with doorman
 ** Post-Condtions: Hint is displayed
 *********************************************************************/
void Game::displayHint()
{
    std::cout << "To win the game, start in the dungeon and collect the votes " << std::endl;
	std::cout << "from Bernie's suit. Behind the picture on the wall there is a secret " << std::endl;
	std::cout << "passage to a secret room. Once it is open, select move again to enter it. Get the votes by looking around the secret room. " << std::endl;
	std::cout << "Get the votes in the garage from the white van. Travel upstairs to the office and get the votes from the piggy bank. There " << std::endl;
	std::cout << "is a secret compartment behind the bookcase. If you interact with the computer " << std::endl;
	std::cout << "the room will flood and you will have to escape through the bookcase, you can't go " << std::endl;
	std::cout << "back to the office again. The votes in the office are behind the picture of Mexico. " << std::endl;
	std::cout << "After you have gotten all these votes, look behind George Washington's statue to " << std::endl;
	std::cout << "go to the Penthouse and win the game! " << std::endl << std::endl;
}


/*********************************************************************
 ** Function: void Game::displayMap()
 ** Description: Just for fun - this is the map of the game
 ** Pre-Conditions: User interacts with doorman
 ** Post-Condtions: Map is displayed
 *********************************************************************/
void Game::displayMap()
{
    std::cout << "                  DRUMPF TOWER MAP                     " << std::endl;
    std::cout << " |                 ____________                       | " << std::endl;
    std::cout << " |                |            |                      | " << std::endl;
    std::cout << " |                |  Penthouse |                      | " << std::endl;
    std::cout << " |                |____________|                      | " << std::endl;
    std::cout << " |     -----------             -----------            | " << std::endl;
    std::cout << " |     |          |-----------|Conference|   2nd      | " << std::endl;
    std::cout << " |     | Office   |           |   Room   |  floor     | " << std::endl;
    std::cout << " |     |          |-----------|          |            | " << std::endl;
    std::cout << " |      ----------             -----------            | " << std::endl;
    std::cout << " |                  -----------|                      | " << std::endl;
    std::cout << " |     -----------  | Secret   | -----------          | " << std::endl;
    std::cout << " |     |          | |  Room    |          |           | " << std::endl;
    std::cout << " |     | Parking  | |_________ | Dungeon  |   1st     | " << std::endl;
    std::cout << " |     | Garage   | |        | |          | floor     | " << std::endl;
    std::cout << " |      ----------- | Lobby  | |          |           | " << std::endl;
    std::cout << " |                  |________|  ----------            | " << std::endl;
    std::cout << " ------------------------------------------------------ " << std::endl;
    std::cout << "                                                        " << std::endl;

}


/*********************************************************************
 ** Function: void Game::play()
 ** Description: Run the game. Handle different scenarios during gameplay.
 ** Parameter: Integer input from user
 ** Pre-Conditions: User inputs their choice as the game progresses. 
 ** Post-Condtions: Game changes depending on user choices.
 *********************************************************************/
void Game::play()
{
    bool won = false;
    bool lost = false;
    double hours = 24;

    while(hours >= 0 && !won && !lost)
    {
        std::cout << "You have only " << hours << " hours before polls close" << std::endl;
        int choice = trump->getLocation()->choice();

        if(choice == 1)
        {
            int interact = trump->getLocation()->interact();

            switch(interact)
            {
            case 1:
                displayHint();

                std::cout << "And here is the map!" << std::endl;
                displayMap();
                break;
			/* Room returns 2 if votes found */	
            case 2:  
                if(trump->addVotes(trump->getLocation()->getName()))
                    std::cout << "You are one step closer to winning the election!" << std::endl;
                else
                    std::cout << "You already have those votes..." << std::endl;
                break;
			/* Penthouse handling */	
            case 3: 
                if(trump->getLocation()->getName() == "Conference room")
                {
                    std::cout << "Nice find, Donnie!" << std::endl;

                    if(trump->countVotes() == 5)
                    {
                        std::cout << "You skip happily into the penthouse!" << std::endl;
                        trump->setLocation(penthouse);
                        choice = 3;
                    }
                    else
                    {
                        std::cout << "You don't have all the votes...oops. You can't enter the Penthouse. You fall through the hole in the floor and land in the lobby." << std::endl;
                        trump->setLocation(lobby);
                    }
                }
                else
                    trump->getLocation()->openPassages();

                break;
            case 4:
                lost = true;
                break; 				/* Tranq'd by Hillary */
            case 5:
                break; 				/* Spray tan */
            case 6:  				/* Office floods */
                conf_room->closePassage(office);
                garage->closePassage(office);
                lobby->closePassage(office);
                office->openPassage(secret_pass);
                int x;

                std::cout << "Oh no! The room has started to flood and you are running out of air! What will you do?" << std::endl;
                std::cout << "1. Accept your fate" << std::endl;
                std::cout << "2. Climb the bookcase and look for a way out" << std::endl;
                std::cin >> x;

                if(x == 1)
                {
                    std::cout << "Rest in peace Donnie! You would have been a great president!" << std::endl;
                    lost = true;
                }
                else
                {
                    std::cout << std::endl << "While on the bookcase, you notice a small opening behind it! With one last breath, you escape! You are now in a ventilation tube." << std::endl;
                    std::cout << "You continue straight and manage to exit into conference room!" << std::endl;
                    trump->setLocation(secret_pass);
                }

                break;
            }

        } else if(choice == 2)
        {
            trump->move();				/* Countdown changes as he moves */
            hours -= 1.5; 				/* Lose 1.5 hours each move */
        }
        if(choice == 3)
        {
            int num_votes = trump->readVotes();

            if((num_votes == 5) && (trump->getLocation()->getName() == "Penthouse"))
                won = true;
        }
    }

    if(!won || lost)
    {
        std::cout << "Sorry, you didn't collect enough votes Mr. Trump, better luck in 4 years..." << std::endl << std::endl;
    }

    if(won)
        std::cout << "Congratulations, Mr. President! Looks like you win!" << std::endl;
}
