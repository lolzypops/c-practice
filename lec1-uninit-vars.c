#include <stdio.h>
#include <stdlib.h>

/* A test/demonstration of how uninitalized local variables don't error in C.
 * The last uninitialized variable in a function that is accessed takes on the most recent local variable's value in its scope.
 * Previously accessed, uninitialized variables within the same scope take on their type's default unitialized values. */

void some_calc(int a) {
    // if a is odd, random var assigned to a, else a = -a
    a = a % 2 ? rand() : -a;
    int b = 10; // with the addition of this line, a is never accessed or assigned to any of the undef local variables
}

void some_calc_2() {
    int c = 7;
}

void undef_local() {
    int x, y;
    printf("x = %d\n", x);
    printf("y = %d\n", y); // if this line is commented out, then x will take on b's value rather than staying 0 (default uninitialized int value)
}

void undef_local_2() {
    int z;
    printf("z = %d\n", z);
    // z takes on b's value but doesn't cancel y's taking on of b's value
}

void main() {
    for (int i=0; i<5; i++) {
        some_calc(i*i);
        undef_local();
        some_calc_2();
        undef_local_2();
        // the uninitialized local variables of undef_local() obtain the final value of the local variables in some_calc()
    }
}