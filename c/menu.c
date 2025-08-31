#include<stdio.h>

int main()
{
int n, top=-1, choice, val;
printf("Enter size of stack: ");
scanf("%d", &n);
int stack[n];
do {
	printf("\n1.PUSH  2.POP  3.PEEK  4.DISPLAY  5.EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

	switch (choice) {
	case 1: // PUSH
                if (top == n-1)
                  	printf("Overflow! Stack is full.\n");
               	else {
                    	printf("Enter value: ");
                    	scanf("%d", &val);
                    	stack[++top] = val;
                }
                break;
	case 2: // POP
                if (top == -1)
                    	printf("Underflow! Stack is empty.\n");
                else
                    	printf("%d popped.\n", stack[top--]);
                break;

	case 3: // PEEK
		if (top == -1)
                    	printf("Stack is empty.\n");
                else
                   	printf("Top element = %d\n", stack[top]);
               	break;

	case 4: // DISPLAY
                if (top == -1)
                    	printf("Stack is empty.\n");
                else {
                    	printf("Stack: ");
                    	for (int i = top; i >= 0; i--)
                        	printf("%d ", stack[i]);
                    	printf("\n");
                }
                break;
	
	case 5: // EXIT
		printf("Exiting...\n");
		break;

	default:
		printf("Invalid Choice!\n");
	}
}
while(choice!=5);
return 0;
}
