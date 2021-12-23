#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include "../Include/users.hpp"
#include "../Include/input.hpp"
#include "../Include/main_menu.hpp"
#include "../Include/about.hpp"

//array for users data
std::string names[5] = {"Helen", "Edgar", "YurBagoyan"};
int usersCount = 3;

void print_users(const int row, const int col) {
    int target = 0; // targeted menu item
    bool toDelete = false; //is targeted X in menu
    
    print_users_word(row, col);

    print_users_names(row, col, target, toDelete);
    move_in_users(row, col, target, toDelete);

    exit_to_main_menu(row, col);
}

void print_users_word(const int row, const int col) {
    system("clear");
    std::cout << "\033[1m" << "\033[32m" << std::endl; //32 is green color id
	gotoxy(3, col/2-13); std::cout << " _   _ ____  _____ ____  ____";
    gotoxy(4, col/2-13); std::cout << "| | | / ___|| ____|  _ \\/ ___|";
	gotoxy(5, col/2-13); std::cout << "| | | \\___ \\|  _| | |_) \\___ \\";
    gotoxy(6, col/2-13); std::cout << "| |_| |___) | |___|  _ < ___) |";
    gotoxy(7, col/2-13); std::cout << " \\___/|____/|_____|_| \\_\\____/" << "\033[0m" << std::endl;

    gotoxy(row, col/2-16); std::cout << "⇾ For returning main menu press" << "\033[1m" << "\033[32m" << " Esc " << "\033[0m" << "⇽" << std::endl;
}

void print_users_names(const int row, const int col, int target, bool toDelete) {
    for(int i = 0; i < usersCount; ++i) {
        gotoxy(15+3*i, col/2-13); std::cout << "╔═════════════════════╗  ╔═══╗";
        gotoxy(15+3*i+1, col/2-13); std::cout << "║";
        if (i == target) {
            gotoxy(15+3*i+1, ceil(col/2 - 12 + (23-names[i].length()-2)/2)); std::cout << "\033[1m" << "\033[32m" << names[i] << "\033[0m";
        } else {
            gotoxy(15+3*i+1, ceil(col/2 - 12 + (23-names[i].length()-2)/2)); std::cout << names[i];
        }
        gotoxy(15+3*i+1, col/2 + 9); std::cout << "║";
        gotoxy(15+3*i+1, col/2 + 12); std::cout << "║";
        if (toDelete && i == target) {
            gotoxy(15+3*i+1, col/2 + 14); std::cout << "\033[1m" << "\033[32m" << "✘" << "\033[0m";
        } else {
            gotoxy(15+3*i+1, col/2 + 14); std::cout << "✘";
        }
        gotoxy(15+3*i+1, col/2 + 16); std::cout << "║";
        gotoxy(15+3*i+2, col/2-13); std::cout << "╚═════════════════════╝  ╚═══╝" << std::endl;
    }
}

void move_in_users(const int row, const int col, int target, bool toDelete) {

    cbreak();
    while(true) {
        const int key = keypress();
        switch(key) {
		case 'w' : case 'W' :
            if(!toDelete) {
                target = (target == 0) ? usersCount - 1 : target - 1;
                print_users_names(row, col, target, toDelete);
            }
			break;
		case 's' : case 'S' : 
            if(!toDelete) {
                target = (target == usersCount - 1) ? 0 : target + 1;
                print_users_names(row, col, target, toDelete);
            }
			break;  
        case 'd' : case 'D' :
            toDelete = true;
            print_users_names(row, col, target, toDelete);
            break;
        case 'a' : case 'A' :
            toDelete = false;
            print_users_names(row, col, target, toDelete);
            break;
        case 10 : //Enter in ASCII
            if (toDelete) {
                system("clear");
                print_users_word(row, col);
                for (int i = target; i < usersCount; ++i) {
                    names[i] = names[i+1];
                }
                usersCount --;
                target = 0;
                toDelete = false;
                print_users_names(row, col, target, toDelete);
            }
            break;
        case 27 : //Esc in ASCII
            menu(row, col);
            return;
        } 
    } 

        /*case 10 : 
            if(toDelete) {
                print_users_word(row, col);
                for(int i = target; i < usersCount; ++i)  {
                    names[i] = names[i+1];
                }
                usersCount --;
                print_users_names(row, col);
                gotoxy(15+1, col/2 - 12 + (23-names[0].length()-2)/2); std::cout << "\033[32m" << "\033[1m" << names[0] << "\033[0m" << std::endl;
                toDelete = false;
            }
            break;
        case 27 : 
            menu(row, col);
            break;
        }
    }*/
}
