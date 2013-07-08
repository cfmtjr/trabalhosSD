#include "files.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
  CLIENT *clnt;
  char *server, *message, **result;
  
  if(argc < 3)
  {
    printf("Usage:\n %s host message\n\n", argv[0]);
    return 1;
  }
  
  server = argv[1];
  message = argv[2];
  
  clnt = clnt_create(server, FILEPROG, FILEVERS, "tcp");
  if(clnt == NULL)
  {
    clnt_pcreateerror(server);
    return 2;
  }
  
  result = showdir_1(message, clnt);
  if(result == NULL)
  {
    clnt_perror(clnt, server);
    return 3;
  }
  else
  {
    printf("Message received:\n%s\n", *result);
  }
  
  if(result == 0)
  {
    printf("Server could not print the message.\n");
    return 4;
  }
  
  printf("Message Delivered to %s .\n", server);
  clnt_destroy(clnt);
  
  return 0;
}