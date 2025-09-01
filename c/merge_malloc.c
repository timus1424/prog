#include <stdio.h>
#include <stdlib.h>  // for malloc, free

int main() {
    int n1, n2;
    printf("Enter size of first list: ");
    scanf("%d", &n1);
    int *l1 = (int*)malloc(n1 * sizeof(int));   // allocate memory
    printf("Enter %d elements (sorted): ", n1);
    for (int i=0; i<n1; i++) scanf("%d", &l1[i]);

    printf("Enter size of second list: ");
    scanf("%d", &n2);
    int *l2 = (int*)malloc(n2 * sizeof(int));
    printf("Enter %d elements (sorted): ", n2);
    for (int i=0; i<n2; i++) scanf("%d", &l2[i]);

    int n3 = n1+n2;
    int *l3 = (int*)malloc(n3 * sizeof(int));

    int i=0, j=0, k=0;
    while (i<n1 && j<n2) {
        if (l1[i] < l2[j]) l3[k++] = l1[i++];
        else if (l2[j] < l1[i]) l3[k++] = l2[j++];
        else { l3[k++] = l1[i++]; l3[k++] = l2[j++]; }
    }
    while (i<n1) l3[k++] = l1[i++];
    while (j<n2) l3[k++] = l2[j++];

    printf("Merged List:\n");
    for (int x=0; x<n3; x++) 
        printf("%d ", l3[x]);
    printf("\n");

    free(l1);  // free allocated memory
    free(l2);
    free(l3);

    return 0;
}