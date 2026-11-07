
#include <stdio.h>
#include "header.h"

void help(void)
{
    printf("\n");

    printf(BOLD_CYAN"!!!!!!!!!!!!!!!!!!!!! HELP MENU !!!!!!!!!!!!!!!!!!!!"RESET "\n");

    printf("\n" BOLD_GREEN "1. -v" RESET" -> to view mp3 file contents\n");

    printf(BOLD_GREEN "2. -e" RESET" -> to edit mp3 file contents\n");

    printf("       " YELLOW "2.1. -t" RESET" -> to edit song title\n");

    printf("       " YELLOW "2.2. -a" RESET" -> to edit artist name\n");

    printf("       " YELLOW "2.3. -A" RESET" -> to edit album name\n");

    printf("       " YELLOW "2.4. -y" RESET" -> to edit year\n");

    printf("       " YELLOW "2.5. -i" RESET" -> to edit genre\n");

    printf("       " YELLOW "2.6. -c" RESET" -> to edit comment\n");

    printf("\n" BOLD_CYAN"============================================================="RESET "\n");
}
