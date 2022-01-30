#define TEST_N1_EN 0
#define TEST_N2_EN 0
#define TEST_NX_EN 1


#define TEST_N1 1
#define TEST_N2 2
#define TEST_NX 1024


#include <stdio.h>
#include <stdlib.h>
#include "lib_strlist.h"
#include "dummy.h"
#include "config.h"
rtlog log=rtlog("result",APPEND);
int main()
{
	#if(LOG_ENSY==1)
	MEM_MAPS("POINTER >>");
	#endif

	item * llist=(item*)malloc(sizeof(item));
	
	#if(LOG_ENSY==1)
	MEM_MAPS("POINTER <<");
	#endif

	#if(LOG_ENSY==1)
	MEM_MAPS("SET >>");
	#endif

	llist->set("first");
	
	#if(LOG_ENSY==1)
	MEM_MAPS("SET <<");
	#endif

	#if(TEST_N1_EN==1)
	for (size_t i = 0; i < TEST_N1; i++)
	{
		list1.push(dummy[i]);
	}
	#endif

	#if(TEST_N2_EN==1)	
	for (size_t i = 0; i < TEST_N2; i++)
	{
		list2.push(dummy[i]);
	}
	#endif
	MEM_MAPS("INSERT >>");
	#if(TEST_NX_EN==1)
	for (size_t i = 0; i < TEST_NX; i++)
	{
		item * curr;
		llist->out=llist->push(dummy[i]);
		curr=llist;
		llist=llist->out;
		llist->in=curr;

		#if(LOG_ENSY==1)
		sprintf(buff,"%p",llist);
		LOG();
		#endif

	}
	MEM_MAPS("INSERT <<");
	MEM_MAPS("PROBE >>");
	for (size_t i = 0; i < TEST_NX; i++)
	{
		#if(LOG_ENSY==1)
		sprintf(buff,"i:%lu %p %u %s",i,llist,llist->len,llist->loc);
		LOG();
		#endif

		llist=llist->in;
		llist->probe();
		
	}
	MEM_MAPS("PROBE <<");	
	#endif

	return 0;
}
