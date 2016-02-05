#include<stdio.h>
int main()
{
    int num,n;
    printf("Enter the number\n");
    scanf("%d",&num);
    n=num;

    if(num==2||num==4||num==6||num==1)
        printf("Next prime is %d\n",++num);
    else if(num==3||num==5||num==0)
        printf("Next prime is %d\n",(num+2));


    n++;

    while(n>7)
    {
       if((n%2!=0)&&(n%3!=0)&&(n%5!=0)&&(n%7!=0))
       {
           printf("Next prime is %d\n",n);
           return 0;
        }
       else
         n++;
    }

}
