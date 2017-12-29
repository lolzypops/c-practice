#include <stdio.h>
/* https://www.w3resource.com/c-programming-exercises/basic-declarations-and-expressions/index.php */
/* Declaration */
void days_to_years(int);

void main(){
    // Problem 8
    days_to_years(1329);
}

/* Problem 8: Write a C program to convert specified days into years, weeks and days. */
void days_to_years(int days) {
    int years = days / 365;
    int rem1 = days % 365;
    int weeks = rem1 / 7;
    int days_left = rem1 % 7;
    printf("Years: %d\n", years);
    printf("Weeks: %d\n", weeks);
    printf("Days: %d\n", days_left);
}