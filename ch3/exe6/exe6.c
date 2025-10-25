/*Write a version of itoa that accepts three arguments instead of two. The third
argument is a minimum field width; the converted number must be padded with blanks on the
left if necessary to make it wide enough. */

#include <stdio.h>
#include <string.h>
#define max 20 
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

void itoa_padded(int n, char s[], int w)
{
    int i = 0;
    int sign;
    sign = n; 
    if (n > 0) {
        n = -n;
    }
    do { 
        s[i++] = -(n % 10) + '0'; 
    } while ((n = n / 10) != 0); 
    if (sign < 0) {
        s[i++] = '-';
    }
    while (i < w)// pad spaces till 'w' 
	{
        s[i++] = ' '; 
    }
    s[i] = '\0';
    reverse(s);//end and reverse
}

int main()
{
    char s[max];
    int w= 15; // Width
    int n = -(int)(((unsigned int)~0) >> 1) - 1;// largest negative number on this system) 
    
    itoa_padded(n, s, w);
    printf("\"%s\"\n",s);
    int in; 
    printf("Enter a number: ");
    if (scanf("%d", &in) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    itoa_padded(in, s, w);
    printf("\"%s\"\n",s);
    
    return 0;
}
