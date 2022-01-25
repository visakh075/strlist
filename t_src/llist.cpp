#define TEST_N1_EN 0
#define TEST_N2_EN 0
#define TEST_NX_EN 1


#define TEST_N1 1
#define TEST_N2 2
#define TEST_NX 200


#include<stdio.h>
#include<stdlib.h>
#include "lib_strlist.h"
#include "lib_rtlog.h"
#include "dummy.h"
rtlog log=rtlog("result",APPEND);
int main()
{
	
	item * llist=(item*)malloc(sizeof(item*));
	llist->set("kkkk");
	
	#if(TEST_N1_EN==1)
	strlist list1;
	for (size_t i = 0; i < TEST_N1; i++)
	{
		list1.push(dummy[i]);
	}
	// list1.show();
	#endif

	#if(TEST_N2_EN==1)	
	strlist list2;
	for (size_t i = 0; i < TEST_N2; i++)
	{
		list2.push(dummy[i]);
	}
	// list2.show();
	#endif

	#if(TEST_NX_EN==1)
	//strlist listx;
	
	//llist->probe();
	for (size_t i = 0; i < TEST_NX; i++)
	{
		llist->push(dummy[i]);
		//llist->probe();
		//llist=llist->out;
		//log + dummy[i];
	}

	
	#endif

	return 0;
}
