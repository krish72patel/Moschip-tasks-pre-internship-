/*Write a function rightrot(x,n) that returns the value of the integer x rotated
to the right by n positions. */

#include<stdio.h>
#include<math.h>
int invert(int,int);
int main()
{
        int x,a,m;
        printf("enter no.1\n");
        scanf("%d",&a);
        printf("enter the no of bits to rotate\n");
        scanf("%d",&m);
        x=invert(a,m);
        printf("number after inverting bits %d\n",x);
}
int invert(int x, int n)
{
	int temp;
	int wordsize = sizeof(int)*8;// total int size in bits
	n=n%wordsize;//normalize n,rotating 35 times in 32 bits is same as rotating 3
	if(n==0)
	{
		return x;
	}
    int mask = (1<<n)-1;
    temp=x & mask;//bits to be rotated
    temp=temp<<(wordsize-n);//bits shifted to left most,rotating bits
	x=x>>n ;//non rotating bits shifted to right
    x=x|temp;
    return x;
}
