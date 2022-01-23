#define TEST_N 20

#include<stdio.h>
#include<stdlib.h>
#include "lib_strlist.h"
int main()
{
	item m[TEST_N];
	const char * ts="TEST_STRING";
	const char * ts_long="1234567890abcdefghijklmnopqrstuvwxyz`1234567890-=~!#$%^&*()*()_+[]{}";
	const char * ts_short="TEST";
	for(int i=0;i<TEST_N;i++)
	{
		m[i]=ts;
		fflush(stdout);
	}

	for(int i=1;i<TEST_N-1;i++)
	{
		m[i].connect(&m[i-1],&m[i+1]);
	}

	printf("\n Allocation and Connect\n");
	for(int i=0;i<TEST_N;i++)
	{
		m[i].probe();
	}

	for(int i=0;i<TEST_N;i+=2)
	{
		m[i]=ts_long;
	}
	
	for(int i=1;i<TEST_N;i+=2)
	{
		m[i]=ts_short;
	}

	printf("\n Restructure and Connect\n");
	for(int i=0;i<TEST_N;i++)
	{
		m[i].probe();
	}
	return 0;
}
