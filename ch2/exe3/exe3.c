/*Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F*/

#include<stdio.h>
#include<ctype.h>// for using inbuilt functions like islower
#define max 12
int htoi(char hex[]);
int main()
{
        int i;
        char c;
        int ans;
        char str[max];
        printf(" enter a hex no. between 0x0 to 0xffffffff\n");
        for(i=0; (c=getchar())!=EOF&& c!='\n' ;i++)
        {
                        str[i]=c;
        }
        str[++i]='\0';
        ans=htoi(str);
        if(ans != -1)
        {
                printf("%d\n",ans);
        }
}

int htoi(char h[])
{
        int digit,i,total;
        i=0;
        total=0;
        digit=0;
        if (h[0]=='0' && (h[1]=='x' || h[1]=='X'))
        {
                for (i=2;h[i]!='\0';i++)
                {
                        if(h[i] >='0' &&h[i]<='9')
                        {
                                digit=h[i]-'0';
                        }
                        else if(h[i]>='a' &&h[i]<='f')
                        {
                                digit=h[i]-'a' +10;
                        }
                        else if(h[i]>='A' && h[i]<='F')
                        {
                                digit=h[i]-'A'+10;
                        }
                        else
                        {
                                printf("invalid hex1\n");
                                return -1;
                                                        }
                        total=(total*16)+digit;
                }

        }
        else
        {
                for (i=0;h[i]!='\0';i++)
                {
                        if(h[i] >='0' &&h[i]<='9')
                        {
                                digit=h[i]-'0';
                        }
                        else if(h[i]>='a' &&h[i]<='f')
                        {
                                digit=h[i]-'a' +10;
                        }
                        else if(h[i]>='A' && h[i]<='F')
                        {
                                digit=h[i]-'A'+10;
                        }
                        else
                        {
                                printf("invalid hex2\n");
                                return -1;
                        }
                        total=(total*16)+digit;
                }
        }
return total;
}

