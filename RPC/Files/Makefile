main:
	rpcgen files.x -N
	gcc files_clnt.c files_remote.c -o rfiles
	gcc file_proc.c files_svc.c -o sfiles