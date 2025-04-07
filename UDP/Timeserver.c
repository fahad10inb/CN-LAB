#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFF 200

int main() {
    int server;
    struct sockaddr_in serv_addr, client_addr;
    char buffer[BUFF];
    socklen_t len = sizeof(client_addr);

    server = socket(AF_INET, SOCK_DGRAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    printf("🕒 UDP Time Server running on port %d\n", PORT);

    while (1) {
        recvfrom(server, buffer, BUFF, 0, (struct sockaddr*)&client_addr, &len);

        time_t now = time(0);
        snprintf(buffer, BUFF, "Server Time: %s", ctime(&now));

        sendto(server, buffer, strlen(buffer), 0, (struct sockaddr*)&client_addr, len);
        printf("Time sent to client\n");
    }

    close(server);
    return 0;
}

