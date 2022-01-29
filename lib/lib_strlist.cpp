#include "lib_strlist.h"
#include "config.h"
#include <stdlib.h>
#include <stdio.h>
#include "lib_rtlog.h"
char buff[100];
rtlog map=rtlog("mem_map",NORMAL);
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
item_c::item_c(const char * _str)
{
	//Pitem_c();
	
	//sprintf(buff,"item : %p %s str",this,_str);
	//map + buff;
	set(_str);
}
item_c::item_c()
{
	in=(item_c *)malloc(sizeof(item_c *));
	out=(item_c *)malloc(sizeof(item_c *));
	loc=(char *)malloc(sizeof(char *));
	len=0;
	sprintf(buff,"item * : %p %p",this,loc);
	map + buff;
}
item_c::~item_c()
{
	sprintf(buff,"item ~ : %p %p %s",this,loc,loc);
	map + buff;
	in=NULL;
	out=NULL;
	loc=NULL;
	// free(loc);
}
void item_c::set(const char * strptr)
{
	loc=NULL;
	loc=(char *)realloc(loc,sizeof(char *)*strlen(strptr)+1);
	
	if(loc!=NULL)
	{
		strcpy(strptr,loc);
		len=strlen(strptr);
	}
	else
	{
		printf("\nmallloc error");fflush(stdout);
	}
	
	sprintf(buff,"item < : %p %p %s",this,loc,loc);
	map + buff;
}
/*
void item_c::operator = (const char* strptr)
{
	set(strptr);
}
*/
void item_c::probe()
{
	printf("\np:%p l:%p [i:%p o:%p] %s",this,loc,in,out,loc);
}
void item_c::connect(item_c * _in,item_c * _out)
{
	// in=_in;
	// out=_out;
}
void item_c::set_out(item_c * _to)
{
	//out=_to;
	//_to->in=out;
}
void item_c::set_in(item_c * _from)
{
	//in=_from;
	//_from->out=in;
}

void item_c::push(const char * _str)
{
	item_c temp=item_c(_str);
	//temp.set(_str);
	out=&temp;
	//temp.probe();
}

strlist_c::strlist_c()
{
	head=(item *)malloc(sizeof(item*));
	tail=(item *)malloc(sizeof(item*));
	list=(item **)malloc(sizeof(item**));
	count=0;
}
strlist_c::~strlist_c()
{
}
void strlist_c::probe()
{
	printf("strlist probe\nh:%p t:%p\n",head,tail);
}

#if(L_TYPE==LINK_LIST)
void strlist_c::push(const char * str)
{
	// Initialize new item _push
	_buff=(item**)malloc(sizeof(item **));
	*_buff=(item *)malloc(sizeof(item*));
	_temp=*_buff;
	_temp->set(str);


	if(count==0)
	{
		head=_temp;
		tail=NULL;
		count=1;
	}
	else if(count==1)
	{
		_temp->set_in(head);
		tail=_temp;
		count=2;
	}
	else
	{
		_temp->set_in(tail);
		count++;
	}
	_temp->probe();
	count++;
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
}
#elif(L_TYPE==ARRAY_TYPE)
void strlist_c::push(const char * str)
{
	//
	
	count++;
	list=(item **)realloc(list,count*sizeof(item**));
	if(list!=NULL)
	{
		list[count-1]->set(str);
	}
}
void strlist_c::show()
{
	for(uint idx=0;idx<count;idx++)
	{
		list[idx]->probe();
	}
}
#endif