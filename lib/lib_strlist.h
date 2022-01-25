#ifndef __STRLIST__
#define __STRLIST__
typedef unsigned int uint;
class item_c{
	public:
		char * loc;
		uint len;
		item_c *in ,*out;
		item_c();
		item_c(const char *);
		~item_c();
		void set(const char *);
		void reset(const char *);
		//void operator = (const char *);
		void probe();
		void connect(item_c *,item_c *);
		void set_out(item_c *);
		void set_in(item_c *);
		void push(const char *);
};
typedef class item_c item;
class strlist_c{
	public:
		item * _temp;
		item ** _buff;
		item * head;
		item * tail;
		#if(L_TYPE==ARRAY_TYPE)
		item ** list;
		#endif
		uint count;
		strlist_c();
		~strlist_c();
		void push(const char *);
		void probe();
		void show();
};
typedef class strlist_c strlist; 
uint strlen(const char *);
#endif
