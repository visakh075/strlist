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
c_rtlog & c_rtlog::operator + (char const * str)
{
    fprintf(log,"%s",str);fflush(log);
    return *this;
}

c_rtlog & c_rtlog::operator + (int _int)
{
    fprintf(log,"%d",_int);fflush(log);
    return *this;
}
c_rtlog & c_rtlog::operator + (double _dbl)
{
    fprintf(log,"%lf",_dbl);fflush(log);
    return *this;
}
c_rtlog & c_rtlog::operator + (long double _dbl)
{
    fprintf(log,"%Lf",_dbl);fflush(log);
    return *this;
}
c_rtlog & c_rtlog::operator + (float _flt)
{
    fprintf(log,"%f",_flt);fflush(log);
    return *this;
}
c_rtlog & c_rtlog::operator + (unsigned int _uint)
{
    fprintf(log,"%i",_uint);fflush(log);
    return *this;
}
c_rtlog & c_rtlog::operator + (char c)
{
    fprintf(log,"%c",c);fflush(log);
    return *this;
}
c_rtlog & c_rtlog::operator + (void * p)
{
    fprintf(log,"%p",p);fflush(log);
    return *this;
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