#include<stdio.h>
#include<stdlib.h>
void reverse(char *begin, char *end)
{
  char temp;
  while (begin < end)
  {
    temp = *begin;
    *begin++ = *end;
    *end-- = temp;
  }
}
void reverseword(char *a)
{
	char *t=a,*g;
	g=NULL;

while( *t )
    {
    	if (( g == NULL ) && (*(t+1 )!= ' ') )
        {
            g=t;
        }
        if(g &&((*(t+1) == ' ') || (*(t+1) == '\0')))
        {
        	reverse(g,t);
        	g=NULL;
		}
		t++;
    }
reverse(a, t-1);
}
int main()
{
	char a[]="i am neha kumari singh";

	printf("%s\n",a);
	reverseword(a);
		printf("%s\n",a);
	return 0;
}
