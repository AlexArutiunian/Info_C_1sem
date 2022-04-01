#include <stdio.h>

int main()
{
    int x, y = 0;
    char s = '\0';
    
    while(s != 'e')
    {
        int k;
        char e;
        scanf("%d%c%d", &x, &s, &y);
        
        if(s == '+')
            k = x + y;
        if(s == '-')
            k = x - y;
        if(s == '~')
            k = ~ y;
        if(s == '*')
            k = x * y;
        if(s == '/')
            k = x / y;
        if(s == '%')
            k = x % y;
        if(s == '&')
            k = x & y;
        if(s == '|')
            k = x | y;
        if(s == '^')
            k = x ^ y;
            
        printf("%d", k);
        
    }
    printf(" - past result");
    printf("\nexit");

    return 0;
}
