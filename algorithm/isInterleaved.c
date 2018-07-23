#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isInterleaved( char *A, char *B, char *C)
{
	
	while(*C!='\0')
	{
		if(*C==*A)
		A++;
		else if(*C==*B)
		B++;
		else 
		return 0;
		C++;
	}
	if(*A!='\0'||*B!='\0')
	return 0;
	
	return 1;
}
int main()
{
	 char *A = "AB";
    char *B = "CD";
    char *C = "ACBDD";
    int x=isInterleaved(A, B, C);
    if (x!=0)
        printf("%s is interleaved of %s and %s", C, A, B);
    else
        printf("%s is not interleaved of %s and %s", C, A, B);
 
    return 0;

}
