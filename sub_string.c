// largest substring and print its length
#include<stdio.h>
int main()
{
    char str[20],res[20],temp;
    int i,j,count=0,n=0;
    printf("Enter the string\n");
    scanf("%s",str);
    printf("The string is %s\n",str);

    for(i=0;str[i]!='\0';i++)
    {
        for(j=i;str[j]!='\0';j++)
        {
            if (str[i]==str[j])
            {
                count++;
                temp=str[i];
            }

        }
        if(count==1)
        {
            res[n]=temp;
            n++;
        }
        count=0;
    }
    res[n]='\0';
    printf("The longest sub-string without repetition is %s\n",res);

    printf("The length of longest sub-string is %d\n",n);

    return 0;
}
