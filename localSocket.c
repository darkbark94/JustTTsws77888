#include <stddef.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#define SOCKET_NAME_RIL "rild"
#define ANDROID_SOCKET_NAMESPACE_RESERVED "/dev/socket"
int main (){

int fd;


printf("create socket\r\n");

fd = socket(SOCKET_NAME_RIL,
ANDROID_SOCKET_NAMESPACE_RESERVED,
SOCK_STREAM);

if (fd < 0) {
perror ("opening radio  socket error");
exit(-1);
}



printf("fd = %d\r\n",fd);
int length = 12;
char datalength[5]={0};
datalength[0] = 0;
datalength[1] = 0;
datalength[2] = (length >>8) & 0xff;
datalength[3] = (length & 0xff);
int ret = send(fd, datalength, 4, 0);
if(ret != sizeof(int)) {
    perror ("Socket write error when sending length");
    close(fd);
    exit(-1);
}
return 0;
}
