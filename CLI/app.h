#define MAX_COMMANDS 4
#define MAX_SIZE 100

typedef struct Commands {
	const char* name;
	const char* info;
	void (*Command)(char parsed[MAX_SIZE][MAX_SIZE]);
} Commands_s;

char *prompt;

void connectToCLI(Commands_s *, char *);

void connect(char parsed[MAX_SIZE][MAX_SIZE]);
//void get_time(const char *n, const char *i);

//void disconnect(const char *n, const char *i);

