#include <iostream>
#include <iomanip>
#include <unistd.h>
#include "start.hpp"
#include "main_menu.hpp"
#include "input.hpp"
#include "users.hpp"
#include "about.hpp"
#include "settings.hpp"

int applei, applej; //apples coordinates
int redApplei, redApplej; //red apples coordinates //not to eat
int len; //snake's length 
char pressed; //snake's hand direction
int count, timer; //count and time for game

void login(const int row, const int col) {
    system("clear");
    gotoxy(row, col/2-16); std::cout << "⇾ For returning main menu press" << "\033[1m" << "\033[32m" << " Esc " << "\033[0m" << "⇽" << std::endl;
    gotoxy(row/2, col/2-24); std::cout << "\033[1m" << "👥 𝔻 𝕠  𝕪 𝕠 𝕦  𝕙 𝕒 𝕧 𝕖  𝕒 𝕟  𝕒 𝕔 𝕔 𝕠 𝕦 𝕟 𝕥  ?  𝕪 / 𝕟" << "\033[0m" << std::endl;
        
    cbreak();
    while(true) {
        const int key = keypress();
            if(key == 121) { //y in ASCII
            system("clear");
            std::string name;
            normal();
            gotoxy(row/2, col/2-22); std::cout << "\033[1m" << "Please type your username for identification" << "\033[0m" << std::endl;
            
            gotoxy(row/2+2, col/2-10); std::cout << "╔═══════════════╗";
            gotoxy(row/2+3, col/2-10); std::cout << "║"; 
            gotoxy(row/2+3, col/2+6); std::cout << "║";
            gotoxy(row/2+4, col/2-10); std::cout << "╚═══════════════╝" << std::endl;

            gotoxy(row/2+3, col/2-8); std::cin >> name;
            system("clear");
            bool isLogged = false;
            for(int i = 0; i < usersCount; ++i) {
                if(name == names[i]) {
                    isLogged = true;
                    gotoxy(row/2, col/2-18-name.length()/2); 
                    std::cout << "\033[1m" << "Okey " << name << ", now you can press " << "\033[32m" << "s" << "\033[0m" << "\033[1m" << " to start a game." << "\033[0m" << std::endl;
                    break;
                }
            } 
            if(!isLogged) {
                gotoxy(row/2-1, col/2-12); std::cout << "\033[1m" << "You don't have an account." << std::endl;
                gotoxy(row/2, col/2-20); std::cout << "Please type your username for registration" << "\033[0m" << std::endl;
                gotoxy(row/2+2, col/2-8); std::cout << "╔═══════════════╗";
                gotoxy(row/2+3, col/2-8); std::cout << "║"; 
                gotoxy(row/2+3, col/2+8); std::cout << "║";
                gotoxy(row/2+4, col/2-8); std::cout << "╚═══════════════╝" << std::endl;
                normal();
                std::string newName;
                gotoxy(row/2+3, col/2-6); std::cin >> newName;
                names[usersCount++] = newName;
                system("clear");
                gotoxy(row/2, col/2-18-newName.length()/2);     
                std::cout << "\033[1m" << "Okey " << newName << ", now you can press " << "\033[1m" << "\033[32m" << "s" << "\033[0m" << "\033[1m" << " to start a game." << "\033[0m" << std::endl;
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
            gotoxy(row/2+1, col/2-20); std::cout << "\033[1m" << "Please type your username for registration" << "\033[0m";
            gotoxy(row/2+3, col/2-8); std::cout << "╔═══════════════╗";
            gotoxy(row/2+4, col/2-8); std::cout << "║"; 
            gotoxy(row/2+4, col/2+8); std::cout << "║";
            gotoxy(row/2+5, col/2-8); std::cout << "╚═══════════════╝" << std::endl;
            normal();
            std::string newName;
            gotoxy(row/2+4, col/2-6); std::cin >> newName;
            names[usersCount++] = newName; //adding new player in the array
            system("clear");
            gotoxy(row/2, col/2-18-newName.length()/2);     
            std::cout << "\033[1m" << "Okey " << newName << ", now you can press " << "\033[1m" << "\033[32m" << "s" << "\033[0m" << "\033[1m" << " to start a game." << "\033[0m" << std::endl;
            cbreak();
            while(true) {
                const int second_key = keypress();
                if(second_key == 's') {
                    count = 0; //make count default
                    game_logic(row, col);
                }
            }
            
            break;
        } else if (key == 27) { //Esc in ASCII
            menu(row, col);
            return;
        }

    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void put_snake(std::string board[][30], int currentSnake[]) {
	board[currentSnake[0]][currentSnake[1]] = "🐸";
	for (int snake = 2; snake < len - 1; snake+=2) {
		int i = currentSnake[snake];
		int j = currentSnake[snake + 1];
		board[i][j] = "☵"; //"▢";
	}
}

void snake_body(int currentHead[], int currentTail[], int currentSnake[], std::string board[][30], const int size) {
	len = 0;
	create_board(board, size);
	for (int i = currentHead[1]; i >= currentTail[1]; --i) {
		currentSnake[len++] = currentHead[0];
		currentSnake[len++] = i;
	}	
	put_snake(board, currentSnake);
}

void random_apple_coordinates(std::string board[][30], const int size) {
		applei = 1 + rand() % (size - 2);
		applej = 1 + rand() % (size - 2);
        if (board[applei][applej] == "☵" || board[applei][applej] == "🐸" || board[applei][applej] == "🍎") {
            random_apple_coordinates(board, size);  //recursia
        }
}

void random_red_apple_coordinates(std::string board[][30], const int size) {
		redApplei = 1 + rand() % (size - 2);
		redApplej = 1 + rand() % (size - 2);
        if (board[redApplei][redApplej] == "☵" || board[redApplei][redApplej] == "🐸" || board[redApplei][redApplej] == "🍏") {
            random_red_apple_coordinates(board, size);  //recursia
        }
}

void create_board(std::string board[][30], const int size) {
	for (int i = 0; i < size; ++i) {
		for(int j = 0; j < size; ++j) {
			if(i == 0 || i == size - 1 || j == 0 || j == size - 1) {
				board[i][j] = "▩";
			} else if(i == applei && j == applej) {
				board[i][j] = "🍏";  //"✽";
            } else if(i == redApplei && j == redApplej) {
                board[i][j] = "🍎";
            } else {
                board[i][j] = " ";
            }
		}
	}
}

void print_board(std::string board[][30], const int size, const int row, const int col) {	
    system("clear");
	for (int i = 0; i < size; ++i) {
        gotoxy(row/6+i, col/2-25);
		for (int j = 0; j < size; ++j) {
            if (board[i][j] == "☵") {
                std::cout << "\033[1m" << "\033[32m" << board[i][j] << " " << "\033[0m";
            } else if (board[i][j] == "🍏" || board[i][j] == "🐸" || board[i][j] == "🍎") {
                std::cout << board[i][j];
            } else {
			    std::cout << board[i][j] << " "; 
            }
		}
	}
    std::cout << "\033[0m" << std::endl;

    gotoxy(row/3, col-32); std::cout << "\033[1m" << "\033[32m" <<   "  🅆";
    gotoxy(row/3+1, col-32); std::cout << "🄰 🅂 🄳";
    gotoxy(row/3+4, col-40); std::cout << "▌▌" << "\033[0m" << "Press space to stop";
    gotoxy(row/3+6, col-40); std::cout << "\033[1m" << "\033[32m" << "▶ " << "\033[0m" << "Press any key to continue" << std::endl;

    gotoxy(row-3, col/3); std::cout << "Score: " << count;
    gotoxy(row-3, 2*col/3); std::cout << "Time: "; //<< timer;
    gotoxy(row, col/2-16); std::cout << "⇾ For returning main menu press" << "\033[1m" << "\033[32m" << " Esc " << "\033[0m" << "⇽" << std::endl;
}

void press(std::string board[][30], const int size, int currentHead[], int currentTail[], int currentSnake[], const int row, const int col) {
    system("clear");
	bool isApple = false;

	if (board[currentHead[0]][currentHead[1]] == "▩" || board[currentHead[0]][currentHead[1]] == "☵" || board[currentHead[0]][currentHead[1]] == "🍎") {
		game_over(row, col);
	} else {
		if (board[currentHead[0]][currentHead[1]] == "🍏") {
            count++; //upgrade count
			random_apple_coordinates(board, size);
            if (level > 1) {
                random_red_apple_coordinates(board, size);
            }
			board[applei][applej] = " ";
			isApple = true;
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

    gotoxy(row/4+8, col/2-8); std::cout << "Your score is " << count << std::endl;
    count = 0;
	sleep(2);
	system("clear");
	menu(row, col);
}

void game_logic(const int row, const int col) {
    //speed depending on the leve
    const int speeds[5] = {400000, 300000, 200000, 150000, 100000};

    //starting coordinates
    const int size = 30;
    std::string board[size][size];
	const int startX = size / 4;
	const int startY = size / 4;
	const int length = 3;
	int currentHead[2] = {startX, startY}; //head current coordinates initialization with first coordinates
	int currentTail[2] = {startX, startY - length + 1}; //tail coordinates
	int currentSnake[2*size*size];  //array for snake body (x, y) coordinates, at first snake head coordinates

    //generate random apples
    random_apple_coordinates(board, size);
    if (level > 1) {
        random_red_apple_coordinates(board, size);
    }
    
    //creating snake board
    create_board(board, size);

    //creating snake body
	snake_body(currentHead, currentTail, currentSnake, board, size);

    //printing snake board
    print_board(board, size, row, col);
  
    pressed = 'd';
	cbreak();
	while (true) {
        usleep(speeds[level-1]);
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
        } else if (key == 32) { //Space Bar in ASCII
            std::cin.get();
            continue;
        } else if (key == 27) { //Esc in ASCII
            count = 0;
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

void game(const int row, const int col, bool* started) {
    if (!(*started)) {
        *started = true;
        login(row, col);
    }

    game_logic(row, col);
    exit_to_main_menu(row, col);
}
