#include<stdio.h>
main(){
	char c;
	while((c=getchar())!=EOF)
	{
		if (c==9) //ascii of tab is 9
		{
			printf("\\t");
		}
		else if(c=='\b')// ascii of backspace is 8 or 127 deepending on system
		{
			printf("backspace");
			printf("\\b");
		}
		else if(c==92)// ascii of bsckslash is 92
		{printf("\\\\");
		}
		else
		{printf("%c",c);
		}
	}
}
