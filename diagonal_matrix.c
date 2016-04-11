#include <stdio.h>

int main(void) 
{
	// your code goes here
	int a[10][10],order,i,j,sum1=0,sum2=0;
	printf("Enter the order of the matrix\n");
	scanf("%d",&order);
	printf("Enter the elements\n");
	for(i=0;i<order;i++)
	{
	    for(j=0;j<order;j++)
	    {
	        scanf("%d",&a[i][j]);
	    }
	}
	printf("Displaying the matrix..\n\n");
	for(i=0;i<order;i++)
	{
	    for(j=0;j<order;j++)
	    {
	        printf("%d  ",a[i][j]);
	    }
	    printf("\n");
	}
	for(i=0;i<order;i++)
	{
	    for(j=0;j<order;j++)
	    {
	        if(i==j)
	            sum1=sum1+a[i][j];
	        if((i+j)==(order-1))
	            sum2=sum2+a[i][j];
	    }
	}
	printf("%d %d\n",sum1,sum2);
	printf("The required answer is %d\n",abs(sum1-sum2));
	return 0;
}

