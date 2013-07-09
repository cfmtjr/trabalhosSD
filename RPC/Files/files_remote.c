#include "files.h"
#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
  CLIENT *clnt;
  char *mode, *server, **message, **result;
  
  if(argc < 3)
  {
    printf("Usage:\n %s host writeFile/showDir \"message\"\n\n", argv[0]);
    return 1;
  }
 
  server = argv[1];
  mode = argv[2];
  message = argv+3;

  clnt = clnt_create(server, FILEPROG, FILEVERS, "tcp");
  if(clnt == NULL)
  {
    clnt_pcreateerror(server);
    return 2;
  }
  
  if(strcasecmp(mode, "writefile") == 0)
    result = writefile_1(message[0], clnt);
  else if (strcasecmp(mode, "showdir") == 0)
    result = showdir_1(message[0], clnt);
  else
    printf("Unknown command.");
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
