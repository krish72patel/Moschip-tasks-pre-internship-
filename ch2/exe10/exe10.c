/*Rewrite the function lower, which converts upper case letters to lower case,
with a conditional expression instead of if-else*/

#include <stdio.h>
int lower(int c);
int main()
{
    int c;
    printf("Enter a single character: ");
    c=getchar();
    c=lower(c);
    printf("Converted character: %c\n", c);
    return 0;
}
int lower(int c)
{
	int x;
	x=(c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
    return x;
}
