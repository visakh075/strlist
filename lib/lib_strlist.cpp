#include "config.h"
#include "lib_strlist.h"
#include <stdlib.h>
#include <stdio.h>
#include "lib_rtlog.h"
#include <cstddef>

//	DEBUG >>>
	// Definition
	#if(LOG_ENSY==1)
	rtlog map=rtlog(LOG_FILE,NORMAL);
	char buff[LOG_BUFF_SZ];
	#define LOG() map + buff
	#endif
//	DEBUG <<<

// EXTRA >>>
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
		#if(LOG_ENSY==1)
		MEM_MAPS("memmory allocation error");
		#endif
	}
	out=(item_c *)malloc(sizeof(item_c));
	if(out==NULL)
	{
		#if(LOG_ENSY==1)
		MEM_MAPS("memmory allocation error");
		#endif
	}

	loc=(char *)malloc(sizeof(char));
	if(loc==NULL)
	{
		#if(LOG_ENSY==1)
		MEM_MAPS("memmory allocation error");
		#endif
	}
	len=0;

	#if(LOG_ENSY==1)
	sprintf(buff,"item * : %p %p",this,loc);
	LOG();
	#endif
}
item::~item_c()
{
	#if(LOG_ENSY==1)
	sprintf(buff,"item ~ : %p %p %s",this,loc,loc);
	LOG();
	#endif

	free(loc);
	in=nullptr;
	out=nullptr;
	loc=nullptr;
}
void item::set(const char * strptr)
{
	if(loc!=nullptr)free(loc);
	loc=nullptr;
	
	loc=(char *)realloc(loc,sizeof(char)*strlen(strptr)+1);
	
	if(loc!=nullptr)
	{
		strcpy(strptr,loc);
		len=strlen(strptr);
	}
	else
	{
		#if(LOG_ENSY==1)
		MEM_MAPS("memmory re-allocation error");
		#endif
	}
	#if(LOG_ENSY==1)
	sprintf(buff,"item < : %p %p %s",this,loc,loc);
	LOG();
	#endif
}
void item::probe()
{
	#if(LOG_ENSY==1)
	sprintf(buff,"item > : %p %p %s",this,loc,loc);
	LOG();
	#endif
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
	head=(item *)malloc(sizeof(item));
	#if(LOG_ENSY==1)
	MEM_MAPS("memmory allocation head");
	#endif

	tail=(item *)malloc(sizeof(item));
	#if(LOG_ENSY==1)
	MEM_MAPS("memmory allocation tail");
	#endif

	ListCount=0;
}
strlist::~strlist_c()
{
	
	if (ListCount<3)
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
}
void strlist::probe()
{
	printf("strlist probe\nh:%p t:%p\n",head,tail);
}
void strlist::push(const char * _str)
{
	#if(LOG_ENSY==1)
	//MEM_MAPS("<PUSH>");
	#endif
	
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
		head->con_tail(tail);
		tail->out=nullptr;
		ListCount=2;
	}
	else
	{
		item * temp=nullptr;
		temp=(item*)malloc(sizeof(item));
	
		temp->set(_str);
		tail->con_tail(temp);
		tail=temp;
		ListCount++;
	}
	#if(LOG_ENSY==1)
	//MEM_MAPS("</PUSH>");
	#endif
	//free(temp);
	
}
void strlist::show()
{
	
	if(ListCount==0)
	{

	}
	else if(ListCount==1)
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
	else if(idx>0 && idx<=ListCount)
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
	else if(idx>0 && idx<=ListCount)
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
// STRLIST <<<