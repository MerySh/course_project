#include <iostream>
#include <iomanip>
#include "main_menu.hpp"
#include "input.hpp"
#include "about.hpp"
#include "users.hpp"
#include "start.hpp"

void menu(const int row, const int col) {
	system("clear"); // clearing console	
	const int main_menu_size = 5; // fixed size for main menu
	const char* main_menu[main_menu_size] = {"Start", "Records", "Users", "About", "Out"};
	print_menu(main_menu, main_menu_size, main_menu_size, row, col); // printing main menu

    // main menu's functionality while pressing any letter in keyboard
	int target = main_menu_size - 1; // menu coordinate
    const int enter = 10; // Enter in ASCII
	cbreak(); 
	while (true) {
		const int key = keypress();
		switch (key) {
		case 'w' : case 'W' :
			system("clear");
			if (target == 0) {
				target = main_menu_size - 1;
			} else {
				target--;
			}
			print_menu(main_menu, main_menu_size, target, row, col);
			break;
		case 's' : case 'S' : 
			system("clear");
			if (target  == main_menu_size - 1) {
				target = 0;
			} else {
				target++;
			}
			print_menu(main_menu, main_menu_size, target, row, col);
			break;
		case enter : 
			system("clear");
            menu_controller(target, row, col);
			break;
		}
	}
}

void print_with_color(int x, int space, int i, const char** main_menu) {
    gotoxy(x+i, space);
    std::cout << "\033[1m" << "\033[32m" << main_menu[i] << "\033[0m" << std::endl; //green color
}

void only_print(int x, int space, int i, const char** main_menu) {
    gotoxy(x+i, space);
    std::cout << main_menu[i] << std::endl;
}

void print_menu(const char** main_menu, const int main_menu_size, int target, const int row, const int col) {	
	//set menu to the center
    for(int i = 0; i < row/2 - main_menu_size + 1; ++i) {
        std::cout << std::endl;
    }

	for(int i = 0; i < main_menu_size; ++i) {
        switch(i) {
            case 0 :
			    if (i == target) {
				    print_with_color(row/2-1, col/2, i, main_menu);
			    } else {
				    only_print(row/2-1, col/2, i, main_menu);
			    }
                break;
            case 1 : 
                if (i == target) {
				    print_with_color(row/2-1, col/2-1, i, main_menu);
			    } else {
				    only_print(row/2-1, col/2-1, i, main_menu);
			    }
                break;
            case 2 :
                if (i == target) {
				    print_with_color(row/2-1, col/2, i, main_menu);
			    } else {
				    only_print(row/2-1, col/2, i, main_menu);
			    }
                break;
            case 3 :
                if (i == target) {
				    print_with_color(row/2-1, col/2, i, main_menu);
			    } else {
				    only_print(row/2-1, col/2, i, main_menu);
			    }
                break;
            case 4 :
                if (i == target) {
				    print_with_color(row/2-1, col/2+1, i, main_menu);
			    } else {
				    only_print(row/2-1, col/2+1, i, main_menu);
			    }
                break;
		}
    }
}

void menu_controller(int target, const int row, const int col) {
	cbreak();
	switch(target) {
	case 0 :
		game(row, col);
		break;
	case 1 :
        //records();
        break;
    case 2 :
        print_users(row, col);
        break;
    case 3 :
        about_game(row, col);
        break;
    case 4 : //end of the game
		system("clear");	
        std::abort();
        break;
    }
}
