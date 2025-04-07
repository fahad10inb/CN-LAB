#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define TOTAL 10       // Total packets
#define WIN 4          // Window size
#define FAIL_RATE 30   // 30% failure rate

int main() {
    srand(time(0));
    int base = 1;

    while (base <= TOTAL) {
        // Send packets in window
        for (int i = base; i < base + WIN && i <= TOTAL; i++) {
            printf("Sender: Packet %d sent\n", i);
            sleep(1);
        }

        // Simulate ACKs (cumulative ACK handling)
        int ack_upto = base - 1;
        for (int i = base; i < base + WIN && i <= TOTAL; i++) {
            if (rand() % 100 >= FAIL_RATE) {
                printf("Receiver: ACK for packet %d received\n", i);
                ack_upto = i;
            } else {
                printf("Receiver: ACK for packet %d lost! Go-Back-N triggered\n", i);
                break;
            }
        }

        if (ack_upto >= base) {
            base = ack_upto + 1;
            printf("Sliding window to %d\n\n", base);
        } else {
            printf("Retransmitting from packet %d...\n\n", base);
            sleep(2);
        }
    }

    printf(" All packets sent successfully!\n");
    return 0;
}

