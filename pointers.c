#include <stdio.h>

/* Need to declare functions before  */
void var_ptrs() {
    int *x; // variable x is an	address to an int
    int y = 9; // y	is an int
    void *a; // generic pointer - can't be dereferenced
    char b = 'b';
    a = &b;
    x = &y; // assign address of y to x
    // & := "address operator"
    int z = *x; // assign what x is	pointing to	to z
    // "dereference operator"
    *x = -7; //	assign -7 to what x is pointing to
    printf("x = %p\n", x); // %p to print pointer memory address
    printf("*x = %d\n", *x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);
    printf("*a = %c\n", *(char *)a);
}

void struct_ptrs() {
    typedef struct { int x, y; } Point;
    Point pt = { 0, 5 };
    Point *pt_ptr = &pt;
    pt_ptr->x = 7;
    printf("pt.x = %d\n", pt.x);
    printf("pt.y = %d\n", pt.y);
}

/* C passes variables as copies - the original parameter passed in remains unchanged (out of scope). 
 * To pass by reference (change the original parameter's value), you should pass in the parameter's address.
 * In Java, primitives are passed as copies and objects as references. */
void pass_by_ref_or_val(int x, int *p) {
    x = 5;
    *p = -9;
}

void main() {
    var_ptrs();
    struct_ptrs();
    int a = 1, b = -3;
    pass_by_ref_or_val(a, &b);
    printf("a = %d b = %d\n", a, b);
}