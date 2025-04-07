# Computer Networks Lab Programs

This repository contains C implementations of fundamental networking protocols and concepts, organized by protocol type.

## Directory Structure

```
.
├── Congestion_Control/
│   └── leakybucket.c          - Leaky bucket algorithm implementation
├── File_Transfer_Protocol/
│   ├── client.c               - Basic file transfer client
│   ├── Pidclient.c            - PID-based file transfer client
│   ├── Pidserver.c            - PID-based file transfer server
│   └── server.c               - Basic file transfer server
├── Routing_Protocols/
│   └── dvr.c                  - Distance Vector Routing implementation
├── Sliding_Window_Protocols/
│   ├── gobackn.c              - Go-Back-N ARQ protocol
│   ├── selectiverepeat.c      - Selective Repeat ARQ protocol
│   └── stopandwait.c          - Stop-and-Wait ARQ protocol
├── TCP/
│   ├── Chatclient.c           - TCP chat client
│   ├── Chatserver.c           - TCP chat server
│   ├── Primeclient.c          - TCP prime number checker client
│   └── Primeserver.c          - TCP prime number checker server
├── UDP/
│   ├── Chatclient.c           - UDP chat client
│   ├── Chatserver.c           - UDP chat server
│   ├── Primeclient.c          - UDP prime number checker client
│   ├── Primeserver.c          - UDP prime number checker server
│   ├── Timeclient.c           - UDP time client
│   └── Timeserver.c           - UDP time server
└── README.md
```

## Detailed Descriptions

### File Transfer Protocol
- **Basic File Transfer**: Client/server for simple file transfer
- **PID-based Transfer**: Enhanced version using process IDs for tracking

### TCP Implementations
- **Chat Application**: Basic chat program demonstrating TCP sockets
- **Prime Number Service**: Client sends numbers, server checks primality

### UDP Implementations
- **Chat Application**: Connectionless chat using UDP
- **Prime Number Service**: UDP version of prime checking
- **Time Service**: Client gets current time from server

### Protocol Implementations
- **Sliding Window Protocols**:
  - Go-Back-N ARQ
  - Selective Repeat ARQ
  - Stop-and-Wait ARQ
- **Distance Vector Routing**: Dynamic routing protocol simulation
- **Leaky Bucket**: Congestion control algorithm

## Compilation and Usage

1. Compile any program with gcc:
```bash
gcc filename.c -o output [-lm for math functions if needed]
```

2. For client/server programs:
```bash
# Terminal 1 (Server)
./server_output [port]

# Terminal 2 (Client)
./client_output [host] [port]
```

3. Example for TCP Chat:
```bash
gcc TCP/Chatserver.c -o chatserver
gcc TCP/Chatclient.c -o chatclient
./chatserver 8080
./chatclient localhost 8080
```

## Requirements
- GCC compiler (version 4.8+ recommended)
- Linux/Unix environment
- Basic C and networking knowledge

## Notes
- Some programs may require additional libraries (-lm for math functions)
- Port numbers can be any available port (typically > 1024)
- Run servers with appropriate permissions if using privileged ports

