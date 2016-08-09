#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "Room.h"
#include "Trump.h"
#include "Lobby.h"
#include "Dungeon.h"
#include "Parking_garage.h"
#include "Secret_room.h"
#include "Office.h"
#include "Conference_room.h"
#include "Penthouse.h"
#include "Secret_passage.h"

class Game
{
    public:
        Game();
        ~Game();

        void displayTheme();
        void displayHint();
        void displayMap();
        void play();
    protected:
    private:
        Trump* trump;
        Lobby* lobby;
        Dungeon* dungeon;
        Parking_garage* garage;
        Secret_room* secret_room;
        Office* office;
        Conference_room* conf_room;
        Penthouse* penthouse;
        Secret_passage* secret_pass;
};

#endif
