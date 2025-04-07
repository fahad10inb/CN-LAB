#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFF 200

int main() {
    int client;
    struct sockaddr_in server;
    char buffer[BUFF];
    socklen_t len = sizeof(server);

    client = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    strcpy(buffer, "TIME_REQUEST");

    sendto(client, buffer, strlen(buffer), 0, (struct sockaddr*)&server, len);

    recvfrom(client, buffer, BUFF, 0, (struct sockaddr*)&server, &len);

    printf("⏰ Time from Server: %s", buffer);

    close(client);
    return 0;
}

