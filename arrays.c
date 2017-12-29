#include <stdio.h>

void bound_check() {
    int a[] = { 1, 2, 3 };
    for (int i=0; i<4; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    // last index out of bounds - doesn't error/stop compiliation
    // Good style: define a constant to use as the size of an array
    const int ARRAY_SIZE = 5;
    int j, b[ARRAY_SIZE];
    for (j=0; j<ARRAY_SIZE; j++) {
        continue;
    }
}

void ptr_to_ptr() {
    int x[] = { 2, 4, 6, 8, 10 };
    int *p = x; // p is the address of the first element in x.
    int **pp = &p; // pp is assigned the address of p.
    (*pp)++; 
    /* Dereferencing pp gives us p, the pointer holding the address of the first element in x. 
     * Next, we increment p - it now holds the address of the second element of the array. */
    (*(*pp))++;
    /* Going inside out, dereferencing pp gives us p, a pointer holding the address of the second element in x.
     * Dereferencing pp as second time gives us the value of whatever is stored at the address p is pointing to - the second element of x.
     * Finally, we increment this element by 1 - the second element of x is now 5. */
    printf("*p = %d\n", *p); // Should be 5.
}

int str_len(char s[]) {
    /* Strings are null-terminated char arrays */
    int n = 0;
    while (s[n]!=0) n++;
    return n;
}

// Concise version utilizing pointer arithmetic. Works as long as there isn't a non-zero character at end of string.
int slen(char s[]) {
    char *p = s;
    printf("&s = %p, *s = %c\n", s, *s);
    while (*p++) printf("Loop: &p = %p, *p = %c\n", p, *p); 
    /* *p++ = *(p++) since postfix ++ has higher precedence. 
     * The derefernence refers to the address p is pointing to before it's incremented by definition of postfix ++. */
    printf("Break: &p = %p, *p = %c\n", p, *p);
    return (p-s-1); // Minus 1 because we increment p once more before the loop breaks.
}

void main() {
    bound_check();
    ptr_to_ptr();
    char str[] = "a";
    // printf("str = %s, len = %d\n", str, str_len(str));
    printf("str = %s, len = %d\n", str, slen(str));
}