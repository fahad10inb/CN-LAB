#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int is_prime(int num)
{
    int i;
    if(num<2)
    {
        return 0;
    }
    for(i=2;i*i< num ;i++)
    {
        if(num%i ==0)
        {
            return 0;
        }
    }
    return 1;
}

void main(){
    int client;
    struct sockaddr_in server;
    char buffer[100];
    int length = sizeof(server);

    client = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(client, (struct sockaddr*)&server, sizeof(server));

    while(1){
        recvfrom(client, buffer, sizeof(buffer)-1, 0, (struct sockaddr*)&server, &length);
        int num = atoi(buffer);
        printf("Client: Number recieved is %d\n", num);
        snprintf(buffer,100,"%d is %s\n",num , is_prime(num) ? "Prime" : "Not prime");
       
        sendto(client, buffer, strlen(buffer), 0, (struct sockaddr*)&server, length);
        printf("Client: %s", buffer);
    }
    close(client);
}