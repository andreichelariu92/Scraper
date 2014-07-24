executabil:main.o car.o collection.o
	g++ -o executabil main.o car.o collection.o
main.o:main.cpp car.h collection.h
	g++ -c -g -Wall main.cpp
car.o:car.cpp car.h collection.h
	g++ -c -Wall -g car.cpp
collection.o:collection.cpp collection.h
	g++ -c -Wall -g collection.cpp
