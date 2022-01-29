#define TEST_N 10

#include<stdio.h>
#include<stdlib.h>
#include "lib_strlist.h"
#include "dummy.h"
int main()
{
	item m[TEST_N];
	
	
	printf("Before\n");
	for(int i=0;i<TEST_N;i++)
	{
		//m[i]=dummy[i];
		fflush(stdout);
	}

	for(int i=0;i<TEST_N;i++)
	{	
		//m[i].probe();
		fflush(stdout);
	}
	

	// REPLACE
	for(int i=0;i<TEST_N;i+=2)
	{
		
		//m[i]=dummy[TEST_N+i];
	}
		
	// PRESENT
	printf("\nAfter\n");
	for(int i=0;i<TEST_N;i++)
	{
		m[i].probe();
	}
	return 0;
}
