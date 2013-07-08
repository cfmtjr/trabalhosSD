#include "files.h"
#include <dirent.h>
#include <string.h>

char ** showdir_1_svc(char *path, struct svc_req *req)
{
  static char msg[1024];
  static char *result;
  
  DIR *d;
  struct dirent *dir;
  
  result = msg;
  result[0] = 0;
  
  d = opendir(path);
  if(d)
  {
    while((dir = readdir(d)) != NULL)
    {
      strcat(result, dir->d_name);
      strcat(result, "\n");
    }
    
    closedir(d);
  }
  else
  {
    result = "failed to open.";
  }
  
  return &result;
}