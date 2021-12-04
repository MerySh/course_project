#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "main_menu.hpp"
#include "input.hpp"
#include "about.hpp"
#include "users.hpp"
#include "start.hpp"
#include "settings.hpp"

bool started = false;

void menu(const int row, const int col) {
	system("clear"); // clearing console	
	const int main_menu_size = 5; // fixed size for main menu
    std::string main_menu[main_menu_size] = {"Start", "Setting", "Users", "About", "Out"};
	print_menu(main_menu, main_menu_size, 0, row, col); // printing main menu

    // main menu's functionality while pressing any letter in keyboard
	int target = 0; // menu coordinate
    const int enter = 10; // Enter in ASCII
	cbreak(); 
	while (true) {
		const int key = keypress();
		switch (key) {
		case 'w' : case 'W' :
            system("clear");
            target = (target == 0) ? main_menu_size - 1 : target - 1;
			print_menu(main_menu, main_menu_size, target, row, col);
			break;
		case 's' : case 'S' : 
            system("clear");
            target = (target == main_menu_size - 1) ? 0 : target + 1;
			print_menu(main_menu, main_menu_size, target, row, col);
			break;
		case enter : 
            system("clear");
            menu_controller(target, row, col);
			break;
		}
	}
}

void print_with_color(int x, int space, int i, std::string main_menu[]) {
    std::cout << "\033[1m" << "\033[32m";
    gotoxy(x+3*i, space-5); std::cout << "╔═════════╗";
    gotoxy(x+3*i+1, space-5); std::cout << "║"; 
    gotoxy(x+3*i+1, space - 4 + (11-main_menu[i].length()-2)/2); std::cout << main_menu[i];
    gotoxy(x+3*i+1, space - 4 + (11-main_menu[i].length()-2)/2 + main_menu[i].length() + (11-main_menu[i].length()-2)/2); std::cout << "║";
    gotoxy(x+3*i+2, space-5); std::cout << "╚═════════╝" << "\033[0m" << std::endl;
}

void only_print(int x, int space, int i, std::string main_menu[]) {
    gotoxy(x+3*i, space-5); std::cout << "╔═════════╗";
    gotoxy(x+3*i+1, space-5); std::cout << "║"; 
    gotoxy(x+3*i+1, space - 4 + (11-main_menu[i].length()-2)/2); std::cout << main_menu[i];
    gotoxy(x+3*i+1, space - 4 + (11-main_menu[i].length()-2)/2 + main_menu[i].length() + (11-main_menu[i].length()-2)/2); std::cout << "║";
    gotoxy(x+3*i+2, space-5); std::cout << "╚═════════╝" << std::endl;
}

void print_menu(std::string main_menu[], const int main_menu_size, int target, const int row, const int col) {	
	for(int i = 0; i < main_menu_size; ++i) {
        switch(i) {
            case 0 :
			    if (i == target) {
				    print_with_color(row/3, col/2, i, main_menu);
			    } else {
				    only_print(row/3, col/2, i, main_menu);
			    }
                break;
            case 1 : 
                if (i == target) {
				    print_with_color(row/3, col/2, i, main_menu);
			    } else {
				    only_print(row/3, col/2, i, main_menu);
			    }
                break;
            case 2 :
                if (i == target) {
				    print_with_color(row/3, col/2, i, main_menu);
			    } else {
				    only_print(row/3, col/2, i, main_menu);
			    }
                break;
            case 3 :
                if (i == target) {
				    print_with_color(row/3, col/2, i, main_menu);
			    } else {
				    only_print(row/3, col/2, i, main_menu);
			    }
                break;
            case 4 :
                if (i == target) {
				    print_with_color(row/3, col/2, i, main_menu);
			    } else {
				    only_print(row/3, col/2, i, main_menu);
			    }
                break;
		}
    }
}

void menu_controller(int target, const int row, const int col) {
	cbreak();
	switch(target) {
	case 0 :
		game(row, col, &started);
		break;
	case 1 :
        settings(row, col);
        break;
    case 2 :
        print_users(row, col);
        break;
    case 3 :
        about_game(row, col);
        break;
    case 4 : //end of the game
		system("clear");	
        normal();
        exit(0);
        break;
    }
}
