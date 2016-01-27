#include <stdio.h>

int main()
{
	long int num,bit;
	printf("Enter the number\n");
	scanf("%ld",&num);
	printf("The binary form of the number is\n");
	getbin(num);
	printf("--Rotate right--\n");
	rightshift(num);
	printf("--Rotate left--\n");
	leftshift(num);
	printf("Swapping the nibbles\n");
	swapnibbles(num);
	printf("Enter the bit to be set,masked and toggled\n");
	scanf("%ld",&bit);
	bit_toggle_operation(num,bit);
	return 0;
}

void getbin(int num)
{
    long int res=0,rem,i=1;
    while(num!=0)
    {
        res=res+(i*(rem=num%2));
        num=num/2;
        i=i*10;
    }
    printf("%ld\n",res);
    
}

void rightshift(int num)
{
    long int ans;
    num=num>>1;
    ans=num|((num&1)<<7);
    getbin(ans);
    printf("%ld\n",ans);
    
}

void leftshift(int num)
{
    long int ans;
    num = num<<1;
    ans=num|((num&255)>>7);
    getbin(ans);
    printf("%ld\n",ans);
    
}

void bit_toggle_operation(int num,int bit)
{
    long int temp=1<<bit;
    printf("Setting the bit\n");
    num=num|temp;
    getbin(num);
    printf("%ld\n",num);

    printf("Masking the bit\n");
    temp=~temp;
    num=num&temp;
    getbin(num);
    printf("%ld\n",num);

    printf("Toggling the bit\n");
    num=num^~temp;
    getbin(num);
    printf("%ld\n",num);

    printf("Toggling except the bit\n");
    temp=~temp;
    num=num^255;
    num=num|temp;
    getbin(num);
    printf("%ld\n",num);
    
}
void swapnibbles(int num)
{
    long int ans;
    ans=(((num<<4)|(num>>4))&255);
    getbin(ans);
    printf("%ld\n",ans);
    
}
