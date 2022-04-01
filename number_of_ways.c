#include <stdio.h>

int main()
{                                // Example input: 3 5
    int n, m;                    //  # 0 0 0 #
    scanf("%d %d", &n, &m);      //  # 0 0 # #
                                 //  # # 0 0 0
    char p[100][100];
    int i, k = 0;
    for(i = 0; i < n; i++)
    {
        for(k = 0; k < m; k++)
        {
            char c = getchar();
            scanf("%c", &p[i][k]);
        }
    }
    int p1[100][100];
    k = 0;
    int g = 0;
    for(i = 0; i < n; i++)
    {
        if(p[i][0] == '#')
        {
            k = i;                
            g = -1;
            break;
        }
    }
    if(g == -1)
    {
        for(i = k; i < n; i++)
        {
            p1[i][0] = 0;
        }
        for(i = k - 1; i >= 0; i--)
        {
            p1[i][0] = 1;
        }
    }
    if(g == 0)
    {
        for(i = k; i < n; i++)
        {
            p1[i][0] = 1;
        }
    }
    
    g = 0;
    k = 0;
    for(i = 0; i < m; i++)
    {
        if(p[0][i] == '#')
        {
            k = i;
            g = -1;
            break;
        }
    }
    if(g == -1)
    {
        for(i = k; i < m; i++)
        {
            p1[0][i] = 0;
        }
        for(i = k - 1; i >= 0; i--)
        {
            p1[0][i] = 1;
        }
    } 
    if(g == 0)
    {
        for(i = k; i < m; i++)
        {
            p1[0][i] = 1;
        }
    }
    
    for(i = 1; i < n; i++)
    {
        for(k = 1; k < m; k++)
        {
            p1[i][k] = 0;
        }
    }
    
    for(i = 1; i < n; i++)
    {
        
        for(k = 1; k < m; k++)
        {
            if(p[i][k] == '#')
            {
                p1[i][k] = 0;
            }
            else
            {
                p1[i][k] = p1[i][k - 1] + p1[i - 1][k];
            }
        }
    }
    printf("\n");    
    for(i = 0; i < n; i++)
    {
        for(k = 0; k < m; k++)
        {
            printf("%d ", p1[i][k]);
        }
        printf("\n");
    }
    printf("Number of ways = %d", p1[n - 1][m - 1]);
    return 0;
}
