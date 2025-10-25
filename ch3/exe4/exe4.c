/*In a two's complement number representation, our version of itoa does not
handle the largest negative number, that is, the value of n equal to -(2^(wordsize-1)). Explain why not.
Modify it to print that value correctly, regardless of the machine on which it runs. */

#include <stdio.h>
#include <string.h>

#define max 20 // Buffer size

void reverse(char s[])
{
    int i, j;
    char temp;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itoa(int n, char s[])
{
    int i = 0;
    int sign;
    sign = n; 
    if(n>0)
    {
    	n=-n;
	}
    
    do { 
        // n % 10 results in a negative digit (e.g., -8 for -128 % 10).
        // Negating the result gives the positive digit (e.g., 8).
        s[i++] = -(n % 10) + '0'; 
        
    } while ((n = n / 10) != 0); // Correctly includes assignment in while loop
    
    if (sign < 0)
    {
        s[i++] = '-';
    }
    
    s[i] = '\0';
    reverse(s);
}

int main()
{
    char s[max];
    int n = -(int)(((unsigned int)~0) >> 1) - 1;//~0-> 32  bits one we need 31 bits '1'-->shift right operator (largest number=2^n-1-->n=32(for 32 bit system)) 
    itoa(n, s);
    printf("n (%d): %s\n", n, s); 
    int in; 
    printf("Enter a number: ");
    if (scanf("%d", &in) != 1) 
	{
        printf("Invalid input.\n");
        return 1;
    }
    itoa(in, s);
    printf("User number (%d): %s\n", in, s); 
    
    return 0;
}
