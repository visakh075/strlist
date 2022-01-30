#ifndef _CONFIG_
#define _CONFIG_
#define ARRAY_TYPE 123
#define LINK_LIST 456
#define L_TYPE LINK_LIST
#define LOG_ENSY 1
#define LOG_BUFF_SZ 100
#define LOG_FILE "mem_map"
//  DEBUG >>
    #include "lib_rtlog.h"
    #if(LOG_ENSY==1)
    extern rtlog map;
    extern char buff[LOG_BUFF_SZ];
    #define LOG() map + buff
    #endif

    // Wrappper
    #define MEM_MAP map + buff
    #define MEM_MAPS(x) ({sprintf(buff,x);map+buff;})
//  DEBUG <<

#endif