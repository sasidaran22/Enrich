#include <stdio.h>
int unique_name=0;
struct resut
{
    char name[50];
    int id[10];
    int num;
}s[6];
int check(int a[],int j,int m)
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
void fun(char str[][10],int arr_id[],int size)
{
    int i,j,num,len,count,temp[size],ind_id=0,n,ind,ind_temp=0;
    for(i=0;i<size;i++)
    {
        temp[i]=-1;
    }
    for(i=0;i<size;i++)
    {
        ind_id=0;len=0;
        if(check(temp,i,ind_temp))
            continue;
        else
        {
            
            s[unique_name].id[ind_id]=arr_id[i];
            ind_id++;
            len=num=0;
            for(j=0;str[i][j]!='\0';j++)
            {
                len++;
            }
            
            for(j=i+1;j<size;j++)
            {
                count=0;ind=-1;
                {
                    for(n=0;str[i][n]!='\0';n++)
                    {
                        if(str[i][n]==str[j][n])
                            count++;
                        else
                            break;
                    }
                }
                if(count==len)
                {
                    num++;
                    ind=j;
                    temp[ind_temp]=arr_id[j-1];//copying the id of repeated names into an array 
                    ind_temp++;
                }
                
                if(ind!=-1)
                {
                    s[unique_name].id[ind_id]=arr_id[j-1]+1;
                    ind_id++;
                }
                
            }
            s[unique_name].num=num+1;
        }
        for(n=0;n<=len;n++)
        {
            s[unique_name].name[n]=str[i][n];
        }
        unique_name++;
    }
}

int main()
{
    char *name[]={"1 B.Raghav","2 Ashok V","3 Raghav Bala","4 Suresh Ramalingam","5 KM.Suresh","6 K.Sasi"};
    int len=0,i,j,k=0,l,f=0;
    char temp[10];
    while(name[len]!=NULL)
    {
        len++;
    }
    int arr_id[len];char f_name[6][10];
    for(i=0;i<len;i++)
    {
        arr_id[i]=name[i][0]-'0';
    }
    for(i=0;i<len;i++)
    {
        k=0;
        for(j=2;name[i][j]!='\0';j++)
        {
            if(name[i][j]=='.')
            {
                k=0;
            }
            else if(name[i][j]==' ')
                break;
            else
            {
                temp[k]=name[i][j];
                temp[k+1]='\0';
                k++;
            }
            
            
        }
        for(l=0;l<k;l++)
        {
            f_name[f][l]=temp[l];
            f_name[f][l+1]='\0';
        }
        f++;
    }
    fun(f_name,arr_id,len);
    for(i=0;i<unique_name;i++)
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
