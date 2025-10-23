#include<stdio.h>
main(){
	char c;
	char prev;
	while ((c=getchar())!=EOF)
	{
	       if ((prev==32 && c==32))	
	       { 
	       }
	       else{
		       printf("%C",c);
	       
	       }
	       prev=c;
	}
}
