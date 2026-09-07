#include <stdio.h>
#include <stdlib.h>  // for malloc and free

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // dynamically allocate stacks of size n
    int *mainStack = (int *)malloc(n * sizeof(int));
    int *auxStack  = (int *)malloc(n * sizeof(int));
    if (mainStack == NULL || auxStack == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int topM = -1, topA = -1;

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        mainStack[++topM] = val;   // push into main stack
    }

    // sorting using aux stack
    while (topM != -1) {
        int temp = mainStack[topM--];  // pop from main

        while (topA != -1 && auxStack[topA] > temp) {
            mainStack[++topM] = auxStack[topA--];  // move back larger elements
        }

        auxStack[++topA] = temp;  // push into aux
    }

    // move sorted elements back into main
    while (topA != -1) {
        mainStack[++topM] = auxStack[topA--];
    }

    // print sorted stack
    printf("Sorted stack: ");
    for (int i = 0; i <= topM; i++) {
        printf("%d ", mainStack[i]);
    }
    printf("\n");

    // free dynamically allocated memory
    free(mainStack);
    free(auxStack);

    return 0;
}
