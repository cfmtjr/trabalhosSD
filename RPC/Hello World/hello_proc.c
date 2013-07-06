#include <stdio.h>
#include "hello.h"

int* hello_1_svc(char** msgn, struct svc_req *req)
{
  static int result;//MUST BE STATIC
  FILE *f;
  
  //f = fopen("/dev/console", "w");
  f = fopen("/dev/tty", "w");
  if(f == NULL)
  {
    result = 0;
    return &result;
  }
  
  //fprintf(f, "Hello World! from RPC.\n");
  fprintf(f, "Message: %s.\n", *msgn);
  fclose(f);
  
  result = 1;
  return &result;
}