#include<stdio.h>
#include<string.h>
void compare(char* temp,char* res)
{
    if(strlen(temp)>strlen(res))
    {
        strcpy(res,temp);
    }
}
int main()
{
    char str[30],res[30]={},temp[30];
    int i,j,k=1,count=1;
    scanf("%s",str);
    printf("The string is %s\n\n",str);
    for(i=1;str[i]!='\0';i++)
    {
        if(count!=0)
        {

            temp[k-1]=str[i-1];
            temp[k]='\0';
            count=0;
        }

        for(j=0;temp[j]!='\0';j++)
        {
            if(str[i]==temp[j])
            {
                count++;
            }

        }
        if(count==0)
        {
            temp[k]=str[i];
            k++;
            temp[k]='\0';
            compare(temp,res);
        }
        else
        {
            compare(temp,res);
            k=1;
        }
    }
    printf("The longest sub-string without repitition is %s\n",res);
    printf("The length of the string is %d\n",strlen(res));

    return 0;
}
