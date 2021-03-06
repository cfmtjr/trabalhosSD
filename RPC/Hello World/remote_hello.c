#include "hello.h"

int main(int argc, char* argv[])
{
  CLIENT *clnt;
  int *result;
  char *server;
  
  if(argc < 2)
  {
    printf("Usage:\n %s host\n\n", argv[0]);
    return 1;
  }
  
  server = argv[1];
  
  //Conecta com o servidor RPC
  clnt = clnt_create(server, HELLOPROG, HELLOVERS, "tcp");
  if(clnt == NULL)
  {
    clnt_pcreateerror(server);
    return 2;
  }
  
  //Chama a função
  result = hello_1(NULL, clnt);
  if(result == NULL)
  {
    clnt_perror(clnt, server);
    return 3;
  }
  
  if(result == 0)
  {
    printf("Server could not print the message.\n");
    return 4;
  }
  
  printf("Message Delivered to %s\n", server);
  
  //Fecha a connecção com o servidor
  clnt_destroy(clnt);
  
  return 0;
}