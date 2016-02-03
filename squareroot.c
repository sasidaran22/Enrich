#include<stdio.h>
int main()
{
  int n;
  printf("Enter the number\n");
  scanf("%d",&n);
  float x=n,y=1;
  float e=0.000001;
  while((x-y)>e)
  {
    x=(x+y)/2;
    y=n/x;
  }
  printf("The square root of the number is %f\n",x);
  return 0;
}
