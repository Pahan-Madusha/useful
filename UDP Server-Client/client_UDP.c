#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char**argv)
{
	int sockfd,n;
	struct sockaddr_in servaddr;
	char send[] = "Hello server!";
	char recv[1000];

	if (argc != 2)
	{
		printf("usage:%s <IP address>\n",argv[0]);
		return -1;
	}
	
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	bzero(&servaddr,sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr=inet_addr(argv[1]);
	servaddr.sin_port=htons(32000);

	sendto(sockfd,send,strlen(send),0,(struct sockaddr*)&servaddr,sizeof(servaddr));

	n=recvfrom(sockfd,recv,10000,0,NULL,NULL);

	recv[n]=0;
	
	printf("Server says: %s\n",recv);
	return 0;
}
