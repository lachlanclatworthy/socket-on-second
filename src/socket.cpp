/* socket.cpp */

#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace socketDemo {

void ex1() {
    struct addrinfo hints;
    struct addrinfo *serverInfo;
    int status;

    // IPv4/6, TCP
    std::memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    status = getaddrinfo("google.com", "http", NULL, &serverInfo);
    if (status != 0) {
        std::fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        std::exit(1);
    }

    // There's more to do here...

    freeaddrinfo(serverInfo);
}

} // namespace socketDemo
