#include<stdio.h>


float cell(float x);
main(){
	float fahr,lower,upper,step;
	lower=0;
	upper=300;
	step=20;
	fahr=lower;
	printf("fahrenheit \t celsius\n");
	while(fahr<=upper){
		printf("%f\t%f\n",fahr,cell(fahr));
		fahr+=step;
	}
}

float cell(float x)
{
	float y;
	y=((x-32)*5)/9;
	return y;
}
