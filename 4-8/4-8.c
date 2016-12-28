//access函数 check user's permissions for a file成功返回0，出错返回 -1
//int access(const char* pathname, int mode);
//int faccess(int fd,const char* pathname, int mode,int flag);
//mode R_OK,W_OK,X_OK
#include"apue.h"
#include<fcntl.h>

int main(int argc,char *argv[]){
	if(argc!=2)
		err_quit("usage: a.out <pathname>");
	if(access(argv[1],R_OK)<0)
		err_ret("access error for %s",argv[1]);
	else
		printf("read access OK\n");
	if(open(argv[1],O_RDONLY)<0)
		err_ret("open error for %s",argv[1]);
	else
		printf("open for reading OK\n");
	exit(0);
}
