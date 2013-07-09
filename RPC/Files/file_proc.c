#include "files.h"
#include <dirent.h>
#include <string.h>
#include <stdio.h>

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

char ** writefile_1_svc(char* args, struct svc_req *req)
{
  static int result;
  static char* answer;
  int i;

  FILE *file;
  file = fopen("test.txt", "a+");
  result = fprintf(file, "%s", args);
  fclose(file);
  
  if(result > 0)
    answer = "Writing to file successfully performed.";
  else
    answer = "Error at writing to file.";
  return &answer;
}
