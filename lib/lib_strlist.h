#ifndef __STRLIST__
#define __STRLIST__

#define LOG_ENSY 1
#define LOG_BUFF_SZ 100
#define LOG_FILE "strlist_map.log"
//  DEBUG >>
    #include "lib_rtlog.h"
    #if(LOG_ENSY==1)
        extern rtlog map;
        extern char buff[LOG_BUFF_SZ];
        #define LOG() map << buff
        // Wrappper
        #define LOG_STR(x) ({map<<x;})
        #define LOG_ITM_INIT() {\
            sprintf(buff,"item * : %p %p",this,loc);\
            map<<buff;\
        }
        #define LOG_ITM_SET() {\
            sprintf(buff,"item < : %p %p %s",this,loc,loc);\
            map<<buff;\
        }
        #define LOG_ITM_PROBE() {\
            sprintf(buff,"item > : %p %p %s",this,loc,loc);\
            map<<buff;\
        }
        #define LOG_ITM_DEST() {\
            sprintf(buff,"item ~ : %p %p %s",this,loc,loc);\
            map<<buff;\
        }
    #else
        #define LOG()
        // Wrappper
        
        #define LOG_STR(x)
        #define LOG_ITM_INIT()
        #define LOG_ITM_SET()
        #define LOG_ITM_PROBE()
        #define LOG_ITM_DEST()

    #endif
//  DEBUG <<

typedef unsigned int uint;
class item_c{
	public:
		char * loc;
		uint len;
        double flag;
		item_c *in ,*out;
		item_c();
		item_c(const char *);
		~item_c();
		void set(const char *);
		void reset(const char *);
		void probe();
		//void connect(item_c *,item_c *);
		void con_tail(item_c *);
		void con_head(item_c *);
		item_c* push(const char *);
		void operator = (const char *);
};
typedef class item_c item;
class strlist_c{
	public:
		item_c * head ,* tail;
		uint len;
		strlist_c();
		~strlist_c();
		void push(const char *);
		void probe();
		void show();
		item_c * get(uint index);
		item_c * getI(uint index);
		item_c * operator [] (uint index);

};
typedef class strlist_c strlist; 
uint strlen(const char *);
#endif
