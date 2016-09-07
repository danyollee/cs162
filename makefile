a4.exe: main.o bats.o event.o gold.o pit.o room.o wumpus.o player.o cave.o
	g++ main.o bats.o event.o gold.o pit.o room.o wumpus.o player.o cave.o -o a4.exe
main:
	g++ -c main.cpp
bats:
	g++ -c bats.cpp
event:
	g++ -c event.cpp
gold:
	g++ -c gold.cpp
pit:
	g++ -c pit.cpp
room:
	g++ -c room.cpp
wumpus:
	g++ -c wumpus.cpp
player:
	g++ -c player.cpp
cave:
	g++ -c cave.cpp
clean:
	rm -f *.o *.out *.exe
	clear
