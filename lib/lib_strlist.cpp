
#include "config.h"
#include "lib_strlist.h"
#include <stdlib.h>
#include <stdio.h>
#include "lib_rtlog.h"
#include <cstddef>
//	DEBUG >>
	// Definition
	#if(LOG_ENSY==1)
	rtlog map=rtlog(LOG_FILE,NORMAL);
	char buff[LOG_BUFF_SZ];
	#define LOG() map + buff
	#endif
//	DEBUG <<

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
	set(_str);
}
item_c::item_c()
{
	in=(item_c *)malloc(sizeof(item_c));
	out=(item_c *)malloc(sizeof(item_c));
	loc=(char *)malloc(sizeof(char));
	len=0;

	#if(LOG_ENSY==1)
	sprintf(buff,"item * : %p %p",this,loc);
	LOG();
	#endif
}
item_c::~item_c()
{
	#if(LOG_ENSY==1)
	sprintf(buff,"item ~ : %p %p %s",this,loc,loc);
	LOG();
	#endif
	
	
	in=nullptr;
	out=nullptr;
	loc=nullptr;
	// free(loc);
}
void item_c::set(const char * strptr)
{
	loc=nullptr;
	
	loc=(char *)realloc(loc,sizeof(char)*strlen(strptr)+1);
	
	if(loc!=nullptr)
	{
		strcpy(strptr,loc);
		len=strlen(strptr);
	}
	else
	{
		printf("\nmallloc error");fflush(stdout);
	}
	
	#if(LOG_ENSY==1)
	sprintf(buff,"item < : %p %p %s",this,loc,loc);
	LOG();
	#endif
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

item_c* item_c::push(const char * _str)
{
	MEM_MAPS("PUSH >>");
	item_c* temp;
	temp=(item_c *) malloc(sizeof(item));
	temp->set(_str);
	
	//item_c(_str);
	//temp.set(_str);
	//in=temp;
	out=nullptr;
	temp->out=this;
	MEM_MAPS("<<PUSH");
	return temp;
	//temp.probe();
}

strlist_c::strlist_c()
{
	head=(item *)malloc(sizeof(item*));
	tail=(item *)malloc(sizeof(item*));
	#if(L_TYPE==ARRAY_TYPE)
	list=(item **)malloc(sizeof(item**));
	#endif
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
		tail=nullptr;
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
	if(list!=nullptr)
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