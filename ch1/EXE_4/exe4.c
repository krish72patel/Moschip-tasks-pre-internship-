#include<stdio.h>
main(){
	float fahr,cell,lower,upper,step;
	lower=0;
	upper=300;
	step=20;
	cell=lower;
	printf("celsius \t fahrenheit\n");
	while(cell<=upper){
		fahr= ((cell*9)/5)+32;
		printf("%f \t %f\n",cell,fahr);
		cell+=step;
	}
}
