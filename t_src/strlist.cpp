#define TEST_N1_EN 0
#define TEST_N2_EN 1
#define TEST_NX_EN 0


#define TEST_N1 1
#define TEST_N2 2
#define TEST_NX 10


#include<stdio.h>
#include<stdlib.h>
#include "lib_strlist.h"
int main()
{
	const char * ts="TEST1";
	
	#if(TEST_N1_EN==1)
	strlist list1;
	for (size_t i = 0; i < TEST_N1; i++)
	{
		list1.push(ts);
	}
	// list1.show();
	#endif

	#if(TEST_N2_EN==1)	
	strlist list2;
	for (size_t i = 0; i < TEST_N2; i++)
	{
		list2.push(ts);
	}
	// list2.show();
	#endif

	#if(TEST_NX_EN==1)
	strlist listx;
	for (size_t i = 0; i < TEST_NX; i++)
	{
		listx.push(ts);
	}
	// listx.show();
	#endif

	return 0;
}
