#include<stdio.h>
#include<stdlib.h>
#include "lib_strlist.h"
#include "lib_rtlog.h"
#include "dummy.h"
int main()
{
    char Key;
    bool stop=false;
    bool prompt=true;
    char str[100];
    int idx;
    strlist listx;
    while(!stop)
    {
        printf("\n> ");
        // char tKey=getchar();
        // if(tKey!=13)
        // {
        //     tKey=Key;
        // }
        // else
        // {
        //     Key=tKey;
        // }
        Key=getchar();
        switch (Key)
        {
        case '*':
            printf("\n> ");
            scanf("%s",str);
            listx.push(str);
            if(prompt)listx.show();
            break;
        case '.':
            listx.show();
            break;
        case 'p':
            prompt=!prompt;
            printf("\nprompt: %d",prompt);
            break;
        case ':' :
            scanf("%d",&idx);
            listx.get(idx)->probe();
        case 'e':
            stop=true;
            break;
        default:
            break;
        }
    }
}