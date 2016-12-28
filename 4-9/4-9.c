//umask函数 set file mode creatio mask
//mode_t umask(mode_t cmask);返回之前的屏蔽字
//屏蔽字为1的位，mode中相应的位被关闭 permission=mode&(~mask)

#include "apue.h"
#include <fcntl.h>
#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
//#define RWRWRW 0

int main(void){
	umask(0);
	if(creat("foo",RWRWRW)<0)
		err_sys("creat error for foo");
	umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
	if(creat("bar",RWRWRW)<0)
		err_sys("creat error for bar");
	exit(0);
}
