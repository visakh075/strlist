#ifndef __STRLIST__
#define __STRLIST__
typedef unsigned int uint;
class item{
	public:
		char * loc;
		uint len;
		item();
		~item();
		void set(const char *);
		void reset(const char *);
		void operator = (const char *);
		void probe();
};
typedef class item element;
uint strlen(const char *);
#endif
