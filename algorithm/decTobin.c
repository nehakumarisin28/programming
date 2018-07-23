#include<stdio.h>
void binary(int n)
{
	int x,j=1,y=0;
	while(n!=0)
	{
		x=n%2;
		y+=x*j;
		j=j*10;
		n=n/2;
	}
	printf("%d\n",y);
}
void decimalToBi(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		binary(i);
	}
}
int main()
{
	int n;
	printf("enter number\n");
	scanf("%d",&n);
	decimalToBi(n);
	return 0;
}
