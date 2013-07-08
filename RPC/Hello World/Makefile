main:
	rpcgen hello.x
	gcc remote_hello.c hello_clnt.c -o rhello -lnsl
	gcc hello_proc.c hello_svc.c -o shello -lnsl