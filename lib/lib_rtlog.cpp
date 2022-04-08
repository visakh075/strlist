#include <stdio.h>
#include <stdlib.h>
#include "lib_rtlog.h"
rt_log::c_rtlog::c_rtlog(char const * _l_file)
{
    l_file=_l_file;
    open(NORMAL);
}
rt_log::c_rtlog::c_rtlog(char const * _l_file,O_MODE m)
{
    l_file=_l_file;
    open(m);
}
rt_log::c_rtlog::~c_rtlog()
{
    fclose(log);
    // free(log);
}
void rt_log::c_rtlog::operator << (char const * str)
{
    fprintf(log,"%s\n",str);fflush(log);
}
rt_log::c_rtlog & rt_log::c_rtlog::operator + (char const * str)
{
    fprintf(log,"%s",str);fflush(log);
    return *this;
}

rt_log::c_rtlog & rt_log::c_rtlog::operator + (int _int)
{
    fprintf(log,"%d",_int);fflush(log);
    return *this;
}
rt_log::c_rtlog & rt_log::c_rtlog::operator + (double _dbl)
{
    fprintf(log,"%lf",_dbl);fflush(log);
    return *this;
}
rt_log::c_rtlog & rt_log::c_rtlog::operator + (long double _dbl)
{
    fprintf(log,"%Lf",_dbl);fflush(log);
    return *this;
}
rt_log::c_rtlog & rt_log::c_rtlog::operator + (float _flt)
{
    fprintf(log,"%f",_flt);fflush(log);
    return *this;
}
rt_log::c_rtlog & rt_log::c_rtlog::operator + (unsigned int _uint)
{
    fprintf(log,"%i",_uint);fflush(log);
    return *this;
}
rt_log::c_rtlog & rt_log::c_rtlog::operator + (char c)
{
    fprintf(log,"%c",c);fflush(log);
    return *this;
}
rt_log::c_rtlog & rt_log::c_rtlog::operator + (void * p)
{
    fprintf(log,"%p",p);fflush(log);
    return *this;
}
void rt_log::c_rtlog::open(rt_log::O_MODE mode)
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