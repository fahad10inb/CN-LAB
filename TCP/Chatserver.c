#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

void main() {
    char buffer[100];
    int desc, client_sock;
    struct sockaddr_in server, client;
    socklen_t client_len;
    
    desc = socket(AF_INET, SOCK_STREAM, 0);
    
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);
    
    bind(desc, (struct sockaddr*)&server, sizeof(server));
    listen(desc, 5);
    
    client_len = sizeof(client);
    client_sock = accept(desc, (struct sockaddr*)&client, &client_len);
    
    while(1) {
        recv(client_sock, buffer, 100, 0);
        printf("\nclient: %s\n", buffer);
        printf("server: ");
        fgets(buffer, 100, stdin);
        send(client_sock, buffer, strlen(buffer), 0);
    }
    
    close(client_sock);
}