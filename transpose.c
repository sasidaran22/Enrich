#include <stdio.h>

int main(void) {
	int i,j,n,a[10][10],t=0;
	printf("Enter the order\n");
	scanf("%d",&n);
	
	
	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
	        scanf("%d",&a[i][j]);
	       }
	}
	
	
	printf("The square matrix is\n");
	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
	        printf("%d   ",a[i][j]);
	       }
	    printf("\n");
	    
	}
	
	for(i=1;i<n;i++){
	    for(j=0;j<i;j++){
	    t=a[i][j];
	    a[i][j]=a[j][i];
	    a[j][i]=t;
	    }
	}
	
	printf("The transposed square matrix is \n");
	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
	        printf("%d   ",a[i][j]);
	       }
	    printf("\n");
	    
	}
	
	    
	return 0;
}

