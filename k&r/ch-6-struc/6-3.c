#include <stdio.h>

struct IPAddress {
    char* host;
    int port;
};

int main() {
    struct IPAddress localhost = {.host = "localhost", .port = 80};
    printf("%s:%d", localhost.host, localhost.port);
}