#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFF 1024

void send_file(int sock) {
    char fn[BUFF], buf[BUFF];
    recv(sock, fn, BUFF, 0);
    printf("Requested file: %s\n", fn);

    // Send server PID to client
    sprintf(buf, "Server PID: %d\n", getpid());
    send(sock, buf, strlen(buf), 0);

    FILE *f = fopen(fn, "r");
  
    
    printf("Sending file: %s\n", fn);
    while (fgets(buf, BUFF, f)) 
        send(sock, buf, strlen(buf), 0);

    printf("File transfer complete\n");
    fclose(f);
}

int main() {
    int srv = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {AF_INET, htons(PORT), INADDR_ANY};

    bind(srv, (struct sockaddr *)&addr, sizeof(addr));
    listen(srv, 3);

    printf("Server running on port %d\n", PORT);
    
    while (1) {
        int cli = accept(srv, NULL, NULL);
        printf("Client connected\n");
        send_file(cli);
        close(cli);
        printf("Client disconnected\n");
    }
}
