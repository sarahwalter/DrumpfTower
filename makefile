# Sarah Walter's makefile
# To use: 
# make all = Make software.
#
# make clean = Clean out built project files.

CC = g++
RM = rm
DEBUG = -g
CFLAGS = $(DEBUG) -std=c++0x
RMFLAGS = -rf 
PROGS = final
MAKEFLAGS = -k

	
all: $(PROGS)
	
final:
	$(CC) $(CFLAGS) Conference_room.cpp Dungeon.cpp Game.cpp Lobby.cpp main.cpp Office.cpp Parking_garage.cpp Penthouse.cpp Room.cpp Trump.cpp Secret_passage.cpp Secret_room.cpp -o final
		
clean:
	$(RM) $(RMFLAGS) *.a *.o $(PROGS)