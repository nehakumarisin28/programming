#include<stdio.h>
typedef struct node
{
	int petrol,distance;
}node;
int printTour(node arr[],int n)
{
	int strt=0,end=1,cur_petrol=0;
	cur_petrol=arr[strt].petrol-arr[strt].distance;
	while(cur_petrol<0||strt!=end)
	{
		while(strt!=end&&cur_petrol<0)
		{
			cur_petrol-=arr[strt].petrol-arr[strt].distance;
			strt=(strt+1)%n;
			if(strt==0)
			return -1;
		}
		cur_petrol+=arr[end].petrol-arr[end].distance;
		end=(end+1)%n;
	}
	return strt;
}
int main()
{
	 node arr[] = {{4, 6}, {6, 5}, {7, 3} , {4, 5}};
 
    int n = sizeof(arr)/sizeof(arr[0]);
    int start = printTour(arr, n);
 
    (start == -1)? printf("No solution"): printf("Start = %d", start);
 
    return 0;
}
