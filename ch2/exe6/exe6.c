/*Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y, leaving the other bits unchanged.*/

#include<stdio.h>
#include<math.h>
int setbits(int,int,int,int);
int main()
{
	int x,a,b,m,q;
	printf("enter no.1\n");
	scanf("%d",&a);
	printf("enter no2.\n");
	scanf("%d",&b);
	printf("enter the no of bits to replace from no2\n");
	scanf("%d",&m);
	printf("enter position from where to replace\n");
	scanf("%d",&q);
	x=setbits(a,b,m,q);
	printf("number after shifting bits %d\n",x);
}
int setbits(int x,int y,int n,int p)
{
	int mask,shift;

	mask=pow(2,n)-1;
	y=y&mask;
	shift=p-n+1;
	y=y<<shift;
	mask=mask<<shift;
	x=x&(~mask);
	x=x|y;
	return x;
}



