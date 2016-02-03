#include<stdio.h>
int nextprime(int);

int main()
{
    int num;
    printf("Enter the number\n");
    scanf("%d",&num);
    if(num%2==0)
        {
            num=num+1;
        }
    else
        num+=2;

    while(1)
	    {
		      if(nextprime(num))
			        break;
		      num+=2;
	    }
	printf("The next prime number is %d\n",num);
	return 0;
}
int nextprime(int n)
{
    int i;
	for(i=2;i<=n/2;i++)
	{
		if(n%i==0)
			return 0;
	}
	return 1;

}
