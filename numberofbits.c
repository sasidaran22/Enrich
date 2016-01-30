#include <stdio.h>
#include<math.h>

int main(void)
{
    int num,i;
    printf("Enter the number\n");
    scanf("%d",&num);
    if(num!=0)
    {
        for(i=0;pow(2,i)<=num;)
            {
                i++;
            }
        printf("Tne number of required bits is %d",i);  
    }
    else
        printf("0");
    return 0;
}
