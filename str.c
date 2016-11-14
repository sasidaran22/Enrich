#include <stdio.h>

int main(void) 
{
	
	char str[20],str1[20],temp[5],temp1[5];
	int len=0,flag=0,i;
	scanf("%s %s",str,str1);
	for(i=0;str[i]!='\0';i++)
	{
	    if(str[i]!=str1[i])    
	    {
	        temp[len]=str[i];
	        temp[len+1]='\0';
	        temp1[len]=str1[i];
	        temp1[len+1]='\0';
	        len++;
	        flag=1;
	    }
	    if((str[i]==str1[i])&&(flag==1))
	    {
	        printf("%s,%s\n",temp,temp1);
	        flag=0;
	        len=0;
	    }
	    
	}
	if(len!=0)
	     printf("%s,%s\n",temp,temp1);
	return 0;
}

