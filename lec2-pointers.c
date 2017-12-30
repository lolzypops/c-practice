#include <stdio.h>
#include <stdlib.h>

/* Topics Covered:
 * Typed and void pointers
 * Structs
 * Enumerations and switch cases 
 * Passing by ref vs. copy (value) 
 * Pointer to pointer vs. pointer
 * - stackoverflow.com/questions/5580761/ */

typedef enum { red, green, blue } Color;

// Need to declare functions before they're called in the main function.
void var_ptrs() {
    int *x; // variable x is an	address to an int
    int y = 9; // y is an int
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
    /* A struct is like a Java class without the methods */
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

void pants_color(Color pants) {
    switch (pants) {
        case red:
            printf("Red pants are hip\n");
            break;
        case green:
            printf("Green pants are weird\n");
            break;
        default:
            printf("Color not recognized\n");
    }
    printf("pants = %d\n", pants); 
    /* If you wanted to print the key (Color) instead of the enumerated value, 
     * you'd have to use a switch function or an array map. */
}

void alloc2(int** p) {
    *p = (int*)malloc(sizeof(int));
    **p = 10;
}

void alloc1(int* p) {
    p = (int*)malloc(sizeof(int));
    *p = 10;
}

void main() {
    var_ptrs();
    struct_ptrs();
    int a = 1, b = -3;
    pass_by_ref_or_val(a, &b);
    printf("a = %d b = %d\n", a, b);
    Color pants = green;
    pants_color(pants);
    int *p;
    alloc1(p);
    //printf("%d ",*p);//value is undefined
    alloc2(&p);
    printf("%d\n",*p);//will print 10
    free(p);
}