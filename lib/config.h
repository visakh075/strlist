#ifndef _CONFIG_
#define _CONFIG_
#define ARRAY_TYPE 123
#define LINK_LIST 456
#define L_TYPE LINK_LIST
#define LOG_ENSY 1
#define LOG_BUFF_SZ 100
#define LOG_FILE "strlist_map.log"
//  DEBUG >>
    #include "lib_rtlog.h"
    #if(LOG_ENSY==1)
        extern rtlog map;
        extern char buff[LOG_BUFF_SZ];
        #define LOG() map + buff
        // Wrappper
        #define LOG_STR(x) ({sprintf(buff,x);map+buff;})
        #define LOG_ITM_INIT() {\
            sprintf(buff,"item * : %p %p",this,loc);\
            map + buff;\
        }
        #define LOG_ITM_SET() {\
            sprintf(buff,"item < : %p %p %s",this,loc,loc);\
            map + buff;\
        }
        #define LOG_ITM_PROBE() {\
            sprintf(buff,"item > : %p %p %s",this,loc,loc);\
            map + buff;\
        }
        #define LOG_ITM_DEST() {\
            sprintf(buff,"item ~ : %p %p %s",this,loc,loc);\
            map + buff;\
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

#endif