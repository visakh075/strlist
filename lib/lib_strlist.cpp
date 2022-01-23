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
item_c::item_c()
{
	in=NULL;
	out=NULL;
	loc=NULL;
	len=0;
}
item_c::~item_c()
{
	free(loc);
	loc=NULL;
}
void item_c::set(const char * strptr)
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
void item_c::operator = (const char* strptr)
{
	set(strptr);
}
void item_c::probe()
{
	printf("p:%p l:%p [i:%p o:%p] %10.10s\n",this,loc,in,out,loc);
}
void item_c::connect(item_c * _in,item_c * _out)
{
	in=_in;
	out=_out;
}
strlist_c::strlist_c()
{
	start=NULL;
	end=NULL;
	count=0;
}
strlist_c::~strlist_c()
{
}
void strlist_c::push(const char * str)
{
	//_temp=NULL;
	// _temp=NULL;
	_temp=(item *)malloc(sizeof(item));
	//_temp->set(str);
	//_temp->in=end;
	_temp->probe();
	//end=_temp;
	
}