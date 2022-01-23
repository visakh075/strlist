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
void item_c::set_out(item_c * _to)
{
	out=_to;
	_to->in=out;
}
void item_c::set_in(item_c * _from)
{
	in=_from;
	_from->out=in;
}
strlist_c::strlist_c()
{
	head=(item *)malloc(sizeof(item*));
	tail=(item *)malloc(sizeof(item*));
	
	head=NULL;
	tail=NULL;
	count=0;
}
strlist_c::~strlist_c()
{
}
void strlist_c::probe()
{
	printf("strlist probe\nh:%p t:%p\n",head,tail);
}
void strlist_c::push(const char * str)
{
	// Initialize new item _push
	item* _temp=NULL;
	_temp=(item *)realloc(_temp,sizeof(item));
	_temp->loc=NULL;
	_temp->set(str);
	
	if(count==0)
	{
		_temp->in=NULL;
		head=_temp;
		tail=NULL;
		count=1;
	}
	else if(count==1)
	{
		_temp->set_in(head);
		_temp->out=NULL;
		tail=_temp;
		
		count=2;
	}
	else
	{
		_temp->set_in(tail);
		_temp->out=NULL;
		
		count++;
	}
	_temp->probe();
	free(_temp);
}
void strlist::show()
{
	printf("%d\n",count);
	probe();
	item * temp;
	temp=head;
	uint idx=0;
	for(;idx<count;idx++)
	{
		temp->probe();
		temp=temp->in;
	}
	// while(count)
	// {
	// 	temp->probe();
	// 	temp=temp->out;
	// 	count--;
	// }
}