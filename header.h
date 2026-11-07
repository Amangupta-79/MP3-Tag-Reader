
#ifndef header_h
#define header_h

// Reset color
#define RESET       "\033[0m"

// Text colors
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

// Bold colors
#define BOLD        "\033[1m"
#define BOLD_RED    "\033[1;31m"
#define BOLD_GREEN  "\033[1;32m"
#define BOLD_YELLOW "\033[1;33m"
#define BOLD_CYAN   "\033[1;36m"

void view_mp3(char*filename);
void edit_mp3(char *option, char *value, char *filename);
void help(void);

#endif
