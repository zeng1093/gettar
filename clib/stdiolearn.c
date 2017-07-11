/*************************************************************************
    > File Name: stdiolearn.c
    > Author:  zengyi
    > Mail: zengyi@ebupt.com
    > Created Time: Wed Jul  5 16:12:46 2017
 ************************************************************************/

#include<stdio.h>
int main(){
	FILE *fp;
	int  sz = 100;
	size_t wrsc;
	char str[] = "hello world1\n";
	char buf[100];
	char strf[100];
	long FilePos;
	fp = fopen("test.txt","w");
	if(fp!= NULL){
		printf("open succsess!");
	}
	else 
		printf("not succsess");
//	if(!(wrsc = fwrite(str,sizeof(float),sizeof(str),fp))){
	if(!(wrsc = fwrite(str,sizeof(str[0]),sizeof(str)-1,fp))){
		printf("write fail");
	}
	printf("%d\n  %d\n", wrsc,sizeof(str)-1);
	fputs("hello",fp);
	fclose(fp);
	fp = fopen("test.txt","a+");
//	fgets(buf, 100, fp);
//	ftell(fp);
	fprintf(fp, "this is format data %d \n", sz);
	fseek(fp, 0L, SEEK_SET);
	fread(buf, sizeof(buf[0]), sizeof(buf), fp);
	printf("%s", buf);
	FilePos = ftell(fp);
	printf("%d\n", FilePos);
	//puts("hello world");
	sprintf(strf,"this is str %d \n", sz);
	printf("%s", strf);
	snprintf(strf, 9,"this is str %d \n", sz);
	printf("%s", strf);
	return 0;
}
