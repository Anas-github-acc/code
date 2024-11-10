#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *names = fopen("names.txt", "r");
    FILE *greet = fopen("greet.txt", "w");

    if (!names || !greet) {
        fprintf(stderr, "File opening failed!\n");
        return EXIT_FAILURE;
    }
    char name[20];

    while (fscanf(names, "%s\n", name) > 0) {
        fprintf(greet, "Hello, %s!\n", name);
    }

    if (feof(names)) {
        printf("Greetings are done!\n");
    }

    return 0;
}

// C provides a number of build-in function to perform basic file operations:

// fopen() - create a new file or open a existing file
// fclose() - close a file
// getc() - reads a character from a file
// putc() - writes a character to a file
// fscanf() - reads a set of data from a file
// fprintf() - writes a set of data to a file
// getw() - reads a integer from a file
// putw() - writes a integer to a file
// fseek() - set the position to desire point
// ftell() - gives current position in the file
// rewind() - set the position to the beginning point