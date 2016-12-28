//chmod函数 change permissions of file 成功返回0，出错返回-1
//int chmod(const char* pathname, mode_t mode);
//int fchmod(int fd,mode_t mode); 操作已打开的文件
//int fchmodat(int fd,const char*pathname,mode_t mode,int flag); 
#include<apue.h>

int main(void){
	struct stat statbuf;

	if(stat("foo",&statbuf)<0)
		err_sys("stat error for foo");
	if(chmod("foo",(statbuf.st_mode & ~S_IXGRP)|S_ISGID)<0)
		err_sys("chmod error for foo");
	if(chmod("bar",S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)<0)
		err_sys("chmod error for bar");
	exit(0);
}
