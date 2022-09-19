#include <iostream>
#include "../Include/about.hpp"
#include "../Include/input.hpp"
#include "../Include/main_menu.hpp"
#include "../Include/settings.hpp"

int level = 1;

void settings(const int row, const int col) {
    const int size = 5;
    std::string levels[size] = {"▣", "▢", "▢", "▢", "▢"};
    int target = 0;
    print_settings(row, col, levels, size);

    cbreak();
    while(true) {
        int key = keypress();
        switch(key) {
        case 'd' :
            if (target != size-1) {
                levels[++target] = "▣";
                print_settings(row, col, levels, size);
            }
            break;
        case 'a' : 
            if (target != 0) {
                levels[target--] = "▢";
                print_settings(row, col, levels, size);
            }
            break;
        case 10 : //Enter in ASCII 
            level = target + 1;
            break;
        case 27 : //Esc in ASCII
            menu(row, col);
            break;
        }
    }
}

void print_settings(const int row, const int col, std::string levels[], const int size) {
    system("clear");
    gotoxy(row/2-1, col/2-10); std::cout << "Please choose a level" << std::endl;
    gotoxy(row/2+1, col/2-12); std::cout << "You can go" << "\033[32m" << "\033[1m" << " ⇦ " << "\033[0m" << "(a) or" << "\033[32m" << "\033[1m" << " ⇨ " << "\033[0m" << "(d)" << std::endl;
    gotoxy(row/2+3, col/2-8); std::cout << " ◄ ";
    for (int i = 0; i < size; ++i) {
        gotoxy(row/2+3, col/2-8+2*i+4); std::cout << levels[i];
    }
    gotoxy(row/2+3, col/2-8+10+4); std::cout << " ► " << std::endl;

    gotoxy(row, col/2-16); std::cout << "⇾ For returning main menu press" << "\033[1m" << "\033[32m" << " Esc " << "\033[0m" << "⇽" << std::endl;
}
