#define TEST_N 10

#include<stdio.h>
#include<stdlib.h>
#include "lib_strlist.h"
int main()
{
	strlist list;
	const char * ts="TEST_STRING";
	list.push(ts);
	return 0;
}
