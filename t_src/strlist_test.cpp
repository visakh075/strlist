#define TEST_N1_EN 0
#define TEST_N2_EN 0
#define TEST_NX_EN 1


#define TEST_N1 1
#define TEST_N2 2
#define TEST_NX 10

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
	for (size_t i = 0; i < TEST_NX; i++)
	{
		listx.push(dummy[i]);
	}
	listx.show();

	for (size_t i = 0; i <=TEST_NX; i++)
	{
		#if(LOG_ENSY==1)
		//MEM_MAPS("<srch>");
		// sprintf(buff,"strlist $ [%lu]%p",i,listx.get(i));
		// LOG();
		// sprintf(buff,"strlist $ [%lu]%p",listx.ListCount-i,listx.getI(listx.ListCount-i));
		// LOG();
		//MEM_MAPS("</srch>");
		#endif

	}
	#endif
	return 0;
}