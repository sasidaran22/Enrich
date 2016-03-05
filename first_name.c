#include <stdio.h>
int total=0;
struct stud
{
    char name[50];
    int id[10];
    int num;
}s[6];
int fun1(int a[],int j,int m)
{
    int i,flag=0;
    for(i=0;i<m;i++)
    {
        if(a[i]==j)
            flag=1;
    }
    if(flag==1)
    {
        
        return 1;
    }
    else
        return 0;
}
void fun(char str[][10],int m)
{
    int i,j,flag,len,count,temp[m],ind_s=0,n,ind,ind_t=0;
    for(i=0;i<5;i++)
    {
        temp[i]=-1;
    }
    for(i=0;i<m;i++)
    {
        ind_s=0;len=0;
        if(fun1(temp,i,ind_t))
            continue;
        else
        {
            
            s[total].id[ind_s]=i+1;
            ind_s++;
            len=flag=0;
            for(j=0;str[i][j]!='\0'&&str[i][j]!=' ';j++)
            {
                len++;
            }
            
            for(j=i+1;j<m;j++)
            {
                count=0;ind=-1;
                {
                    for(n=0;str[i][n]!='\0';n++)
                    {
                        if(str[i][n]==str[j][n])
                        {
                            
                            count++;
                            
                        }
                        else
                            break;
                    }
                }
                if(count==len)
                {
                    flag++;
                    ind=j;
                    temp[ind_t]=j;
                    ind_t++;
                }
                
                if(ind!=-1)
                {
                    s[total].id[ind_s]=j+1;
                    ind_s++;
                }
                
            }
            s[total].num=flag+1;
        }
        for(n=0;n<=len;n++)
        {
            s[total].name[n]=str[i][n];
        }
        total++;
    }
}

int main()
{
    char *name[]={"B.Raghav","Ashok V","Raghav Bala","Suresh Ramalingam","KM.Suresh","K.Sasi"};
    int len=0,i,j,k=0,l,f=0;
    char f_name[6][10];
    char temp[10];
    while(name[len]!=NULL)
    {
        len++;
    }
    for(i=0;i<len;i++)
    {
        k=0;
        for(j=0;name[i][j]!='\0';j++)
        {
            temp[k]=name[i][j];
            temp[k+1]='\0';
            k++;
            if(name[i][j]=='.')
            {
                k=0;
            }
            else if(name[i][j]==' ')
                break;
            
        }
        for(l=0;l<k;l++)
        {
            f_name[f][l]=temp[l];
            f_name[f][l+1]='\0';
            
        }
        f++;
    }
    
    fun(f_name,len);
    for(i=0;i<total;i++)
    {
        printf("%s,%d,[ ",s[i].name,s[i].num);
        for(j=0;j<s[i].num;j++)
        {
            printf("%d ",s[i].id[j]);
        }
        printf(" ]\n");
    }
    return 0;
}
