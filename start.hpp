#ifndef START_HPP
#define START_HPP

void game(const int row, const int col);
void login(const int row, const int col);
void game_logic(const int row, const int col);
void create_board(std::string board[][20], const int size);
void random_apple_coordinates(std::string board[][20], const int size);
void print_board(std::string board[][20], const int size, const int row, const int col);
void snake_body(int currentHead[], int currentTail[], int currentSnake[], std::string board[][20], const int size);
void put_snake(std::string board[][20], int currentSnake[]);
void press(std::string board[][20], const int size, int currentHead[], int currentTail[], int currentSnake[], const int row, const int col);
void game_over(const int row, const int col);

#endif
