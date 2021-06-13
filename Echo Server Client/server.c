#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
  int sock;
  int listener;
  int bytes_read;
  struct sockaddr_in addr;
  char buf[512];

  listener = socket(AF_INET, SOCK_STREAM, 0);

  if(listener < 0)
  {
    perror("Socket");
    exit(1);
  }

  addr.sin_family = AF_INET;
  addr.sin_port = htons(3425);
  addr.sin_addr.s_addr = htonl(INADDR_ANY);

  if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0)
  {
    perror("Bind");
    exit(0);
  }

  listen(listener, 1);

  while(1)
  {
    sock = accept(listener, 0, 0);
    if(sock < 0)
    {
      perror("Accept");
      exit(3);
    }

    while(1)
    {
      bytes_read = recv(sock, buf, 512, 0);
      if(bytes_read <= 0)
      {
        break;
      }
      send(sock, buf, bytes_read, 0);
    }
    close(sock);
  }

  return 0;

}
