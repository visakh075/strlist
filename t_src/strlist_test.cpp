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
	strlist listx;
	for (size_t i = 0; i < TEST_NX; i++)
	{
		listx.push(dummy[i]);
		log + dummy[i];
	}
	listx.show();
	#endif

	return 0;
}
