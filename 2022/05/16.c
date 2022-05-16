#include <hiredis.h>
#include <stdio.h>
#include <stdlib.h>

/*
 git clone https://github.com/redis/hiredis.git
 make
 make install
 gcc xx.c -I/usr/local/include/hiredis -lhiredis
 '-lhiredis' means libhiredis.a
*/
int main(int argc, char **argv) {
  if (argc < 3) {
    printf("usage: ./a.out host password\n");
    exit(1);
  }
  struct timeval timeout = {1, 500000}; // 1.5 seconds
  redisContext *redisCli = redisConnectWithTimeout(argv[1], 6379, timeout);
  if (redisCli->err) {
    printf("Connection err: %s\n", redisCli->errstr);
    redisFree(redisCli);
    exit(1);
  }
  redisCommand(redisCli, "auth %s", argv[2]);
  redisReply *reply = redisCommand(redisCli, "PING");
  printf("PING: %s\n", reply->str);
  reply = redisCommand(redisCli, "get key");
  printf("GET key: %s\n", reply->str);
  freeReplyObject(reply);
}
