/*Adapt the ideas of printd to write a recursive version of itoa; that is, convert
an integer into a string by calling a recursive routine.*/

#include<stdio.h>

#define MAXLINE 100

void itoa(int );

char s[MAXLINE]; //a global character array where the result will be stored
int i=0,sign=1; //a global index variable to maintain proper index during recursive calls beacuse if index is maintained
//within function then for each call the variable defined for index within func gets fresh values independent of previous calls
//and hence will not serve our purpose

int main()
{
    int ip;

    printf("Enter a Integer Number:\n");
    scanf("%d",&ip);

    printf("\nEntered Integer is: %d",ip);

    itoa(ip);

    printf("\nThe Entered Integer Converted to String is: %s\n",s);

    return 0;
}

//defining the recurisve itoa func here
void itoa(int ip)
{
    if(ip<0)
    {
        s[i++]='-';
        sign=-1;
        ip=-ip;
    }

    int c=i++; //maintain a local index where for each number to put in array
    
    if((ip/10)>0)
        itoa(ip/10);
    else
        s[i]='\0'; //done to terminate string with null character so that printing later doesn't cause problems
    
    //i-c-1 is indexing logic for this recursion take example of +ve and test and you'll know 
    //i-c for -ve will become clear if you clear above ;)
    if(sign>0)
        s[i-c-1]=(ip%10)+'0';
    else
        s[i-c]=(ip%10)+'0';
}
