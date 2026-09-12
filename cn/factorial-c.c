#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 7777
#define BUFFER_SIZE 1024

int main()
{
    int sock;
    struct sockaddr_in server;

    char input[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (struct sockaddr *)&server, sizeof(server));

    printf("Connected to server.\n");

    while (1)
    {
        printf("Enter number: ");
        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = '\0';

        send(sock, input, strlen(input), 0);

        if (strcmp(input, "exit") == 0)
            break;

        memset(buffer, 0, sizeof(buffer));

        recv(sock, buffer, sizeof(buffer), 0);

        printf("Factorial = %s\n", buffer);
    }

    close(sock);

    return 0;
}
