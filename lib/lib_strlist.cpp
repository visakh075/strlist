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
void item_c::set_tail(item_c * _tail)
{
	out=_tail;
}
void item_c::set_head(item_c * _head)
{
	in=_head;
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
	item * _temp;
	// free(_temp);
	_temp=NULL;
	_temp=(item *)realloc(_temp,sizeof(item));
	_temp->loc=NULL;
	_temp->set(str);
	
	if(!count)
	{
		head=_temp;
		tail=NULL;
		count++;
	}
	else
	{
		_temp->set_head(head);
		head=_temp;
		count++;
	}
	// probe();

	//tail->set_tail(_temp);
	//_temp->set_head(tail);
	// _temp->probe();
}
void strlist::show()
{
	printf("%d\n",count);
	probe();
	item * temp;
	temp=head;
	while(count)
	{
		temp->probe();
		temp=temp->in;
		count--;
	}
}