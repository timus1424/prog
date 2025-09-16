#include <stdio.h>

int front = -1, rear = -1, n;   // global for simplicity
int Q[10];   // actual n taken from user

// ENQUEUE
void enQ(int val) {
    if (rear == n - 1) {
        printf("Overflow!\n");
    } else {
        if (front == -1) front = 0;
        Q[++rear] = val;
        printf("%d enqueued\n", val);
    }
}

// DEQUEUE
void deQ() {
    if (front == -1 || front > rear) {
        printf("Underflow!\n");
        front = rear = -1;   // reset
    } else {
        printf("%d dequeued\n", Q[front++]);
    }
}
//DISPLAY
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", Q[i]);
        printf("\n");
    }
}

int main() {
    int choice, val;
    printf("Enter queue size (6–10): ");
    scanf("%d", &n);

    do {
        printf("\n1.ENQUEUE 2.DEQUEUE 3.DISPLAY 4.EXIT\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enQ(val);
                break;
            case 2:
                deQ();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
