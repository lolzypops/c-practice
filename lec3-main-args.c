#include <stdio.h>

/* Retrieving arguments from command line. 
 * Unix: 
 * gcc -o ex main-args.c // Places the output of main-args.c into executable file ex
 * ./ex -g a "d e f" // executes main-args.c on all arguments 
 * argv[0] is always the name of the executed program 
 * argv[argc] is always a null pointer 
 * argv[1] is the first argument. */
void main(int argc, char *argv[]) {
    // argc is the number of strings on the command line
    // argv is a pointer to an array of values containing the arguments as strings
    for (int i=0; i<argc; i++) {
        printf("arg[%d] = %s\n", i, argv[i]);
    }
}