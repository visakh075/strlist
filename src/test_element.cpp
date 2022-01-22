#define TEST_N 100000

#include<stdio.h>
#include<stdlib.h>
#include "lib_strlist.h"
int main()
{
	element m[TEST_N];
	const char * ts="TEST_STRING";
	for(int i=0;i<TEST_N;i++)
	{
		m[i]=ts;
		fflush(stdout);
	}

	for(int i=0;i<TEST_N;i++)
	{
		printf("\n%x %s",&m[i],m[i].loc);
	}


	for(int i=0;i<TEST_N;i++)
	return 0;
}
