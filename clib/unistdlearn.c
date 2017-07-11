/*************************************************************************
    > File Name: unistdlearn.c
    > Author:  zengyi
    > Mail: zengyi@ebupt.com
    > Created Time: Fri Jul  7 13:29:16 2017
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
extern int errno;
int main(){
	int res, fp;
	pid_t pid;
	long hostid;
	char buf[100];
	char str[] = "appendstring";
	res = access("test.txt", X_OK);
	if(!res)
		printf("ok\n");
	else
		printf("%s\n", strerror(errno));
	fp = open("test.txt", O_RDONLY);
	if(fp!= -1){
		read(fp, buf, sizeof(buf));
		printf("%s", buf);
	}
	else 
		printf("open fail");
	close(fp);
	fp = open("test.txt", O_RDWR|O_APPEND);//O_CREAT 
	if(fp!= -1){
		write(fp, str, sizeof(str));
	//	read(fp, buf, sizeof(buf));
//		printf("%s", buf);
	}
	else
		printf("open fail");
	close(fp);
	pid = getpid();
	printf("\npid = %d\n", pid);
	if((pid = fork()) == 0){
		usleep(2000000);  //Œ¢√Î
		printf("ppid = %d\n", getppid());
	}
	else{
		sleep(2);         //√Î
		printf("cpid = %d\n", pid);
	}
	hostid = gethostid();
	
	printf("hostid = %d\n", hostid);
	return 0;
}
