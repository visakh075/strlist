#include<stdio.h>
#include<stdlib.h>
#include "lib_strlist.h"
int main()
{
	item m;
	m.probe();
	
	m.set("thengaaaaa");
	
	m="chakka";
	m.probe();
	printf("exit\n");fflush(stdout);
	return 0;
}
