#include "lib_strlist.h"
#include <stdlib.h>
#include <stdio.h>
uint strlen(const char * strptr)
{
	uint retVal=0;
	while(*strptr++)retVal++;
	return retVal;
}
void strcpy(const char * frm,char * to)
{
	while(*to++=*frm++);
}
item::item()
{
	in=NULL;
	out=NULL;
	loc=NULL;
	len=0;
}
item::~item()
{
	free(loc);
	loc=NULL;
}
void item::set(const char * strptr)
{
	loc=(char *)realloc(loc,sizeof(char)*strlen(strptr)+1);
	if(loc!=NULL)
	{
		strcpy(strptr,loc);
		len=strlen(strptr);
	}
	else
	{
		printf("\nmallloc error");
	}
}
void item::operator = (const char* strptr)
{
	set(strptr);
}
void item::probe()
{
	printf("p:%p l:%p [i:%p o:%p] %10.10s\n",this,loc,in,out,loc);
}
void item::connect(item * _in,item * _out)
{
	in=_in;
	out=_out;
}