#define TEST_N 100

#include<stdio.h>
#include<stdlib.h>
#include "lib_strlist.h"
int main()
{
	strlist list;
	const char * ts="TEST1";
	const char * ts1="TEST12";
	const char * ts2="TEST123";
	for (size_t i = 0; i < TEST_N; i++)
	{
	list.push(ts);
	}

	for (size_t i = 0; i < TEST_N; i++)
	{
	// list.head->probe();
	}
	

	// list.push(ts);
	// list.push(ts1);
	// list.push(ts2);
	list.show();
	return 0;
}
