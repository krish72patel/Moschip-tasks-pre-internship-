/*Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t.
(Block structure will help.)*/

//remember to ask question based on this solution of yours in company


#include <stdio.h>

#define swap(t, x, y)  do { t temp = (x); (x) = (y); (y) = temp; } while (0)

int main() {
    int a = 10, b = 20;
    double p = 3.14, q = 2.71;
    char c1 = 'A', c2 = 'Z';

    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(int, a, b);
    printf("After swap:  a = %d, b = %d\n", a, b);

    printf("\nBefore swap: p = %.2f, q = %.2f\n", p, q);
    swap(double, p, q);
    printf("After swap:  p = %.2f, q = %.2f\n", p, q);

    printf("\nBefore swap: c1 = %c, c2 = %c\n", c1, c2);
    swap(char, c1, c2);
    printf("After swap:  c1 = %c, c2 = %c\n", c1, c2);

    return 0;
}

