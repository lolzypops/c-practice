#include <stdio.h>
#include <string.h>

void main(int argc, char *argv[]) {
    FILE *inputFile = fopen(argv[1], "r");
    char buff[1024];
    /* Assumes no word exceeds length of 1023 */
    while (fscanf(inputFile, " %1023s", buff) == 1) {
        printf("%d: ", (int) strlen(buff));
        printf("%s", buff);
    }
    int i;
    int count = 0;
    char c;
    while ((i = fgetc(inputFile)) != EOF) {
        c = (char) i;
        count++;
        if (c == ' ')
        printf("Count: %d, Char: %c\n", count, c);
    }
}
