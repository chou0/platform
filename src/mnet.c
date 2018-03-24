#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h> 

int mnet_setnoblock(int fd)
{
    int opts;
    
    opts = fcntl(fd, F_GETFL);
    if (opts < 0) {
        perror("fcntl(F_GETFL)");
        return -1;
    }
    
    opts = (opts | O_NONBLOCK);
    if (fcntl(fd, F_SETFL, opts) < 0) {
        perror("fcntl(F_SETFL)");
        return -1;
    } 
    
    return 0;       
}

int mnet_check_connectble(char *ipaddr, int port, int timeout)
{
    struct sockaddr_in remote = {0};
    struct timeval timeo = {3, 0};
    socklen_t len;
    int client, ret = -1;
    
    if (0 > (client = socket(AF_INET, SOCK_STREAM, 0)))
	{
		printf("create socker err\n");
		return -1;
	} 
	
	if (timeout)
	{
	    timeo.tv_sec = timeout;    
	}
	
	setsockopt(client, SOL_SOCKET, SO_SNDTIMEO, &timeo, sizeof timeo);     

	remote.sin_family = AF_INET;
	remote.sin_port = htons(port);
    remote.sin_addr.s_addr = inet_addr(ipaddr);
	len = sizeof(remote);

	if (0 > connect(client,(struct sockaddr *)&remote, len))
	{	
	    perror("connect err");
		goto fail_label;
	}
	
	ret = 0;
fail_label:
    close(client);	
	return ret;
}