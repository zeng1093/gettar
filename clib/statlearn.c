/*************************************************************************
     File Name: statlearn.c
     Author:  zengyi
     Mail: zengyi@ebupt.com
     Created Time: Fri Jul  7 13:01:56 2017
 ************************************************************************/
/* struct stat {

	     dev_t         st_dev;       //�ļ����豸���
	     ino_t         st_ino;       //�ڵ�
	     mode_t        st_mode;      //�ļ������ͺʹ�ȡ��Ȩ��
	     nlink_t       st_nlink;     //�������ļ���Ӳ������Ŀ���ս������ļ�ֵΪ1
	     uid_t         st_uid;       //�û�ID
	     gid_t         st_gid;       //��ID
	     dev_t         st_rdev;      //(�豸����)�����ļ�Ϊ�豸�ļ�����Ϊ���豸���
	     off_t         st_size;      //�ļ��ֽ���(�ļ���С)
	     unsigned long st_blksize;   //���С(�ļ�ϵͳ��I/O ��������С)
	     unsigned long st_blocks;    //����
	     time_t        st_atime;     //���һ�η���ʱ��
	     time_t        st_mtime;     //���һ���޸�ʱ��
	     time_t        st_ctime;     //���һ�θı�ʱ��(ָ����)
	 };
*/
#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
int main(){
	int i;
	struct stat st;
	i = stat("/home/zengyi/clib/test.txt", &st);
	if (i!= 0) 
		printf("%s", strerror(errno));
	else 
		printf("%d\n %d\n", st.st_dev, st.st_size);
	return 0;
}
