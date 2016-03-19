#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <stdio.h>

int main(int argc, char**argv)
{
	int sockfd,n;
	struct sockaddr_in servaddr, cliaddr;
	socklen_t len;
	char mes[1000];
	char send[] = "Hello client!";
	
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	
	servaddr.sin_family = AF_INET;	
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(32000);
	
	bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	len = sizeof(cliaddr);
	
	while(1)
	{
		n=recvfrom(sockfd,mes,1000,0,(struct sockaddr*)&cliaddr,&len);
	
		sendto(sockfd,send,n,0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));
		mes[n] = 0;
	
		printf("Client says: %s\n",mes);
	}	
	return 0;
}
