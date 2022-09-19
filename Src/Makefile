all: build

build:	about.o input.o main_menu.o settings.o start.o users.o main.o
	g++ -o build about.cpp input.cpp main.cpp main_menu.cpp settings.cpp start.cpp users.cpp

about.o: about.cpp
	g++ -c about.cpp

input.o: input.cpp
	g++ -c input.cpp

main_menu.o: main_menu.cpp
	g++ -c main_menu.cpp

settings.o: settings.cpp
	g++ -c settings.cpp

start.o: start.cpp
	g++ -c start.cpp

users.o: users.cpp
	g++ -c users.cpp

main.o: main.cpp
	g++ -c main.cpp

clean: 
	rm *.o build
