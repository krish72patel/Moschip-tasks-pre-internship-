#include <stdio.h>
#define TAB_STOP 8
int main() 
{
	int c;
	int spaces;
	int column=1;
        while ((c = getchar()) != EOF) 
	{
		if (c == '\t') 
		{
			spaces = TAB_STOP - ((column - 1) % TAB_STOP);
	                while (spaces > 0) 
			{
				putchar(' ');
				column++;
		                spaces--;
 		        }
	        } 
		else if (c == '\n') 
		{
			putchar(c);
			column = 1;
		}
		else 
		{
			putchar(c);
			column++;
		}
	}
return 0;
}
