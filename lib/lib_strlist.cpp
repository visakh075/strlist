#include "lib_strlist.h"
#include <stdlib.h>
#include <stdio.h>
#include "lib_rtlog.h"
#include <cstddef>

//	DEBUG >>>
	// Definition
	#if(LOG_ENSY==1)
	rtlog map=rtlog(LOG_FILE,rt_log::NORMAL);
	char buff[LOG_BUFF_SZ];
	#define LOG() map << buff
	#endif
//	DEBUG <<<

// EXTRA >>>
namespace gen
{
uint strlen(const char * strptr)
{
	uint retVal=0;
	while(*strptr++)retVal++;
	return retVal;
}
void strcpy(const char * frm,char * to)
{
	while((*to++=*frm++)){};
}
}
// EXTRA <<<

// ITEM >>>
item::item_c(const char * _str)
{
	set(_str);
}
item::item_c()
{
	in=(item_c *)malloc(sizeof(item_c));
	if(in==NULL)
	{
		LOG_STR("memmory allocation error");
	}
	out=(item_c *)malloc(sizeof(item_c));
	if(out==NULL)
	{
		LOG_STR("memmory allocation error");
	}

	loc=(char *)malloc(sizeof(char));
	if(loc==NULL)
	{
		LOG_STR("memmory allocation error");
	}
	len=0;

	LOG_ITM_INIT();
}
item::~item_c()
{
	LOG_ITM_DEST();
	free(loc);
	in=nullptr;
	out=nullptr;
	loc=nullptr;
}
void item::set(const char * strptr)
{
	loc=nullptr;
	
	loc=(char *)realloc(loc,sizeof(char)*gen::strlen(strptr)+1);
	
	if(loc!=nullptr)
	{
		gen::strcpy(strptr,loc);
		len=gen::strlen(strptr);
	}
	else
	{
		LOG_STR("memmory re-allocation error");
	}
	LOG_ITM_SET();
}
void item::reset(const char * strptr)
{
	if(loc!=nullptr)
	{
		free(loc);
	}
	set(strptr);
}
void item::probe()
{
	LOG_ITM_PROBE();
	printf("\np:%p l:%p [i:%p o:%p] %s",this,loc,in,out,loc);
}
void item::con_tail(item * _tail)
{
	out=_tail;
	_tail->in=this;
}
void item::con_head(item * _head)
{
	in=_head;
	_head->out=this;
}
item * item::push(const char * _str)
{
	item_c* temp;
	temp=(item_c *) malloc(sizeof(item));
	temp->set(_str);
	
	out=nullptr;
	temp->out=this;
	return temp;

}
// ITEM <<<

// STRLIST >>>
strlist::strlist_c()
{
	LOG_STR("strlist init");
	head=(item *)malloc(sizeof(item));
	LOG_STR("memmory allocation head");
	
	tail=(item *)malloc(sizeof(item));
	LOG_STR("memmory allocation tail");
	
	len=0;
}
strlist::~strlist_c()
{
	
	if (len<3)
	{
		//free(head->loc);free(tail->loc);
		tail->~item_c();
		head->~item_c();
		free(tail);
		free(head);
	}
	else
	{
		item * temp =nullptr;
		temp=tail;
		item * x_temp;
		while(temp!=nullptr)
		{
			x_temp=temp->in;
			temp->~item_c();
			free(temp);
			temp=x_temp;
		}

	}
	LOG_STR("strlist deleted");
}
void strlist::probe()
{
	printf("strlist probe\nh:%p t:%p\n",head,tail);
}
void strlist::push(const char * _str)
{
	
	if(len==0)
	{
		head->set(_str);
		head->in=nullptr;
		head->out=nullptr;
		len=1;
	}
	else if(len==1)
	{
		tail->set(_str);
		head->con_tail(tail);
		tail->out=nullptr;
		len=2;
	}
	else
	{
		item * temp=nullptr;
		temp=(item*)malloc(sizeof(item));
	
		temp->set(_str);
		tail->con_tail(temp);
		tail=temp;
		len++;
	}
	
}
void strlist::show()
{
	
	if(len==0)
	{

	}
	else if(len==1)
	{
		head->probe();
	}
	else
	{
		item * temp=nullptr;
		temp=head;
		while(temp!=nullptr)
		{
			temp->probe();
			temp=temp->out;
		}
	}
}
item * strlist::get(uint idx)
{
	if(idx==0) return head;
	else if(idx>0 && idx<=len)
	{
		uint count=0;
		item * temp;
		temp=head;
		while(count<idx)
		{
			temp=temp->out;
			count++;
		}
		return temp;
	}
	return nullptr;
}
item * strlist::getI(uint idx)
{
	if(idx==0) return tail;
	else if(idx>0 && idx<=len)
	{
		uint count=0;
		item * temp;
		temp=tail;
		while(count<idx)
		{
			temp=temp->in;
			count++;
		}
		return temp;
	}
	return nullptr;
}
item * strlist::operator[] (uint index)
{
	return getI(index);
}
void item::operator = (const char * strptr)
{
	reset(strptr);
}
// STRLIST <<<