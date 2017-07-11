/*************************************************************************
    > File Name: stringlearn.c
    > Author:  zengyi
    > Mail: zengyi@ebupt.com
    > Created Time: Wed Jul  5 10:09:30 2017
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
	char *buf1, *buf2, *buf9;
	char buf8[]="buf812345678";
	char *p=buf8;
	int i,slen;
	buf1 = "hello world!";
	buf2 = "hello !";
	char *buf5;
	char buf6[] = "This is new string";
	char buf7[] = "This is new string";
	char str1[] = "stringcat ";
	char str2[] = "str112";
	char *res;
	printf("%s ",argv[1]);
	size_t sz = atoi(argv[1]);
/*********************************************/	
	i = memcmp(buf1, buf2, sz);
	switch(i){
		case 0 :
			printf("equal!\n");
			break;
		default:
			printf("not equal\n");
	}
/*********************************************/
	char *buf3, *buf4;
	buf4 = memcpy(buf3, buf2, sz);
	printf("buf3 = %s && buf4 = %s \n", buf3, buf4);

/*********************************************/
	buf4 = memcpy(&buf7[2], &buf7[0], sz);
	printf("buf7 = %s && buf4 = %s \n", buf7, buf4);
	buf5 = memmove(&buf6[2], &buf6[0], sz);
	printf("buf6 = %s && buf5 = %s \n", buf6, buf5);
/*********************************************/
	buf9 = memset(p, 'a', sz);
	printf("buf9 = %s && buf8 = %s \n", buf9, buf8);
/*********************************************/
    res = strcat(str1, str2);
	printf("res = %s\n", res);
	res = strncat(str1, str2,sz);
	printf("res = %s\n", res);
/*********************************************/
	res = strchr(str1, '1' );
	if (res == NULL)
		printf("not find\n");
	else
		printf("%s\n", res);

	res = strrchr(str1, '1');
	if (res == NULL)
		printf("not find\n");
	else
		printf("%s\n", res);
/*********************************************/
//	strcpy(str2, str1);
	if(strcmp(str1, str2) == 0)
		printf("%s and %s equal\n ",str1, str2);
	else
		printf("%s and %s not equal\n ",str1, str2);
	if(strncmp(str1, str2, sz) == 0)
		printf("%s and %s first %d ch equal \n ",str1, str2, sz);
	else
		printf("%s and %s first %d ch not equal\n ",str1, str2, sz);
/*********************************************/
	slen = strlen(str2);
	printf( "length = %d\n", slen);
/*********************************************/
	res = strcpy(str1, str2);	
	printf("%s\n", res);
	strcpy(str2, "newstr2");
	res = strncpy(str1, str2, sz);	
	printf("%s\n", res);
/*********************************************/
	res = strstr(str1 , "12");
	if(res == NULL)
		printf("not find\n");
	else
		printf("%s\n", res);
	return 0;
	
}
