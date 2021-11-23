#include <iostream>
#include <iomanip>
#include <unistd.h>
#include "start.hpp"
#include "main_menu.hpp"
#include "input.hpp"
#include "users.hpp"
#include "about.hpp"

int applei, applej; //apples coordinates
int len; //snake's length 
char pressed = 'd'; //snake's hand direction
int count, timer; //count and time for game

void login(const int row, const int col) {
    system("clear");
    gotoxy(row, col/2-16); std::cout << "⇾ For returning main menu press" << "\033[1m" << "\033[32m" << " Esc " << "\033[0m" << "⇽" << std::endl;
    gotoxy(row/2, col/2-14); std::cout << "👥 Do you have an account ? y/n" << std::endl;

    cbreak();
    while(true) {
        const int key = keypress();
        if(key == 121) { //y in ASCII
            system("clear");
            std::string name;
            normal();
            gotoxy(row/2, col/2-22); std::cout << "Please type your username for identification: ";
            std::cin >> name;
            system("clear");
            bool isLogged = false;
            for(int i = 0; i < usersCount; ++i) {
                if(name == names[i]) {
                    isLogged = true;
                    gotoxy(row/2, col/2-18-name.length()/2); 
                    std::cout << "Okey " << name << ", now you can press " << "\033[1m" << "\033[32m" << "s" << "\033[0m" << " to start a game." << std::endl;
                    break;
                }
            } 
            if(!isLogged) {
                gotoxy(row/2, col/2-12); std::cout << "You don't have an account." << std::endl;
                gotoxy(row/2+1, col/2-20); std::cout << "Please type your username for registration: ";
                normal();
                std::string newName;
                std::cin >> newName;
                system("clear");
                gotoxy(row/2, col/2-18-newName.length()/2);     
                std::cout << "Okey " << newName << ", now you can press " << "\033[1m" << "\033[32m" << "s" << "\033[0m" << " to start a game." << std::endl;
            }
            cbreak();
            while(true) {
                const int second_key = keypress();
                if(second_key == 's') {
                    count = 0; //make count default
                    game_logic(row, col);
                }
            }
            break;
        } else if (key == 110) { //n in ASCII
            system("clear");
            gotoxy(row/2+1, col/2-20); std::cout << "Please type your username for registration: ";
            normal();
            std::string newName;
            std::cin >> newName;
            system("clear");
            gotoxy(row/2, col/2-18-newName.length()/2);     
            std::cout << "Okey " << newName << ", now you can press " << "\033[1m" << "\033[32m" << "s" << "\033[0m" << " to start a game." << std::endl;
            cbreak();
            while(true) {
                const int second_key = keypress();
                if(second_key == 's') {
                    count = 0; //make count default
                    game_logic(row, col);
                }
            }
            
            break;
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void put_snake(std::string board[][20], int currentSnake[]) {
	board[currentSnake[0]][currentSnake[1]] = "◉";
	for (int snake = 2; snake < len - 1; snake+=2) {
		int i = currentSnake[snake];
		int j = currentSnake[snake + 1];
		board[i][j] = "▢";
	}
}

void snake_body(int currentHead[], int currentTail[], int currentSnake[], std::string board[][20], const int size) {
	len = 0;
	create_board(board, size);
	for (int i = currentHead[1]; i >= currentTail[1]; --i) {
		currentSnake[len++] = currentHead[0];
		currentSnake[len++] = i;
	}	
	put_snake(board, currentSnake);
}

void random_apple_coordinates(std::string board[][20], const int size) {
	do {
		applei = 1 + rand() % (size - 2);
		applej = 1 + rand() % (size - 2);
	} while (board[applei][applej] == "▢" || board[applei][applej] == "◉");
}

void create_board(std::string board[][20], const int size) {
	for (int i = 0; i < size; ++i) {
		for(int j = 0; j < size; ++j) {
			if(i == 0 || i == size - 1 || j == 0 || j == size - 1) {
				board[i][j] = "▩";
			} else if(i == applei && j == applej) {
				board[i][j] = "✽";
            } else {
                board[i][j] = " ";
            }
		}
	}
}

void print_board(std::string board[][20], const int size, const int row, const int col) {	
    system("clear");
    gotoxy(row, col/2-16); std::cout << "⇾ For returning main menu press" << "\033[1m" << "\033[32m" << " Esc " << "\033[0m" << "⇽" << std::endl;
    gotoxy(row-3, col/3); std::cout << "Count: " << count;
    gotoxy(row-3, 2*col/3); std::cout << "Time: "; //<< timer;

	for (int i = 0; i < size; ++i) {
        gotoxy(row/4+i, col/2-10-7);
		for (int j = 0; j < size; ++j) {
			std::cout << board[i][j] << " "; 
		}
	}
    std::cout << std::endl;
}

void press(std::string board[][20], const int size, int currentHead[], int currentTail[], int currentSnake[], const int row, const int col) {
    system("clear");
	bool isApple = false;

	if (board[currentHead[0]][currentHead[1]] == "▩" || board[currentHead[0]][currentHead[1]] == "▢") {
		game_over(row, col);
	} else {
		if (board[currentHead[0]][currentHead[1]] == "✽") {
            count++; //upgrade count
			board[applei][applej] = " ";
			isApple = true;
			random_apple_coordinates(board, size);
		}
		create_board(board, size);
		if (isApple) {
			currentSnake[len++] = currentTail[0];
			currentSnake[len++] = currentTail[1];
		}
		for (int i = len - 1; i >= 3; i-=2) {
			currentSnake[i] = currentSnake[i-2];
			currentSnake[i-1] = currentSnake[i-3];
		}
		currentSnake[0] = currentHead[0];
		currentSnake[1] = currentHead[1];
		put_snake(board, currentSnake);
	}
    print_board(board, size, row, col);
}

void game_over(const int row, const int col) {
	system("clear");
    std::cout << "\033[32m" << "\033[1m";
	gotoxy(row/4, col/2-28); std::cout << "  ____    _    __  __ _____    _____     _______ ____  _ ";
    gotoxy(row/4+1, col/2-28); std::cout << " / ___|  / \\  |  \\/  | ____|  / _ \\ \\   / / ____|  _ \\| |";
	gotoxy(row/4+2, col/2-28); std::cout << "| |  _  / _ \\ | |\\/| |  _|   | | | \\ \\ / /|  _| | |_) | |";
    gotoxy(row/4+3, col/2-28); std::cout << "| |_| |/ ___ \\| |  | | |___  | |_| |\\ V / | |___|  _ <|_|";
    gotoxy(row/4+4, col/2-28); std::cout << " \\____/_/   \\_\\_|  |_|_____|  \\___/  \\_/  |_____|_| \\_(_)" << "\033[0m" << std::endl;
	sleep(5);
	system("clear");
	menu(row, col);
}

void game_logic(const int row, const int col) {
    //starting coordinates
    const int size = 20;
    std::string board[size][size];
	const int startX = size / 4;
	const int startY = size / 4;
	const int length = 3;
	int currentHead[2] = {startX, startY}; //head current coordinates initialization with first coordinates
	int currentTail[2] = {startX, startY - length + 1}; //tail coordinates
	int currentSnake[2*size*size];  //array for snake body (x, y) coordinates, at first snake head coordinates

    //generate random apples
    random_apple_coordinates(board, size);
    
    //creating snake board
    create_board(board, size);

    //creating snake body
	snake_body(currentHead, currentTail, currentSnake, board, size);

    //printing snake board
    print_board(board, size, row, col);
  
	cbreak();
	while (true) {
        usleep(200000);
		const int key = keypress();

		if (key == 'a' || key == 'A') { 
			if (pressed == 'w' || pressed == 's') {
				pressed = 'a';
	            currentHead[1]--;
				press(board, size, currentHead, currentTail, currentSnake, row, col); 
			} continue;
		} else if (key == 'd' || key == 'D') {
			if (pressed == 'w' || pressed == 's') {
				pressed = 'd';
	            currentHead[1]++;
				press(board, size, currentHead, currentTail, currentSnake, row, col);
			} continue;
		} else if (key == 'w' || key == 'W') {
			if (pressed == 'd' || pressed == 'a') {
				pressed = 'w';
	            currentHead[0]--;
				press(board, size, currentHead, currentTail, currentSnake, row, col);
			} continue;
		} else if (key == 's' || key == 'S') { 
			if (pressed == 'd' || pressed == 'a') {
				pressed = 's';
	            currentHead[0]++;	
				press(board, size, currentHead, currentTail, currentSnake, row, col);
			} continue;
        } else if (key == 27) { //Esc in ASCII
            menu(row, col);
            return;
        }
		
        //always move in current direction
		switch (pressed) {
		case 'd' :	
	        currentHead[1] ++;
			press(board, size, currentHead, currentTail, currentSnake, row, col);
			break;
		case 'a' :
	        currentHead[1] --;
			press(board, size, currentHead, currentTail, currentSnake, row, col);
			break;
		case 'w' : 
	        currentHead[0]--;
			press(board, size, currentHead, currentTail, currentSnake, row, col);
			break;
		case 's' :  
	        currentHead[0]++;	
			press(board, size, currentHead, currentTail, currentSnake, row, col);
			break;
		} 
	}

    exit_to_main_menu(row, col);    
}

void game(const int row, const int col) {
    login(row, col);

    exit_to_main_menu(row, col);
}
