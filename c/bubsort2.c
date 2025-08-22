// flawed

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
	for(i=0;i<n-1;i++) 
        {
		int flag=0;
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]<a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j]=temp;
				flag++;
			}
		}
		if(flag==0)
			break;
	}
	printf("Sorted Array: \n");
	for(i=0;i<n;i++) 
        {
		printf("%d \t",a[i]);
	}
	printf("\n");
	return 0;
}
