#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define TOTAL_PACKETS 5
#define SUCCESS_RATE 70
#define ACK_SUCCESS (rand() % 100 < SUCCESS_RATE)  // 70% chance of success
int main() {
    srand(time(0));
    int packet = 1;
    int ack_received;

    while (packet <= TOTAL_PACKETS) {
        printf("Sender: Sending packet %d...\n", packet);
        sleep(1);
        ack_received = ACK_SUCCESS;
        if (ack_received) {
            printf("Receiver: ACK for packet %d received.\n\n", packet);
            packet++;
        } else {
            printf("Receiver: ACK for packet %d lost! Retransmitting...\n\n", packet);
            sleep(2);
        }
    }
    printf(" All packets sent successfully!\n");
    return 0;
}
