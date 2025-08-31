#include <stdio.h>

int main() {
	int l1[] = {3,4,50,60}, l2[] = {7,8,90,100};
	int n1 = sizeof(l1)/sizeof(l1[0]);
	int n2 = sizeof(l2)/sizeof(l2[0]);
	int n3 = n1+n2;
	int l3[n3];
	int i=0, j=0, k=0;
	while (i<n1 && j<n2) {	//so that once one list is over, we can directly add the rest of the elements.
		if (l1[i] < l2[j])
			l3[k++] = l1[i++];
		else if (l2[j] < l1[i]) 
            		l3[k++] = l2[j++];
		else {
            		l3[k++] = l1[i++];
            		l3[k++] = l2[j++];
        	}
    	}
    	while (i<n1) l3[k++] = l1[i++];
    	while (j<n2) l3[k++] = l2[j++];

    	printf("Merged List:\n");
    	for (int x=0; x<n3; x++) {
    	    printf("%d ", l3[x]);
    	}
	printf("\n");
    	return 0;
}
