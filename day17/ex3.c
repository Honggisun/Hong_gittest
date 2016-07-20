#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

typedef struct _S_PACKET_BASE {
	unsigned short header;
	unsigned short req_type;
} _S_PACKET_BASE;


int main()
{
	int socket_dsec;
	struct sockaddr_in server;
	static char read_buffer[2000];

	_S_PACKET_BASE testPacket = {1004,100};
	
	printf("%d,%d \r\n",testPacket.header,testPacket.req_type);	

	return 0;
}
