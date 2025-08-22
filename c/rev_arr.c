#include <stdio.h>

void rev_arr(int a[], int n) {
    int i, temp;
    for (i=0; i<n/2; i++) {
        temp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = temp;
    }
}

void disp(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Original Array: ");
    disp(a, n);
    rev_arr(a, n);
    printf("Reversed Array: ");
    disp(a, n);
    return 0;
}