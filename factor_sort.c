#include <stdio.h>
int fac(int );
int main() 
{
    int a[20],size,i,j,temp;
    printf("Enter the number of elements\n");
    scanf("%d",&size);
    printf("Enter the elements\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<size;i++)
    {
        for(j=i;j<size;j++)
        {
            if(fac(a[i])<fac(a[j]))
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("The sorted array is\n");
    for(i=0;i<size;i++)
    {
        printf("%d  ",a[i]);
    }
}
int fac (int num)
{
    int i,count=0;
    for(i=1;i<=num;i++)
    {
        if((num%i)==0)
            count++;
        
    }
    return count;
}
