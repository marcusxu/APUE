//对每个参数打印文件类型
//struct stat
//mode_t st_mode的成员 文件类型和模式(访问权限)
//函数stat系列：返回与文件有关的信息结构
//#include <sys/stat.h>
//int stat(const char *restrict pathname, struct stat *restrict buf);		
//int fstat(int fd,struct stat *buf)	在文件描述符上打开文件
//int lstat(const char*restrict pathname, struct stat *restrict buf);		遇到文件链接返回符号链接的信息（而不是引用的文件）
//int fstatat(int fd,const char* restrict pathname,struct stat *restrict buf,int flag);	一个相对于当前打开目录的路径名返回文件统计信息
#include "apue.h"

int main (int argc, char *argv[]){
	int i;
	struct stat buf;
	char *ptr;
	for(i =0;i<argc;++i){
		printf("%s: ",argv[i]);
		if(lstat(argv[i],&buf)<0){
			err_ret("lstat error");
			continue;
		}
		if(S_ISREG(buf.st_mode))//用宏确定文件类型#define S_ISDIR (mode) (((mode) & S_IFMT) == S_IFDR) 和屏蔽字与之后比较
			ptr="regular";//普通文件
		else if(S_ISDIR(buf.st_mode))
			ptr="directory";//目录文件
		else if(S_ISCHR(buf.st_mode))//字符特殊文件，对设备提供不带缓冲的访问
			ptr="character special";
		else if(S_ISBLK(buf.st_mode))//块特殊文件，提供对设备带缓冲的访问
			ptr="block speical";
		else if(S_ISFIFO(buf.st_mode))//FIFO，用于进程间通信
			ptr="fifo";
		else if(S_ISLNK(buf.st_mode))//符号链接
			ptr="symbolic link";
		else if(S_ISSOCK(buf.st_mode))//套接字，用于进程间的网络通信
			ptr="socket";
		else
			ptr="** unknown mode **";
		printf("%s\n",ptr);
	}
	exit(0);
}
