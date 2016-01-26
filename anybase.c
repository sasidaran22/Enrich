#include <stdio.h>

int main(void)
{
	int num,base;
	printf("Enter the number and the base\n\n");
	scanf("%d%d",&num,&base);
	convert(num,base);
	return 0;
}
int convert(int num,int base)
{
    int i=0,j,result[60],rem;
    while(num>0)
    {
        rem=num%base;
        if(rem<10)
        {
            result[i]=rem+48;
        }
        else
            result[i]=rem+55;
        num=num/base;
        i++;
    }
    for(j=i-1;j>=0;j--)
    {
        printf("%c ",result[j]);
    }
    return 0;
}

