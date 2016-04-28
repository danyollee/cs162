triangle.exe: driver.o triangle.o isosceles.o
	g++ driver.o triangle.o isosceles.o -o triangle.exe
driver:
	g++ -c driver.cpp
triangle:
	g++ -c triangle.cpp
isosceles:
	g++ -c isosceles.cpp
clean:
	rm -f *.o *.out *.exe
	clear