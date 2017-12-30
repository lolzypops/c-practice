#include <stdio.h>

/* Topics Covered:
 * Parts of memory allocation:
 * - Code:
 * --- Loaded when program starts; comes from the compiler
 * --- Doesn't change
 * - Static Data
 * --- Loaded when program starts
 * --- Can be modified
 * --- Size doesn't change
 * - Stack
 * --- Local variables and arguments inside functions
 * --- Allocated when function is called and deallocated when function returns (LIFO)
 * - Heap
 * --- Space for dynamic data
 * --- Allocated and freed by the program as needed 
 * Functions returning pointer to a local variable may have pointer value overriden
 * - If another function is called after it, the stack is reallocated and the pointer value is related to the new function
 * - After the  */

// Stack Begin
/* Each call to a function allocates a new frame in memory.
 * Each frame contains:
 * - Function args
 * - Local vars
 * - Return addresses (memory of who called me)
 * Stacks use contiguous blocks of memory
 * - A stack pointer indicates current level of stack */

int b(int arg);

void a() {
    int a_local = 0;
    b(a_local);
}

int b(int arg) {
    int b_local = 5;
    return 2 * arg + b_local;
}

int *f() {
    int x = 5;
    return &x;
    /* After f returns, the stack is dumped. 
     * x is still assigned to that point in memory unless some other function that is called reuses it. */
}

// Stack End
// Heap Begin
/* Heap Management Functions:
 * void *malloc(size_t n): allocate a block of uninitialized memory
 * - size_t is an internal C type that's an unsigned integer that's big enough to represent all of the address space of your machine
 * - returns void pointer (generic type) or NULL which means out of memory. Always check return value of malloc(n).  
 * calloc(): allocate a block of zeroed memory
 * void free(void *p): free previously allocated block of memory
 * - Release memory allocated by malloc()
 * - p must be the original pointer that malloc was run on. Don't modify the pointer originally returned by malloc.
 * realloc(): change size of previously allocaed block */
void malloc_usage() {
    // array of 50 ints: 200bytes
    int *ip = (int*)malloc(50*sizeof(int)); // void* casted into int*

    // typecast is optional
    double *dp = malloc(1000*sizeof(double)); // warning (recommended to cast the type)
}

void arr_alloc() {
    // Explicit Memory Management (Manual: done when needed) (C/C++) vs. Auto Memory Management (Garbage Collection) (Java)
    const int SIZE = 10;
    int *array = (int*)malloc(SIZE*sizeof(int));
    for (int *p=array; p<&array[SIZE];) {
        *p++;
    }
    free(array);
}

// Heap End

void main() {
    a();
    b(7);
    /* Up to this point, memory allocated for the stack is largest when a calls b during execution.
     * The stack containes frames for main, a, and b.
     * After b returns, a also returns and then b is called in the main function - 
     * creating a frame for b underneath the main frame (reusing the memory previously occupied by a). */
    // int *c = f();
    // printf("c = %p, *c = %d", c, *c);
    // a(); // overrides pointer value to the local variable in f. Segmentation core error.
    // printf("c = %p, *c = %d", c, *c); 
    arr_alloc();
}