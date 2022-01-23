#define TEST_N 100000

#include<stdio.h>
#include<stdlib.h>
#include "lib_strlist.h"
int main()
{
	item m[TEST_N];
	const char * ts="TEST_STRING";
	for(int i=0;i<TEST_N;i++)
	{
		m[i]=ts;
		fflush(stdout);
	}

	for(int i=0;i<TEST_N;i++)
	{
		m[i].probe();
	}

	return 0;
}
