/* TCP Server - Checks if a number is prime */
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int sock_desc, temp_sock_desc;
    struct sockaddr_in server, client;
    socklen_t len;
    char buffer[100];

    sock_desc = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(3003);

    bind(sock_desc, (struct sockaddr *)&server, sizeof(server));
    listen(sock_desc, 5);
    
    printf(" Server is running on port 3003...\n");
    len = sizeof(client);
    temp_sock_desc = accept(sock_desc, (struct sockaddr *)&client, &len);
   
    recv(temp_sock_desc, buffer, 100, 0);
    int num = atoi(buffer);
    memset(buffer, 0, sizeof(buffer)); // Clear buffer before response
    sprintf(buffer, "%d is %s", num, is_prime(num) ? "prime" : "not prime");
    send(temp_sock_desc, buffer, strlen(buffer), 0);
    
    close(temp_sock_desc);
    close(sock_desc);
    return 0;
}


