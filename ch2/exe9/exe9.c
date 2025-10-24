/*In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
in x. Explain why. Use this observation to write a faster version of bitcount.
*/
#include<stdio.h>
int bitcount(unsigned);
int main()
{
	unsigned int a;
	int q;
	printf("enter a number");
	scanf("%u",&a);
	q=bitcount(a);
	printf("no of 1's in the number is:%d\n",q);
}
int bitcount(unsigned int x)
{
    int b;
    for (b = 0; x != 0; b++) 
	{
        x &= (x - 1); // clear rightmost '1' -bit in x
    }
    
    return b;
}
