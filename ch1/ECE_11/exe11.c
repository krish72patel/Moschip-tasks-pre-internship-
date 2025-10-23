#include<stdio.h>
#define in 1
#define out 0
	main(){
		int nw,c,state;
		nw=0;
		while((c=getchar())!=EOF)
		{
			if (c=='\t' || c==' ' ||  c=='\n')
			{
			       	state=out;
			}
			else if(state==out)
			{
				state=in;
				++nw;
			}
		}
		printf("%d",nw);
	}
