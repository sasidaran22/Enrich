#include<stdio.h>
int flag;
struct input
{
    int y;
    int m;
    int d;
    
}x;
char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
char *week[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
int isleap(int year)
{
    if((year%4==0)&&(year%100==0))
        return 1;
    else if((year%4==0)&&(year%100!=0))
        return 1;
    else
        return 0;
}

int findnum(char a[],int m,int n)
{
    int res=0,i;
    for(i=m;i<=n;i++)
    {
        res=(res*10)+(a[i]-'0');
    }
    return res;
}

int findindex()
{
    
    int i,res=0,year=x.y,month=x.m,day=x.d;
    if(isleap(year))
    {
        days[1]=29;
    }
    for(i=0;i<(month-1);i++)
    {
        res+=days[i];
    }
    
    return (res+day);
}
void numtochar(char str[],int m,int n,int num)
{
    int i,temp;
    for(i=n;i>=m;i--)
    {
        temp=num%10;
        num/=10;
        str[i]=(temp+'0');
    }
}


void date_before_n_days(int n,char str[])
{
    int new_date,new_month,new_year,count=0,year=x.y,month=x.m,day=x.d;
    new_month=month;
    new_year=year;
    if((day-n)<1)
    {
        count=count+day;
        while(count<=n)
        {
            if (isleap(new_year))
                days[1]=29;
            else
                days[1]=28;
            
            if((month-1)==0)
            {
                month=12;
                new_month=12;
                new_year--;
            }
            else
            {
                new_month--;
                month--;
            }
            count=count+days[month-1];
            
        }
        new_date=count-n;
    }
    else
        new_date=day-n;
    numtochar(str,0,3,new_year);
    numtochar(str,5,6,new_month);
    numtochar(str,8,9,new_date);
    str[4]=str[7]='-';
    str[10]='\0';
}
int diff(char b[])
{
    int y2,mon2,day2,res,t,year=x.y,month=x.m,day=x.d;
    y2=findnum(b,0,3);
    day2=findnum(b,8,9);
    mon2=findnum(b,5,6);
    flag=1;
    if((y2>year)||(mon2>month)||(day2>day))
    {
        flag=-1;
        t=year;
        year=y2;
        y2=t;
        t=month;
        month=mon2;
        mon2=t;
        t=day;
        day=day2;
        day2=t;
    }
    res=day;
    while(1)
    {
        if(((year-y2)!=0)||(month-mon2)!=0)
        {
            if (isleap(year))
                days[1]=29;
            else
                days[1]=28;
            
            if((month-1)==0)
            {
                month=12;
                year--;
            }
            else
            {
                month--;
            }
            res+=days[month-1];
            
        }
        else
            break;
    }
    res-=day2;
    return res;
    
}

int findweek_day()
{
    int result;
    char str[]="2015-02-21";
    result=diff(str);
    result%=7;
    if (flag==1)
        return result;
    else
        return (6-result);
}
int main()
{
    
    char a[11],b[11],new_date[11];
    int index,n,difference;
    printf("Enter a valid date\n");
    scanf("%s",a);
    x.y=findnum(a,0,3);
    printf("The current year is %d\n",x.y);
    printf("The previous year is %d\n",(x.y-1));
    x.m=findnum(a,5,6);
    printf("The current month is(in number) %d\n",x.m);
    printf("The current month is(in words) %s\n",months[x.m-1]);
    if(x.m!=1)
        printf("The previous month is(in words)%s \n",months[x.m-2]);
    else
        printf("The previous month is(in words)%s \n",months[11]);
    x.d=findnum(a,8,9);
    printf("The day in number is %d\n",x.d);
    index=findindex();
    printf("The index of the date is %d\n",index);
    index=findweek_day();
    printf("The day of given date is %s\n",week[index]);
    printf("Enter the number whose previous date is to be found\n");
    scanf("%d",&n);
    date_before_n_days(n,new_date);
    printf("The date before %d days is %s\n",n,new_date);
    printf("Enter the another date \n");
    scanf("%s",b);
    difference=diff(b);
    printf("The difference is %d\n",difference);
    return 0;
}
