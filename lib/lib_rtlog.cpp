#include <stdio.h>
#include <stdlib.h>
#include "lib_rtlog.h"
c_rtlog::c_rtlog(char const * _l_file)
{
    l_file=_l_file;
    open(NORMAL);
}
c_rtlog::c_rtlog(char const * _l_file,O_MODE m)
{
    l_file=_l_file;
    open(m);
}
c_rtlog::~c_rtlog()
{
    fclose(log);
    // free(log);
}
void c_rtlog::operator << (char const * str)
{
    fprintf(log,"%s\n",str);fflush(log);
}
void c_rtlog::operator + (char const * str)
{
    fprintf(log,"%s",str);fflush(log);
}
void c_rtlog::operator + (int _int)
{
    fprintf(log,"%d",_int);fflush(log);
}

void c_rtlog::open(O_MODE mode)
{
    switch (mode)
    {
    case APPEND:
        log=fopen(l_file,A_MODE);
        break;

    case NORMAL:
    default:
        log=fopen(l_file,N_MODE);
        break;
    }
}