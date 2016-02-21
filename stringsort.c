#include<stdio.h>

int fun(char str[])
{
    int i,sum=0;
    for(i=0;str[i]!='\0';i++)
    {
        sum=sum+str[i];
    }
    return sum;
}
int main()
{
    int i,j;
    char *num[]= {"1", "3", "11", "100", "19", "2", "5"},*tmp;
    int n=sizeof(num)/sizeof(num[0]);
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if (fun(num[i])>fun(num[j]))
            {
                tmp=num[i];
                num[i]=num[j];
                num[j]=tmp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%s  ",num[i]);
    }
    return 0;
}
