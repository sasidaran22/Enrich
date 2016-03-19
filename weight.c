#include <stdio.h>
int tot=0;
int flag=1;
struct products
{
    float weight;
    float cost;
    int total;
    float cost_kg;
};
struct result
{
    int weightt;
    int costt;
    int count;
}r[5];
void fun(int *w, int *c, struct products p[],int num, int wt)
{
    int i,ind=-1,total=0;
    int temp;float max=0;
    for(i=0;i<num;i++)
    {
        if((p[i].cost_kg>max)&&(p[i].total!=0)&&(p[i].weight<wt))
        {
            ind=i;
            max=p[i].cost_kg;
        }
        
    }
    if(ind!=-1)
    {
        r[tot].weightt=p[ind].weight;
        r[tot].costt=p[ind].cost;
        temp=p[ind].weight;
        for(i=1;wt>=(temp*i);i++)
        {
            if(p[ind].total!=0)
            {
                total++;
                p[ind].total--;
            }
        }
        r[tot].count=total;
        (*w)+=(temp)*total;
        (*c)+=total*p[ind].cost;
        tot++;
    }
    else
        flag=0;
}
int main(int argc, const char * argv[])
{
    int i,wt,num,total_wt=0,total_cost=0,temp=0;
    printf("Enter the max weight of the bag\n");
    scanf("%d",&wt);
    printf("Enter the total number of available products\n");
    scanf("%d",&num);
    struct products p[num];
    printf("Enter the weight, cost and count of the individual product\n\n\n");
    for(i=0;i<num;i++)
    {
        printf("Enter the weight of product %d\n",(i+1));
        scanf("%f",&p[i].weight);
        printf("Enter the cost of product per given weight\n");
        scanf("%f",&p[i].cost);
        printf("Enter the total number of such products\n");
        scanf("%d",&p[i].total);
        p[i].cost_kg=(p[i].cost)/(p[i].weight);

    }
    printf("Showing details..\n\n");
    for(i=0;i<num;i++)
    {
        printf("\t\t\tProduct %d\n",(i+1));
        printf("Weight->%f  Cost->%f  Total->%d\n\n",p[i].weight,p[i].cost,p[i].total);
        
    }
    temp=wt-total_wt;
    while((temp>0)&&(flag==1))
    {
        fun(&total_wt,&total_cost,p,num,temp);
        temp=wt-total_wt;
    }
    for(i=0;i<tot;i++)
    {
        printf("The weight %dkg of cost Rs.%d occurs %d times\n",r[i].weightt,r[i].costt,r[i].count);
    }
    printf("The total cost is %d and total_wt is %d\n",total_cost,total_wt);

    return 0;
}
