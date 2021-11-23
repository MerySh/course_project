#include <iostream>
#include <iomanip>
#include <cstring>
#include "users.hpp"
#include "input.hpp"
#include "main_menu.hpp"
#include "about.hpp"

//array for users data 
std::string names[10] = {"Helen", "Edgar", "YuraBagoyan"};
int usersCount = 3;

void print_users(const int row, const int col) {
    system("clear");
    std::cout << "\033[1m" << "\033[32m" << std::endl; //32 is green color id
	gotoxy(3, col/2-14); std::cout << " _   _ ____  _____ ____  ____";
    gotoxy(4, col/2-14); std::cout << "| | | / ___|| ____|  _ \\/ ___|";
	gotoxy(5, col/2-14); std::cout << "| | | \\___ \\|  _| | |_) \\___ \\";
    gotoxy(6, col/2-14); std::cout << "| |_| |___) | |___|  _ < ___) |";
    gotoxy(7, col/2-14); std::cout << " \\___/|____/|_____|_| \\_\\____/" << "\033[0m";

    print_users_names(row, col);
    gotoxy(row, col/2-16); std::cout << "⇾ For returning main menu press" << "\033[1m" << "\033[32m" << " Esc " << "\033[0m" << "⇽" << std::endl;
    
    exit_to_main_menu(row, col);
}

void print_users_names(const int row, const int col) {
    for(int i = 0; i < usersCount; ++i) {
        gotoxy(10+i, col/2-5-names[i].length()/2);
        std::cout << "☆ User " << i << " ⤍  " << names[i];
    }
}
