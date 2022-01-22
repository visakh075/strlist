#ifndef __STRLIST__
#define __STRLIST__
typedef unsigned int uint;
class item{
	public:
		char * loc;
		uint len;
		item *in ,*out;
		item();
		~item();
		void set(const char *);
		void reset(const char *);
		void operator = (const char *);
		void probe();
		void connect(item *,item *);
		//void connect(item,item);
};
class strlist{
	public:
		item start;
		item end;
};
typedef class item element;
uint strlen(const char *);
#endif
