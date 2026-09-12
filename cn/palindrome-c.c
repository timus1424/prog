#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int sock_fd;
    struct sockaddr_in server_addr;

    char buffer[BUFFER_SIZE];
    char input[BUFFER_SIZE];

    // 1. Create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_fd < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // 2. Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    server_addr.sin_addr.s_addr =
        inet_addr("127.0.0.1");

    // 3. Connect to server
    if (connect(sock_fd,
                (struct sockaddr *)&server_addr,
                sizeof(server_addr)) < 0)
    {
        perror("Connection failed");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server.\n");

    // 4. Continuous communication
    while (1)
    {
        printf("\nEnter a string: ");

        fgets(input, BUFFER_SIZE, stdin);

        // Remove newline
        input[strcspn(input, "\n")] = '\0';

        // Send input to server
        send(sock_fd,
             input,
             strlen(input),
             0);

        // Exit condition
        if (strcmp(input, "exit") == 0)
            break;

        // Receive response
        memset(buffer, 0, BUFFER_SIZE);

        int bytes_received = recv(sock_fd,
                                  buffer,
                                  BUFFER_SIZE - 1,
                                  0);

        if (bytes_received <= 0)
            break;

        buffer[bytes_received] = '\0';

        printf("Server: %s\n", buffer);
    }

    close(sock_fd);

    return 0;
}
