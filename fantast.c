#include <stdio.h>

int main(void) 
{
	// your code goes here
	int arr[20],n,i,j,sum,flag1=0,flag2=0,prod;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	    scanf("%d",&arr[i]);
	}
	sum=arr[0];
	for(i=1;i<n;i++)
	{
	    if(arr[i]<sum)
	    {
	        flag1=1;
	        break;
	    }
	    sum=sum+arr[i];
	}
	prod=arr[0];
	for(i=1;i<n;i++)
	{
	    if(arr[i]<prod)
	    {
	        flag2=1;
	        break;
	    }
	    prod=prod*arr[i];
	}
	
	if(flag1==1)
	    printf("Not Fantastic array\n");
	else
	    printf("Fantastic array\n");
	
	if(flag2==1)
	    printf("Not Fabulous array\n");
	else
	    printf("Fabulous array\n");
	    
	 if((flag1==0)&&(flag2==0))
	    printf("Fantabulous array\n");
	return 0;
}

