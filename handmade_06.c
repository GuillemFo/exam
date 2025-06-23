#include <stdio.h>
#include <stdlib.h>

int count = 0, fd_max = 0;
int ids[65536];
char *messages[65536];
fd_set rfds, wfds, afds;
char read_buf[1001], write_buf[42];

void err_msg(char *s)
{
	write(2,s, strlen(s));
	exit(1);
}

void notify_all(int author, char *str)
{
	for (int fd = 0; fd <= fd_max; fd++)
		if(FD_ISSET(fd, &wfds) && fd != author)
			send(fd, str, strlen(str), 0);
}


void reg_cli(int fd)
{
	fd_max = fd > fd_max ? fd : fd_max;
	ids[fd] = count++;
	messages[fd] = NULL;
	FD_SET(fd, &afds);
	sprintf(write_buf, "server: client %d just arrived\n", ids[fd]);
	notify_all(fd, write_buf);
}


void rm_cli(int fd)
{
	sprintf(write_buf, "server: client %d just left\n", ids[fd]);
	notify_all(fd,write_buf);
	free(messages[fd]);
	FD_CLR(fd, &afds);
	close(fd);
}


void send_msg(int fd)
{
	char *msg;

	while (extract_message(&(messages[fd]), &msg))
	{
		sprintf(write_buf, "client %d: ", ids[fd]);
		notify_all(fd, write_buf);
		notify_all(fd, msg);
		free(msg);
	}
}


int main(int ac, char **av) {
	
	if (ac != 2)
		err_msg("Wrong number of arguments\n");
	
	int sockfd, connfd;
	socklen_t len;

	//struct sockaddr_in servaddr, cli; 
	
	FD_ZERO(&afds);

	//sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd < 0) { 
		err_msg("Fatal error\n"); 
	}

	servaddr.sin_port = htons(atoi(av[1])); 

	//if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		err_msg("Fatal error\n"); 
	if (listen(sockfd, 200) != 0)
		err_msg("Fatal error\n"); 

	FD_SET(sockfd, &afds);
	fd_max= sockfd;

	while (42)
	{
		rfds = wfds = afds;
		if (select(fd_max +1 ,&rfds, &wfds, NULL, NULL) <0)
			err_msg("Fatal error\n");

		
		for (int fd=0; fd <= fd_max; fd++)
		{
			if (!FD_ISSET(fd, &rfds))
					continue;
			if(fd == sockfd)
			{
				len = sizeof(cli);
				connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
				if (connfd >= 0)
				{
					reg_cli(connfd);
					continue;
				}
			}
			else
			{
				int read_bytes = recv(fd, read_buf, sizeof(read_buf) -1, 0);
				if (read_bytes <= 0)
				{
					rm_cli(fd);
					break;
				}
				read_buf[read_bytes] = '\0';
				messages[fd] = str_join(messages[fd], read_buf);
				send_msg(fd);
			}
		}
	}
	return (0)
}
