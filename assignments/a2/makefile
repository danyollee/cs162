a2.exe: driver.o game.o deck.o hand.o player.o dealer.o
	g++ driver.o game.o deck.o hand.o player.o dealer.o -o a2.exe
driver:
	g++ -c driver.cpp
game:
	g++ -c game.cpp 
deck:
	g++ -c deck.cpp
hand:
	g++ -c hand.cpp
player:
	g++ -c player.cpp
dealer:
	g++ -c dealer.cpp
clean:
	rm -f *.o *.out *.exe
	clear