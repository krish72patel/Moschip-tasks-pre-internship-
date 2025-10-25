/*Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.*/

#include<stdio.h>
#include<math.h>
int invert(int,int,int);
int main()
{
        int x,a,m,q;
        printf("enter no.1\n");
        scanf("%d",&a);
        printf("enter the no of bits to invert\n");
        scanf("%d",&m);
        printf("enter position from where to invert\n");
        scanf("%d",&q);
        x=invert(a,q,m);
        printf("number after inverting bits %d\n",x);
}
int invert(int x, int p, int n)
{
    int mask = (1<<n)-1;
    int shift = p-n+1;
    mask = mask << shift;
    x=x^mask;
    return x;
}
