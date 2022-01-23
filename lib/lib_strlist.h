#ifndef __STRLIST__
#define __STRLIST__
typedef unsigned int uint;
class item_c{
	public:
		char * loc;
		uint len;
		item_c *in ,*out;
		item_c();
		~item_c();
		void set(const char *);
		void reset(const char *);
		void operator = (const char *);
		void probe();
		void connect(item_c *,item_c *);
};
typedef class item_c item;
class strlist_c{
	public:
		item * _temp ;
		item * start;
		item * end;
		uint count;
		strlist_c();
		~strlist_c();
		void push(const char *);
};
typedef class strlist_c strlist; 
uint strlen(const char *);
#endif
