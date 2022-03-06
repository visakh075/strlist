#include<stdio.h>
#include<stdlib.h>
#include "lib_rtlog.h"
rtlog log_file=rtlog("test.log");
int main()
{
    char * k =(char *)malloc(1);

    log_file + "hermit\n";
    log_file + "thenga" + "346"+ '*' + &k;
    log_file<<"uihihi";
    return(0);
}