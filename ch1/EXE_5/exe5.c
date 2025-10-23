#include<stdio.h>
main(){
	float fahr,cell;
	printf("fahrenheit \t celsius\n");
	for(fahr=300;fahr>=0;fahr=fahr-20)
	{
		cell=((fahr-32)*5)/9;
		printf("%f \t %f \n",fahr,cell);
	}
}
