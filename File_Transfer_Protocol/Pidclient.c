#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFF 1024

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {AF_INET, htons(PORT), INADDR_ANY};
    connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    
    char fn[BUFF];
    printf("Enter filename: ");
    scanf("%s", fn);
    send(sock, fn, strlen(fn), 0);
    
    char buf[BUFF];
    
    // Receive and print PID from server
    if (recv(sock, buf, BUFF, 0) > 0) {
        printf("\n%s", buf);  // Should print: Server PID: XXXX
    }

    // Then receive file content or "file not found" message
    printf("File Content:\n");
    while (recv(sock, buf, BUFF, 0) > 0) {
        printf("%s", buf);
    }

    close(sock);
    return 0;
}
