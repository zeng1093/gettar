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

	int tm_sec;    *�룬������Χ0-59�� ��������61*
	int tm_min;    *���ӣ�0-59*
	int tm_hour;   *Сʱ�� 0-23*
	int tm_mday;   *�գ���һ�����еĵڼ��죬1-31*
	int tm_mon;    *�£� ��һ������0-11*1+p->tm_mon;
	int tm_year;   *�꣬ ��1900�����Ѿ�������*1900�� p->tm_year;
	int tm_wday;   *���ڣ�һ���еĵڼ��죬 ������������0-6*
	int tm_yday;   *�ӽ���1��1�յ�Ŀǰ����������Χ0-365*
	int tm_isdst;  *�չ��Լʱ������*
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
	res = time(&p); //��ָ�벻����Ϊ��������
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

