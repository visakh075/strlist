#ifndef __rtlog__
#define __rtlog__
#include <stdio.h>
#define N_MODE "wb"
#define A_MODE "ab"

enum O_MODE
{
    NORMAL,
    APPEND
};

class c_rtlog
{
private:
    
public:
    FILE * log;
    char const * l_file;
    c_rtlog(char const * l_file);
    c_rtlog(char const * l_file,O_MODE m);
    ~c_rtlog();
    void open(O_MODE l);
    void close();
    void operator << (char const *);
    void operator + (char const *);
    
};
typedef class c_rtlog rtlog;
#endif