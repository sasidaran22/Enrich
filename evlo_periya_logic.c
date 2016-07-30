#include <stdio.h>
#include<math.h>
int is_power_num(int num,int power[],int ind)
{
    int temp=0,count=0,i;
    power[ind]=num+1;
    ind++;
    while(num>0)
    {
        for(i=0;power[i]<=num;i++)
        {
            temp=power[i];
            
        }
        count++;
        num=num-temp;
        
    }
    if(count<=2)
        return 1;
    return 0;
    
}
int main(void) {
	// your code goes here
	int l,r,power[100],ind=1,i,j,temp;
	scanf("%d %d",&l,&r);
	power[0]=1;
	for(i=2;i<=r;i++)
	{
	    for(j=2;pow(i,j)<=r;j++)
	    {
	        power[ind]=pow(i,j);
	        ind++;
	    }
	}
	for(i=0;i<ind;i++)
	{
	    for(j=i+1;j<ind;j++)
	    {
	        if(power[i]>power[j])
	        {
	            temp=power[i];
	            power[i]=power[j];
	            power[j]=temp;
	        }
	    }
	}
	/*for(i=0;i<ind;i++)
	{
	    printf("%d ",power[i]);
	}*/
	for(i=l;i<=r;i++)
	{
	    if(is_power_num(i,power,ind))
	        printf("%d ",i);
	}
	
	return 0;
}

