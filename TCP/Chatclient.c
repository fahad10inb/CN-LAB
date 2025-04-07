#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>

void main() {
    char buffer[100];
    int n, desc;
    struct sockaddr_in client;
    
    desc = socket(AF_INET, SOCK_STREAM, 0);
    
    client.sin_family = AF_INET;
    client.sin_addr.s_addr = INADDR_ANY;
    client.sin_port = htons(8080);
    
    connect(desc, (struct sockaddr*)&client, sizeof(client));
    
    while(1) {
        printf("client: ");
        fgets(buffer, 100, stdin);
        send(desc, buffer, strlen(buffer), 0);
        recv(desc, buffer, 100, 0);
        printf("\nserver: %s\n", buffer);
    }
    
    close(desc);
}