#include<stdio.h>
#include<string.h>
void checkpal(char* a,char* res)
{

    char temp[100],temp1[100]={};
    int i,l1,l2,j=0;
    strcpy(temp,a);

    strrev(temp);
    if (strcmp(a,temp) != 0)
    {
        strcpy(temp1,a);

    }
    l1=strlen(temp1);
    l2=strlen(res);
    for(i=l2;i<(l1+l2);i++)
    {
        res[i]=temp1[j];
        j++;

    }
    res[i+1]='\0';
}
int main()
{
    char str[100],tmp[100],res[100]={};
    int i,k=0,len;
    printf("Enter the sentence\n");
    gets(str);
    len=strlen(str);
    str[len]=' ';
    str[len+1]='\0';
    for(i=0;str[i]!='\0';i++)
    {

        if(str[i]!=' ')
        {
            tmp[k]=str[i];
            tmp[k+1]='\0';
            k++;
        }
        else
        {

            checkpal(tmp,res);
            len=strlen(res);
            res[len]=' ';
            res[len+1]='\0';
            k=0;

        }
    }
    printf("The sentence without palindrome words is\n");
    puts(res);

    return 0;
}
