#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP
#include <string>

void menu(const int row, const int col);
void print_menu(std::string main_menu[], const int main_menu_count, int target, const int row, const int col);
void print_with_color(int x, int space, int i, std::string main_menu[]);
void only_print(int x, int space, int i, std::string main_menu[]);
void menu_controller(int target, const int row, const int col);

#endif
