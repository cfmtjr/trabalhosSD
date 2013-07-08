#include "hello.h"
#include <stdio.h>

int * hello_1_svc(void *param, struct svc_req * req)
{
  static int result;//MUST BE STATIC
  FILE *f;
  
  f = fopen("/dev/tty", "w");
  if(f == NULL)
  {
    result = 1;
    return &result;
  }
  
  fprintf(f, "Hello World! from RPC.\n");
  fclose(f);
  
  result = 0;
  return &result;
}