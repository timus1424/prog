#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#define MAX 5000
#define MIN 100
int partition(int a[], int lb, int ub){
	int pivot=a[lb];
	int start=lb, end=ub;
	while (start<end){
		while(a[start]<=pivot)
			start++;
		while(a[end]>pivot)
			end--;
		if(start<end){
			int temp=a[start];
			a[start]=a[end];
			a[end]=temp;
		}
	}
	int temp2=a[lb];
	a[lb]=a[end];
	a[end]=temp2;
	return end;
}
void quickSort(int arr[], int lb, int ub){
	if(lb<ub){
		int loc=partition(arr, lb, ub);
		quickSort(arr, lb, loc-1);
		quickSort(arr, loc+1, ub);	
	}
}

int main(){
int n=50000, arr[n];
clock_t start, end, start1, end1;
double cpu_time, cpu_time1, cpu_time2;
for(int i=0;i<n;i++)
	arr[i]=rand()%(MAX+MIN-1)+MIN;
start=clock();
quickSort(arr, 0, n-1);
end=clock();
cpu_time=((double)(end-start)/CLOCKS_PER_SEC);
printf("Best case time :%f \n", cpu_time);
start1=clock();
quickSort(arr, 0, n-1);
end1=clock();
cpu_time1=((double)(end1-start1)/CLOCKS_PER_SEC);
printf("Worst Case time :%f \n", cpu_time1);
cpu_time2=(cpu_time+cpu_time1)/2;
printf("Average Case time :%f \n", cpu_time2);
return 0;
}
