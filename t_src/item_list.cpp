#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include "lib_strlist.h"
#include "dummy.h"

#define TEST_NX 10
void push(const char *);
void show();
item ** list;
int lc=0;
int main()
{
    list=nullptr;
    list=(item**)malloc(sizeof(item*));

    for (int i = 0; i < TEST_NX; i++)
    {
        push(dummy[i]);
        //show();
    }
    show();
    for (int i = 0; i < TEST_NX; i+=2)
    {
        list[i]->set(dummy[TEST_NX+i]);
        //show();
    }
    show();
}
void push(const char * str)
{
    item *temp=nullptr;
    temp=(item*)malloc(sizeof(item));
    temp->set(str);
    lc++;
    list=(item**)realloc(list,lc*sizeof(item*));
    list[lc-1]=temp;
}
void show()
{
    printf("\n>BEGIN<");
    for (int i = 0; i < lc; i++)
    {
        list[i]->probe();
        //printf("\n%d %p %s",i,list[i],list[i]->loc);
    }
    printf("\n>END<");
    
}