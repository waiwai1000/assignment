#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

main()
{
	int ct;
	struct sockaddr_in addr;

	ct = socket(PF_INET, SOCK_STREAM, 0);
	memset(&addr,0,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(33333);

	inet_aton("127.0.0.1", &addr.sin_addr);

	connect(ct,&addr, sizeof(addr));

	send(ct, "sucessfully connected" , strlen("sucessfully connected"), 0);


} 
