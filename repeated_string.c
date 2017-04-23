#include <stdio.h>


char fun(int ind, int letters[])
{
    int i;
    for(i=ind+1;i<26;i++)
    {
        if(letters[i]==0)
        {
            letters[i]++;
            return i+'a';
        }
    }
}

char fun2(int ind, int numbers[])
{
    int i;
     for(i=ind+1;i<9;i++)
     {
        if(numbers[i]==0)
        {
            numbers[i]++;
            return i+'0';
        }
     }
    
}

int main(void) 
{
	// your code goes here
	char str[100]; char res[1000];
	scanf("%s",str);
	int letters[26] = {0}, numbers[9]={0},i,j, index=0;
	for(i=0;str[i]!='\0';i++)
	{
	    if((str[i]>='a')&&(str[i]<='z'))
	    {
	        if(letters[str[i]-'a'] == 0)
	        {
	            res[index] = str[i];
	            index++;
	            letters[str[i]-'a']++;
	        }
	        else
	        {
	            res[index] = fun(str[i]-'a',letters);
	            index++;
	        }
	    }
	    else
	    {
	        if(numbers[str[i]-'0'] == 0)
	        {
	            res[index] = str[i];
	            index++;
	            numbers[str[i]-'0']++;
	        }
	        else
	        {
	            res[index] = fun2(str[i]-'0' , numbers);
	            index++;
	        }
	    }
	}
	res[index] = '\0';
	printf("Result is %s",res);
	return 0;
}

