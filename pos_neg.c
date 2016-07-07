#include <stdio.h>

int main(void) 
{
	// your code goes here
	int input[20],a[20],b[20],res[20];
	int i,j,a_index=0,b_index=0,res_index,n,temp;
	printf("Enter the total count of numbers\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	    scanf("%d",&input[i]);
	}
	for(i=0;i<n;i++)
	{
	    if(input[i]>0)
	    {
	        a[a_index]=input[i];
	        a_index++;
	    }
	    else
	    {
	        b[b_index]=input[i];
	        b_index++;
	     }
	}
	
	//sorting positive numbers in ascending order
	for(i=0;i<a_index;i++)
	{
	    for(j=i;j<a_index;j++)
	    {
	        if(a[i]>a[j])
	        {
	            temp=a[i];
	            a[i]=a[j];
	            a[j]=temp;
	        }
	    }
	}
	//sorting negative numbers in descending order
	for(i=0;i<b_index;i++)
	{
	    for(j=i;j<b_index;j++)
	    {
	        if(b[i]<b[j])
	        {
	            temp=b[i];
	            b[i]=b[j];
	            b[j]=temp;
	        }
	    }
	}
	//copying in required order to result array
	res_index=0;
	for(i=0;i<a_index;i++)
	{
	    res[res_index]=a[i];
	    res_index+=2; //skipping odd indexes
	}
	res_index=1;
	for(i=0;i<b_index;i++)
	{
	    res[res_index]=b[i];
	    res_index+=2; //skipping even indexes
	}
	//printing the result array
	for(i=0;i<n;i++)
	{
	    printf("%d ",res[i]);
	}
	return 0;
}

