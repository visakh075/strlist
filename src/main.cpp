#include<stdio.h>
#include<stdlib.h>
#include "lib_strlist.h"
int main()
{
	printf("create\n");fflush(stdout);
	element m;
	
	printf("%x %s\n",&m.loc,m.loc);
	m.set("thengaaaaa");
	
	m="chakka";
	printf("%x %s\n",&m.loc,m.loc);
	printf("exit\n");fflush(stdout);
	return 0;
}
