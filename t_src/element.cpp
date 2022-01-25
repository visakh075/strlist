#define TEST_N 1

#include<stdio.h>
#include<stdlib.h>
#include "lib_strlist.h"
#include "lib_rtlog.h"
#include "dummy.h"
rtlog log=rtlog("log",APPEND);
int main()
{
	item m[TEST_N];
	
	for(int i=0;i<TEST_N;i++)
	{
		

		//log + m[i]
		m[i]=item(dummy[i]);
		
		//fflush(stdout);
	}
	
	for(int i=0;i<TEST_N;i++)
	{
		//printf("\ncurr %p",&m[i]);
		//m[i]=item(ts);
		
		//fflush(stdout);
	}

	for(int i=0;i<TEST_N;i++)
	{
		m[i].probe();
	}

	return 0;
}
