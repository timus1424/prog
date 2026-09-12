#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int s, bytes;
    char input[20], result[200];

    s = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(8081);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    connect(s, (struct sockaddr*)&server, sizeof(server));

    printf("Connected to server.\n");

    while(1) {
        printf("Enter number of terms: ");
        scanf("%s", input);

        send(s, input, strlen(input), 0);

        if(strcmp(input, "exit") == 0 || atoi(input) == -1)
            break;

        bytes = recv(s, result, sizeof(result)-1, 0);
        result[bytes] = '\0';

        printf("Fibonacci Series: %s\n", result);
    }

    close(s);
}
