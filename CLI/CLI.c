#include <stdio.h>
#include <string.h>
#include "app.h"

#define MAX_SIZE 100

void parse(char parsed[][MAX_SIZE]) {
    char input[MAX_SIZE];
    fgets(input, MAX_SIZE, stdin);

    int j = 0, k = 0;
    for (int i=0; i <= (strlen(input)); ++i) {
        if(input[i] == ' ' || input[i] == '\0' || input[i] == '\n') {
            parsed[k][j] = '\0';
            ++k;
            j = 0; 
        } else {
            parsed[k][j] = input[i];
            ++j;
        }
    }
}

void connectToCLI(Commands_s *commands, char *prompt) {
    while (1) {
        // waiting for client's input/command
        printf("%s", prompt);

        // gets user input, parse it and make command
        char parsed[MAX_SIZE][MAX_SIZE];
        parse(parsed);

        char command[MAX_SIZE];
        strcpy(command, parsed[0]);
        
        // checking if there is such a command
        int count = 0;	
        if (strlen(command) > 1) {
            for (int i = 0; i < MAX_COMMANDS; ++i) {
                if (strcmp(command, commands[i].name) == 0) {
                    ++count;
                    break;
                }
            }
            
            if (count == 0) {
                printf("Error: Command not found\n");
            } else if (strcmp(command, commands[0].name) == 0) {
                for (int i = 0; i < MAX_COMMANDS; ++i) {
                    printf(" %s | %s \n", commands[i].name, commands[i].info);
                }
            } else {
                for (int i = 0; i < MAX_COMMANDS; ++i) {
                    if (strcmp(command, commands[i].name) == 0) {
                        commands[i].Command(parsed);
                    }
                }

            }
        }
    }
}
