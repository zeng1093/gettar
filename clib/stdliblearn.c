/*************************************************************************
    > File Name: stdliblearn.c
    > Author:  zengyi
    > Mail: zengyi@ebupt.com
    > Created Time: Wed Jul  5 14:58:02 2017
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
//	int i = -2147483667;
	int i = -24;
	int res;
	char *str;
	char *a;
	res = abs(i);
	printf("abs(%d) = %d\n", i, res);
	printf("%i\n", atoi("12345.231hello!"));
	printf("%f\n", atof(" 12232.234 hello!"));
	printf("%d\n", atol(" 12232.234 hello!"));
	str = getenv("PATH");
	printf("%s\n", str);
	a = malloc(sizeof(int));
	free(a);
	str = "ls -l ~";
	res = system(str);
	str = "";
	res = system(NULL);
	printf("%d\n",res);
//	abort();
	return 0;
}
