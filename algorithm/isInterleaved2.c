#include<stdio.h>
#include<string.h>
int isInterleaved(char *A,char *B,char *C)
{
	int len1,len2,len3;
	len1=strlen(A);
	len2=strlen(B);
	len3=strlen(C);
	if(len3>(len1+len2))
	return 0;
	int i,j,t[len1+1][len2+1];
	for(i=0;i<=len1;i++)
	{
		for(j=0;j<=len2;j++)
		{
			t[i][j]=0;
			if(i==0&&j==0)
			t[i][j]=1;
			
			else if(i==0&&B[j-1]==C[i+j-1])
			t[i][j]=t[i][j-1];
			
			 else if (j==0 && A[i-1]==C[i-1])
                t[i][j] = t[i-1][j];
 
			
			else if(A[i-1]==C[i+j-1]&&B[j-1]!=C[i+j-1])
				t[i][j]=t[i-1][j];
				
			else if(A[i-1]!=C[i+j-1]&&B[j-1]==C[i+j-1])
				t[i][j]=t[i][j-1];
				
			else if(A[i-1]==C[i+j-1]&&B[j-1]==C[i+j-1])
				t[i][j]=t[i-1][j];
		}
	}
	return t[len1][len2];
	
}
int main()
{
	char *str1="AB";
	char *str2="CD";
	char *str3="CDBA";
	int x=isInterleaved(str1,str2,str3);
	if(x==1)
	printf("%s is interleaved of %s and %s\n",str3,str1,str2);
	else
		printf("%s is not  interleaved of %s and %s\n",str3,str1,str2);
	return 0;
	
	
	
}
