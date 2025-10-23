#include<stdio.h>
main(){
	float fahr,cel,lower,upper,step;
	lower=0;
	upper=300;
	step=20;
	fahr=lower;
	printf("fahrenheit \t celsius\n");
	while(fahr<=upper){
		cel= ((fahr-32)*5)/9;
		printf("%f\t%f\n",fahr,cel);
		fahr+=step;
	}
}

