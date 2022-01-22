#define TEST_N 10

#include<stdio.h>
#include<stdlib.h>
#include "lib_strlist.h"
int main()
{
	element m[TEST_N];
	const char * ts="TEST_STRING";
	const char * ts_long="1234567890abcdefghijklmnopqrstuvwxyz`1234567890-=~!#$%^&*()*()_+[]{}";
	const char * ts_short="TEST";
	
	printf("Before\n");
	for(int i=0;i<TEST_N;i++)
	{
		m[i]=ts;
		fflush(stdout);
	}

	for(int i=0;i<TEST_N;i++)
	{	
		m[i].probe();
		fflush(stdout);
	}
	
	// REPLACE
	for(int i=0;i<TEST_N;i+=2)
	{
		m[i]=ts_long;
	}
	
	for(int i=1;i<TEST_N;i+=2)
	{
		m[i]=ts_short;
	}
	
	// PRESENT
	printf("After\n");
	for(int i=0;i<TEST_N;i++)
	{
		m[i].probe();
	}
	return 0;
}
