#include <stdio.h>
#include "app.h"

#define MAX_SIZE 100

Commands_s commands[] = {
    { "help", "Gives all commands" },
    { "connect", "Connecting", &connect },
    { "disconnect", "Disconnecting" },
    { "get_time", "Gives current time" }
};

int main() { 
    prompt = ">";   
    connectToCLI(commands, prompt);
}

/*
void get_time(const char *n, const char *i) {
	printf(" Getting time.\n");
}
*/
void connect(char parsed[MAX_SIZE][MAX_SIZE]) {
    if () {
        printf("No given port or ip_addr");
    } else {
	    printf(" Connecting to the port %s ip_addr is %s\n", parsed[2], parsed[1]);
    }
}

/*
void disconnect(const char *n, const char *i) {
	printf(" Disconnected.\n");
}
*/
