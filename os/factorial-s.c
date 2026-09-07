#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 7777
#define BUFFER_SIZE 1024

int main()
{
    int server_fd, client_fd;
    struct sockaddr_in server, client;
    socklen_t len = sizeof(client);

    char buffer[BUFFER_SIZE];
    int num;
    long long fact;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&server, sizeof(server));
    listen(server_fd, 5);

    printf("Server waiting for client...\n");

    client_fd = accept(server_fd,
                       (struct sockaddr *)&client,
                       &len);

    printf("Client connected.\n");

    while (1)
    {
        memset(buffer, 0, sizeof(buffer));

        recv(client_fd, buffer, sizeof(buffer), 0);

        if (strcmp(buffer, "exit") == 0)
            break;

        num = atoi(buffer);

        fact = 1;

        for (int i = 1; i <= num; i++)
            fact = fact * i;

        sprintf(buffer, "%lld", fact);

        send(client_fd, buffer, strlen(buffer), 0);
    }

    close(client_fd);
    close(server_fd);

    return 0;
}
