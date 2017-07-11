/*************************************************************************
    > File Name: timelearn.c
    > Author:  zengyi
    > Mail: zengyi@ebupt.com
    > Created Time: Thu Jul  6 14:02:19 2017
 ************************************************************************/
/*struct timeval
{
	time_t tv_sec; * Seconds. long*
	suseconds_t tv_usec; * Microseconds. long*
};/
truct tm
{

	int tm_sec;    *秒，正常范围0-59， 但允许至61*
	int tm_min;    *分钟，0-59*
	int tm_hour;   *小时， 0-23*
	int tm_mday;   *日，即一个月中的第几天，1-31*
	int tm_mon;    *月， 从一月算起，0-11*1+p->tm_mon;
	int tm_year;   *年， 从1900至今已经多少年*1900＋ p->tm_year;
	int tm_wday;   *星期，一周中的第几天， 从星期日算起，0-6*
	int tm_yday;   *从今年1月1日到目前的天数，范围0-365*
	int tm_isdst;  *日光节约时间的旗标*
};*/
#include<stdio.h>
#include<sys/time.h>
#include<time.h>

int main(){
	struct timeval tv;
	struct tm *tm1, *tm2, *tm3;
	time_t res;
	time_t p;
	gettimeofday(&tv, NULL);
	res = time(&p); //空指针不能作为参数传入
	if(!p)
		printf("can not get time");
	else
		printf("tv = %d\nres = %d\np = %d\n", tv.tv_sec, res, p);
	
	tm1 = localtime(&p);
	printf("%d:%d:%d:%d:%d:%d\n", tm1->tm_year+1900, tm1->tm_mon+1, tm1->tm_mday, tm1->tm_hour, tm1->tm_min, tm1->tm_sec);
			
	res = mktime(tm1);
	printf("res = %d\n", res);
	
	
	tm3 = localtime_r(&p, tm3);
	printf("%d:%d:%d:%d:%d:%d\n", tm3->tm_year+1900, tm3->tm_mon+1, tm3->tm_mday, tm3->tm_hour, tm3->tm_min, tm3->tm_sec);
		
}		

