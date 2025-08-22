#include<stdio.h>
int main(){
	int n,i,j,temp;
	printf("Enter your array size and elements : \n");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{	
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++) 
        {
		for(j=0;j<n-1;j++)
		{
			if(a[i]<a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("Sorted Array: \n");
	for(i=0;i<n;i++) 
        {
		printf("%d \t",a[i]);
	}
	printf("\n");
	return 0;
}
