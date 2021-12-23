#ifndef USERS_HPP
#define USERS_HPP

//global variables
extern std::string names[5];
extern int usersCount;

void print_users_names(const int row, const int col, int target, bool toDelete);
void print_users(const int row, const int col);
void move_in_users(const int row, const int col, int target, bool toDelete);
void print_users_word(const int row, const int col);

#endif
