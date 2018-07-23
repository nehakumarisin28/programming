#include<stdio.h>
#include<string.h>
void divideString(char str[],int n)
{
	int size=strlen(str);
	int k,i;
	if(size%n!=0)
	{
		printf("invalid divide size\n");
		return;
	}
	k=size/n;
	for(i=0;i<size;i++)
	{
	if((i%k)==0)
	printf("\n");
	printf("%c",str[i]);
}
}
int main()
{
	char str[]="neha_kumari_sing";
	divideString(str,4);
	return 0;
}
