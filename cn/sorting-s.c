#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int s, c, n, a[20], t, bytes;
    char input[200], result[200];

    s = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(8081);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(s, (struct sockaddr*)&server, sizeof(server));
    listen(s, 1);

    printf("Server waiting...\n");
    c = accept(s, NULL, NULL);
    printf("Client connected!\n");

    while(1) {
        bytes = recv(c, input, sizeof(input)-1, 0);
        input[bytes] = '\0';

        if(strcmp(input, "exit") == 0 || atoi(input) == -1)
            break;

        n = atoi(input);

        bytes = recv(c, a, sizeof(a), 0);

        for(int i = 0; i < n-1; i++)
            for(int j = i+1; j < n; j++)
                if(a[i] > a[j]) {
                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }

        send(c, a, sizeof(a), 0);

        printf("Sorted array sent.\n");
    }

    printf("Client disconnected.\n");
    close(c);
    close(s);
}
