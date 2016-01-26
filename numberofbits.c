#include <stdio.h>
#include<math.h>

int main(void)
{
    int num,i;
    printf("Enter the number\n");
    scanf("%d",&num);
    for(i=0;pow(2,i)<=num;)
    {
        i++;
    }
    printf("Tne number of required bits is %d",i);
    return 0;
}
