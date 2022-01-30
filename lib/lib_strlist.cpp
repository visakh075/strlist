
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

void item_c::probe()
{
	printf("\np:%p l:%p [i:%p o:%p] %s",this,loc,in,out,loc);
}

item_c* item_c::push(const char * _str)
{
	MEM_MAPS("PUSH >>");
	item_c* temp;
	temp=(item_c *) malloc(sizeof(item));
	temp->set(_str);
	
	out=nullptr;
	temp->out=this;
	MEM_MAPS("<<PUSH");
	return temp;

}
// STRLIST
strlist_c::strlist_c()
{
	head=(item *)malloc(sizeof(item));
	tail=(item *)malloc(sizeof(item));
	ListCount=0;
}
strlist_c::~strlist_c()
{
}
void strlist_c::probe()
{
	printf("strlist probe\nh:%p t:%p\n",head,tail);
}
void strlist_c::push(const char * _str)
{
	item * temp=nullptr;
	if(ListCount==0)
	{
		head->set(_str);
		head->in=nullptr;
		head->out=nullptr;
		ListCount=1;
	}
	else if(ListCount==1)
	{
		tail->set(_str);
		tail->in=head;
		tail->out=nullptr;
		ListCount=2;
	}
	else
	{
		temp->set(_str);
		temp->in=tail;
		temp->out=nullptr;
		tail=temp;
		ListCount++;
	}
}
void strlist_c::show()
{
	item * temp;
	temp=head;

	while(temp->in!=nullptr)
	{
		temp->probe();
		temp=temp->in;
	}
}
