/*Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types. 
*/
#include <stdio.h>
int main() 
{
	unsigned char uc = ~0; // all bits 11111111        
	unsigned short us = ~0;
	unsigned int ui = ~0;
	unsigned long ul = ~0;

	printf("signed char: %d to %d\n", -(char)(uc>>1) - 1, (char)(uc>>1));
	printf("unsigned char: 0 to %u\n", uc);

	printf("signed short: %d to %d\n", -(short)(us >> 1) - 1, (short)(us >> 1));
	printf("unsigned short: 0 to %u\n", us);

	printf("signed int: %d to %d\n", -(int)(ui >> 1) - 1, (int)(ui >> 1));
	printf("unsigned int: 0 to %u\n", ui);

	printf("signed long: %ld to %ld\n", -(long)(ul >> 1) - 1, (long)(ul >> 1));
	printf("unsigned long: 0 to %lu\n", ul);

return 0;
}

