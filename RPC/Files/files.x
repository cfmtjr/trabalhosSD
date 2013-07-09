/*files.x Remote file system*/

program FILEPROG {
  version FILEVERS {
    string SHOWDIR(string) = 1;
    string WRITEFILE(string) = 2;
  } = 1;
} = 0x20000010;
