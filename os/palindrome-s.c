#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int isPal(char str[])
{
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right)
    {
        if (str[left] != str[right])
            return 0;

        left++;
        right--;
    }

    return 1;
}

int main()
{
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    char buffer[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    int option = 1;

    // 1. Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR,
               &option, sizeof(option));

    if (server_fd < 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // 2. Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // 3. Bind socket
    if (bind(server_fd,
             (struct sockaddr *)&server_addr,
             sizeof(server_addr)) < 0)
    {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // 4. Listen
    if (listen(server_fd, 5) < 0)
    {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server is waiting for client...\n");

    // 5. Accept client
    client_fd = accept(server_fd,
                       (struct sockaddr *)&client_addr,
                       &addr_len);

    if (client_fd < 0)
    {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Client connected.\n");

    // 6. Continuous communication
    while (1)
    {
        memset(buffer, 0, BUFFER_SIZE);

        int bytes_received = recv(client_fd,
                                  buffer,
                                  BUFFER_SIZE - 1,
                                  0);

        if (bytes_received <= 0)
            break;

        buffer[bytes_received] = '\0';

        printf("Client: %s\n", buffer);

        // Exit condition
        if (strcmp(buffer, "exit") == 0)
            break;

        // Check palindrome
        if (isPal(buffer))
            strcpy(response, "Palindrome");
        else
            strcpy(response, "Not a Palindrome");

        // Send result
        send(client_fd,
             response,
             strlen(response),
             0);
    }

    close(client_fd);
    close(server_fd);

    return 0;
}
