#include <iomanip>
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include "../Include/main_menu.hpp"

int main()
{
    //finding terminal's size
    winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    const int col = w.ws_col;
    const int row = w.ws_row;

    menu(row, col); //creating main menu
}
