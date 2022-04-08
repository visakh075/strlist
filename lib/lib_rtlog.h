#ifndef __rtlog__
#define __rtlog__
#include <stdio.h>
#define N_MODE "wb"
#define A_MODE "ab"
namespace rt_log
{
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
    c_rtlog & operator + (char const *);
    c_rtlog & operator + (int);
    c_rtlog & operator + (double);
    c_rtlog & operator + (long double);
    c_rtlog & operator + (float);
    c_rtlog & operator + (unsigned int);
    c_rtlog & operator + (char);
    c_rtlog & operator + (void *);
    
    
};}
typedef class rt_log::c_rtlog rtlog;
#endif