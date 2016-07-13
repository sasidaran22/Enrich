#include <stdio.h>

int main(void) 
{
	// your code goes here
	char str[20],str2[20];
	int len1=0,len2=0,i,j;
	char reverse[20],concat[40];
	scanf("%s",str);
	for(i=0;str[i]!='\0';i++)
	{
	    len1++;
	}
	for(i=0,j=len1-1;i<len1;i++,j--)
	{
	    reverse[i]=str[j];
	}
	reverse[len1]='\0';
	printf("%s\n",reverse);
	//concat
	//get another string as input to concatenate
	scanf("%s",str2);
	for(i=0;str2[i]!='\0';i++)
	{
	    len2++;
	}
	j=0;
	for(i=0;i<len1;i++)
	{
	    concat[j]=str[i];
	    j++;
	}
	for(i=0;i<len2;i++)
	{
	    concat[j]=str2[i];
	    j++;
	}
	concat[j]='\0';
	printf("%s",concat);
	return 0;
}

