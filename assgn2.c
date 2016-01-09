#include<stdio.h>
int main()
{
    int i,j,odd=1,even=2;
    for(i=1;i<=6;i=i+2)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d\t",odd);
            odd+=2;
        }
        printf("\n");
        for(j=1;j<(i+2);j++)
        {
            printf("%d\t",even);
            even+=2;
        }
        printf("\n");
    }
    return 0;
}
