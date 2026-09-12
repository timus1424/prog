#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int s, n, a[20];
    char input[20];

    s = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(8081);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    connect(s, (struct sockaddr*)&server, sizeof(server));

    printf("Connected to server.\n");

    while(1) {
        printf("Enter number of elements: ");
        scanf("%s", input);

        send(s, input, strlen(input), 0);

        if(strcmp(input, "exit") == 0 || atoi(input) == -1)
            break;

        n = atoi(input);

        printf("Enter elements: ");
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        send(s, a, sizeof(a), 0);
        recv(s, a, sizeof(a), 0);

        printf("Sorted array: ");
        for(int i = 0; i < n; i++)
            printf("%d ", a[i]);

        printf("\n");
    }

    close(s);
}
