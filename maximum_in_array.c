#include <stdio.h>
int maxdifference(int arr[],int n)
{
    int i,j,max=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            
            if(arr[i]<arr[j])
            {
                
                if((arr[j]-arr[i])>max)
                    max=arr[j]-arr[i];
            }
            
        }
    }
    if(max>0)
        return max;
    else
        return -1;
    
}

int main(void) 
{
	// your code goes here
	int arr[100];
	int i,n,result;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	    scanf("%d",&arr[i]);
	}
	result=maxdifference(arr,n);
	printf("%d",result);
	return 0;
}

