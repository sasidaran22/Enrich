#include <stdio.h>
#include <math.h>
int isvalid(double a, double b, double c)
{
	if((a!=0)&&(b!=0)&&(c!=0))
		return 1;
	else
		return 0;
}
int main() 
{
	
	int x1,x2,y1,y2,z1,z2;
	double a,b,c,side1,side2,side3,temp,rad1,rad2,perimeter,result;
	scanf("%d %d",&x1,&x2);
	scanf("%d %d",&y1,&y2);
	scanf("%d %d",&z1,&z2);
	//using distance formula
	a=(double)(((x1-y1)*(x1-y1))+((x2-y2)*(x2-y2)));
	b=(double)(((y1-z1)*(y1-z1))+((y2-z2)*(y2-z2)));
	c=(double)(((z1-x1)*(z1-x1))+((z2-x2)*(z2-x2)));
	side1=sqrt(a);
	side2=sqrt(b);
	side3=sqrt(c);
	if(isvalid(side1,side2,side3))
	{
		temp=sqrt((side1+side2+side3)*(side2+side3-side1)*(side3+side1-side2)*(side1+side2-side3));
    	rad1=(side1*side2*side3)/temp;
    	perimeter=(side1+side2+side3)/2;
		rad2=(2*sqrt(perimeter*(perimeter-side1)*(perimeter-side2)*(perimeter-side3)))/(side1+side2+side3);
		result=3.14159265358979323846*((rad1*rad1)-(rad2*rad2));
		printf("%.2lf",result);
	}
    else
		printf("Not Possible");
	return 0;
}
