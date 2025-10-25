/*Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s. In particular, itob(n,s,16) formats s as a
hexadecimal integer in s.*/
#include <stdio.h>
#include <string.h>
#define max 100

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

void itob(int n, char s[], int b)
{
    int i = 0;
    int sign;
    int digit; // stores remainder (0-35)
    
    // Check for valid base range
    if (b < 2 || b > 36) {
        s[0] = '\0'; 
        return;
    }
    sign = n;
    
    if (n > 0) {
        n = -n;
    }
    
    do {
        // Since n is non-positive, n % b is non-positive.
        // Negating it gives the correct positive digit value (0 to 35).
        digit = -(n % b); 

        // Convert digit value to hex
        if (digit <= 9) 
		{
            s[i++] = digit + '0';
        } 
		else 
		{
            s[i++] = digit - 10 + 'a'; 
        }
        
    } while ((n /= b) != 0); 
    
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main()
{
    char s[max];
    int n,b;
    printf("enter number: ");
    scanf("%d", &n);
    printf("enter base (2-36): ");
    scanf("%d", &b);
    itob(n, s, b);
    printf("Result in base %d: %s\n", b, s); 
    
    return 0;
}
