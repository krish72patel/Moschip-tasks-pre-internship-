#include<stdio.h>
main(){
	long ns,nt,nl;
	int c;
	ns=0;
	nt=0;
	nl=0;
	while ((c=getchar())!=EOF)
	{
		if (c==32)
		{
			++ns;
		}else if(c==9)
		{
			++nt;
		}else if(c==10)
		{
			++nl;
		}
	}
	printf("no of space=%ld\nno of tab=%ld\nno of lines=%ld",ns,nt,nl);
}
