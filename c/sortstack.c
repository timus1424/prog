#include <stdio.h>

int main() {
    int main[10], aux[10];   // two stacks
    int topM = -1, topA = -1;
    int arr[] = {3,1,5,4}, n;
    n=sizeof(arr)/sizeof(arr[0]);
    // push array into main stack
    for(int i=0;i<n;i++)
	main[++topM] = arr[i];

    // sorting logic
    while(topM != -1) {
        int temp = main[topM--];   // pop from main

        while(topA != -1 && aux[topA] > temp) 
            main[++topM] = aux[topA--];   // move back larger elements

        aux[++topA] = temp;   // push into aux
    }

    // transfer back to main (sorted)
    while(topA != -1) 
        main[++topM] = aux[topA--];

    printf("Sorted stack: ");
    for(int i=0;i<=topM;i++){ 
	printf("%d ", main[i]);
    }
    printf("\n");
    return 0;
}
