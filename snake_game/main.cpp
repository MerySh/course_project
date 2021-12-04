#include "main_menu.hpp"
#include <iostream>
#include <iomanip>
#include <sys/ioctl.h>
#include <unistd.h>

int main()
{
    //finding terminal's size
    winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    const int col = w.ws_col;
    const int row = w.ws_row;

    menu(row, col); //creating main menu
}
