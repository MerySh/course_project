#include <iomanip>
#include <iostream>
#include "../Include/about.hpp"
#include "../Include/input.hpp"
#include "../Include/main_menu.hpp"

void exit_to_main_menu(const int row, const int col) {
    const int esc = 27; //Esc in ASCII
    cbreak();
    while(true) {
        const int key = keypress();
        if(key == esc) {
            menu(row, col);
        }
    }
}

void about_game(const int row, const int col) {
    system("clear");
    std::cout << "\033[1m"  << "\033[32m" << std::endl; //32 is green color id
    gotoxy(row/4, col/2-15); std::cout << " ____  _   _    _    _  _______";
    gotoxy(row/4+1, col/2-15); std::cout << "/ ___|| \\ | |  / \\  | |/ / ____|";
    gotoxy(row/4+2, col/2-15); std::cout << "\\___ \\|  \\| | / _ \\ | ' /|  _|";
    gotoxy(row/4+3, col/2-15); std::cout << " ___) | |\\  |/ ___ \\| . \\| |___";
    gotoxy(row/4+4, col/2-15); std::cout << "|____/|_| \\_/_/   \\_\\_|\\_\\_____|" << "\033[0m";
		
    gotoxy(row/4+7, col/2-47); std::cout << "Snake is a video game that originated during the late 1970s in arcades becoming something of a";
    gotoxy(row/4+8, col/2-47); std::cout << "classic. It became the standard pre-loaded game on Nokia phones in 1998. The player controls a";
    gotoxy(row/4+9, col/2-45); std::cout << "long, thin creature, resembling a snake, which roams around on a bordered plane, picking up ";
    gotoxy(row/4+10, col/2-46); std::cout << "food (or some other item), trying  to avoid hitting its own tail or the edges of the playing ";
    gotoxy(row/4+11, col/2-43); std::cout << "area. Each time the snake eats a piece of food, its tail grows longer, making the game ";
    gotoxy(row/4+12, col/2-45); std::cout << "increasingly difficult. The user controls the direction of the snake's head (up down, left, ";
    gotoxy(row/4+13, col/2-20); std::cout << "or right), and the snake's body follows.";
	gotoxy(row/4+15, col/2-27); std::cout << "\033[32m" << "‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗" << "\033[0m";
    gotoxy(row/4+17, col/2-3); std::cout << "🐍 🐍 🐍";

    gotoxy(row, col/2-16); std::cout << "⇾ For returning main menu press" << "\033[1m" << "\033[32m" << " Esc " << "\033[0m" << "⇽" << std::endl;
    exit_to_main_menu(row, col);
}
