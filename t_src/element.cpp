#define TEST_N 1000

#include<stdio.h>
#include<stdlib.h>
#include "lib_strlist.h"
#include "dummy.h"
//#include "config.h"
rtlog log=rtlog("log",rt_log::APPEND);

// #if(LOG_ENSY==1)
// extern rtlog map;
// extern char * buff;
// #define LOG map + buff
// #endif


int main()
{
	#if(LOG_ENSY==1) 
	sprintf(buff,"Definition >>");
	LOG();
	#endif

	item m[TEST_N];
	
	#if(LOG_ENSY==1) 
	sprintf(buff,"Definition <<");
	LOG();
	#endif

	#if(LOG_ENSY==1) 
	sprintf(buff,"Declare >>");
	LOG();
	#endif
	for(int i=0;i<TEST_N;i++)
	{
		

		//log + m[i]
		m[i]=item(dummy[i]);
		
		//fflush(stdout);
	}
	#if(LOG_ENSY==1) 
	sprintf(buff,"Declare <<");
	LOG();
	#endif
	


	for(int i=0;i<TEST_N;i++)
	{
		//printf("\ncurr %p",&m[i]);
		//m[i]=item(ts);
		
		//fflush(stdout);
	}

	#if(LOG_ENSY==1) 
	sprintf(buff,"Probe >>");
	LOG();
	#endif
	
	for(int i=0;i<TEST_N;i++)
	{
		m[i].probe();
	}

	#if(LOG_ENSY==1) 
	sprintf(buff,"Probe <<");
	LOG();
	#endif


	return 0;
}
