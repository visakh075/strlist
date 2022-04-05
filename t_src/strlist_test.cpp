//#include "test_spec.h"

#ifndef TEST_NX_EN
#define TEST_NX_EN 1
#endif

#ifndef TEST_NX
#define TEST_NX 100
#endif

#include<stdio.h>
#include<stdlib.h>
#include "lib_strlist.h"
#include "lib_rtlog.h"
#include "dummy.h"
rtlog log=rtlog("result.log",APPEND);
int main()
{
	#if(TEST_NX_EN==1)
	
	strlist listx;


	LOG_STR("initial push");
	for (size_t i = 0; i < TEST_NX; i++)
	{
		listx.push(dummy[i]);
	}

	LOG_STR("initial show");
	listx.show();

	LOG_STR("replace");	
	for (size_t i = 0; i < TEST_NX; i+=2)
	{
		*listx[i]=dummy[TEST_NX+i];
	}

	LOG_STR("replace show");
	listx.show();

	for (size_t i = 0; i <=TEST_NX; i++)
	{
		#if(LOG_ENSY==1)

		sprintf(buff,"item $ [%03lu]%p",i,listx.get(i));
		LOG();
		sprintf(buff,"item $ [%03lu]%p",listx.len-i,listx.getI(listx.len-i));
		LOG();

		#endif

	}
	#endif
	
	return 0;
}
