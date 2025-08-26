#include<stdio.h>
int main()
{
	int i, n, j, sum=0;
	printf("Enter the no of iterations you'd like:");
	scanf("%d",&n);
	int a[n+1];
	a[0]=1;
	for(i=1; i<n;i++){
		for(j=0;j<i;j++){
			sum+=a[j];
		}
		a[i]=sum;
		sum=0;
	}
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
}

