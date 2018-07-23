#include<stdio.h>
int findpivot(int a[], int l ,int h)
{
	int mid=(l+h)/2;
	if(l>h)
	return -1;
	if(l==h)
	return l;
	if(mid<h&&a[mid]>a[mid+1])
	return mid;
	if(mid>l&&a[mid]<a[mid-1])
	return mid-1;
	else if(a[mid]>=a[h])
	findpivot(a,mid+1,h);
	else 	findpivot(a,l,mid-1);
	
}
int BinarySearch(int a[], int l, int h, int key)
{
		int mid=(l+h)/2;
		if(key==a[mid])
		{
			printf("mid:%d\n",mid);
		return mid;
	}
		else if(key<a[mid])
		BinarySearch(a,l,mid-1,key);
		else
			BinarySearch(a,mid+1,l,key);
}
int pivotedBinarySearch(int a[],int l, int h, int key)
{
	
	int mid,pivot;
	pivot=findpivot(a,l,h);
	printf("pivot:%d\n",a[pivot]);
	if(pivot==-1)
	return;
	if(a[pivot]==key)
	return pivot;
	else if(key<a[pivot]&&key>=a[l])
	return BinarySearch(a,l,pivot-1,key);
	else
	return BinarySearch(a,pivot+1,h,key);
	
}
int main()
{
	int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
   int n = sizeof(arr1)/sizeof(arr1[0]);
   int key = 5;
   printf("Index: %d\n", pivotedBinarySearch(arr1,0,  n-1, key)+1);
   return 0;
}
