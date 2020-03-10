#include <iostream>
#include <cstdint>

#include "../common/net.hpp"

int main()
{
    uint16_t port {30000};
    net::Socket socket;

    if (!socket.open(port)) {
        std::cout << "failed to create socket!\n";

        return 1;
    }

    while ( true )
    {
        net::Address sender;
        unsigned char buffer[256];
        int bytes_read = socket.receive( sender, buffer, sizeof( buffer ) );
        if ( !bytes_read ) {
            net::sleepFor(100);
            continue;
        }
        printf( "received packet from %d.%d.%d.%d:%d (%d bytes)\n",
            sender.a(), sender.b(), sender.c(), sender.d(),
            sender.port(), bytes_read );

        printf("received: %s\n", buffer);

        net::sleepFor(100);
    }

    return 0;
}
