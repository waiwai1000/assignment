#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
	int sd;
	struct sockaddr_in addr;

	sd = socket(PF_INET,SOCK_STREAM,0);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(33333);
	addr.sin_addr.s_addr = INADDR_ANY;	

	bind(sd, &addr, sizeof(addr));
	listen(sd, 20);

	int addr_len = sizeof(addr);
	int clientsd = accept(sd, &addr, &addr_len);

	char buf[64]= {};
	memset(buf , 0 , 64);

//	recv(buf,0,64,0);
	recv(clientsd, buf, 64, 0);

	printf("Client-> %s\n", buf);
	
	close(clientsd);
	close(sd);

	return 0;
}
