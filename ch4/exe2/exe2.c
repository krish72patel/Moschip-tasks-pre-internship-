/*Extend atof to handle scientific notation of the form
 123.45e-6
where a floating-point number may be followed by e or E and an optionally signed exponent.*/

#include <stdio.h>
#include <ctype.h>
#define max 100
double atof(char s[]);
int main()
{
	char s[max];
	char c;
	double sum = 0;
	int i;
	
	printf("enter a number eg.2e-3");
	for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++)
	{
	 	s[i] = c;
	}
	s[i] = '\0';
	
	if (i > 0) {
		printf("\t%g\n", sum += atof(s));
	} else {
		printf("No input processed.\n");
	}
	
	return 0;
}

double atof(char s[])
{
	int k;
	double val = 0.0;
	double power = 1.0;
	int exp_sign = 1;
	int exp_val = 0;
	double exp_factor = 1.0;
	
	int i, sign;
    
	for (i = 0; isspace(s[i]); i++) // skip white space 
	{
	}
	
	sign = (s[i] == '-') ? -1 : 1; // check sign 
	
	if (s[i] == '+' || s[i] == '-')
	{
	 	i++;
	}
    
	for (val = 0.0; isdigit(s[i]); i++)// calculate value before decimal point
	{
		val = 10.0 * val + (s[i] - '0');
	}
    
	if (s[i] == '.')//check for decimal point
	{
		i++;
	}
    
	for (power = 1.0; isdigit(s[i]); i++) // calculate value after decimal point
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
    
	if (s[i]=='e' || s[i]=='E')// check for exponent
	{
	 	i++;
	 	
	 	exp_sign = (s[i] == '-') ? -1 : 1; // check for exp sign
	 	
	 	if (s[i] == '-' || s[i] == '+')
	 	{
	 		i++;
		}
        
		for (; isdigit(s[i]); i++)// calc val of exp
		{
		 	exp_val = 10 * exp_val + (s[i] - '0');
		}
        
		if (exp_val != 0)
		{
			for (k = 0; k < exp_val; k++)// calc val of 10^(exp_val)
			{
				if (exp_sign > 0)
				{
					exp_factor *= 10.0;
				}
				else
				{
					exp_factor /= 10.0;
				}
			}
		}
		val *= exp_factor;
	}

	return sign * val / power;
}
