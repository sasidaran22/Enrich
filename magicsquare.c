
#include <stdio.h>
void generatematrix(int n)
{ 	int i,j,size,num,matrix[50][50];
  	size=n*n;
  	i=0;j=n/2;//initial element position
  	for(num=1;num<=size;)
  	{
  		if (i==-1&&j==n) 
            {
                j=n-1;
                i=1;
            }
        else
            {
                if (j==n)
                    j=0;
                if (i<0)
                    i=n-1;
            }
        if (matrix[i][j])
            {
                j=j-1;
                i=i+2;
                continue;
            }
        else
            {
                matrix[i][j] = num; 
                num++;
            }
            j++; 
            i--;
  	}
  	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
		{
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}
  	
        
}
  	

int main() 
{
	int i,j,n,mat[n][n];
	printf("Enter the order of the square matrix(only odd number)\n");
	scanf("%d",&n);
	if(n%2==0)
		{printf("Matrix cannot be generated\n");
		}
	else
  		generatematrix(n);
	return 0;
}
