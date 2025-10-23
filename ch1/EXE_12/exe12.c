#include<stdio.h>
main()
{
	char c,prev;
	while((c=getchar())!=EOF)
	{
		if((prev==' ' && c==' ') || (prev=='\t' && c=='\t') || (prev=='\n' && c=='\n'))
		{
		}
		else{
			
			if(c==' ' || c=='\t' || c=='\n')
			{
				printf("\n");
				prev=c;
			}
			else
			{
				printf("%c",c);
				prev=c;
			}
		}
	}
}
