/* TCP Client - Sends a number to check if it's prime */
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int sock_desc;
    struct sockaddr_in server;
    char buffer[100];

    sock_desc = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(3003);

    connect(sock_desc, (struct sockaddr *)&server, sizeof(server));

    printf("Enter a number: ");
    fgets(buffer, 100, stdin);
    send(sock_desc, buffer, strlen(buffer), 0);

    recv(sock_desc, buffer, 100, 0);
    printf("Server: %s\n", buffer);

    close(sock_desc);
    return 0;
}
