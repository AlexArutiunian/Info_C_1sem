#include <stdio.h>
#include <stdlib.h>            // It is the work with numbers like array. There are aruthmetic operations
#include <string.h>

int * get(int n)      // функция считывания символов из командной строки и записи их в массив
{
    int i = 0;
    int *Mn = (int * )malloc(sizeof(int) * n);
    for(i = 0; i < n; i++) scanf("%d", &Mn[i]);
    return Mn;
}

void prin(int *Mn, int n)          // функция для вывода числа составленного из введенных символов
{
    for(int i = 0; i < n; i++) printf("%d", Mn[i]);
    return;        
}

int * change(int n, int m, int *Mn, int *Mm){   // функция для сравнения двух чисел

    int *Mm2 = (int *)malloc(sizeof(int) * n);
    for(int i = 0; (m - i) >= 0; i++) Mm2[n - i] = Mm[m - i];
    for(int i = 0; i < n - m; i++) Mm2[i] = 0;
    return Mm2;    
   
}

int * sum(int *Mn, int *Mm2, int n)       // функция сложения в "столбик"
{
    int *Sum = (int *)malloc(sizeof(int) * n);
    memset(Sum, 0, sizeof(int) * n);
    for(int i = n - 1; i >= 0; i--)
    {
        int s = Mn[i] + Mm2[i];
        if((s >= 10) || ((s + Sum[i]) >= 10))
        {
            Sum[i - 1] = Sum[i - 1] + 1;
            Sum[i] = Sum[i] + s - 10;
        }
        else Sum[i] = Sum[i] + s;
    }  
    return Sum;
}

int * Diff(int *Mn, int *Mm2, int n)     // функция вычитания в "столбик"
{
    int *diff = (int *)malloc(sizeof(int) * n);
    memset(diff, 0, sizeof(int) * n);
    for(int i = n - 1; i >= 0; i--)
    {
        int d = Mn[i] - Mm2[i];
        if(d < 0)
        {
            Mn[i - 1] = Mn[i - 1] - 1; 
            diff[i] = (10 + Mn[i]) - Mm2[i];
        }
        else diff[i] = diff[i] + d;
    }  
    return diff;
}

int comp(int n, int m, int *Mn, int *Mm)
{
    if(n > m) return 1;
    else
    { 
        if(n == m)
        {
            int i = 0;
            while(Mn[i] == Mm[i]) i++;
            if(Mn[i] > Mm[i]) return 1;
            else return 0;
        }
        else return -1;
          
    } 

}

int inp(int n, int * Mn)
{
    int i = 0;
    for(i = n; i >= 1; i--)
    {
        for(int i1 = 1; i1 < i; i1++) Mn[n - i] = Mn[n - i] * 10;
    }
    int s = 0;
    for(i = n; i >= 1; i--) s = s + Mn[n - i];
    return s;
}

int nod(int a, int b)
{
    while((a - b) != 0)
    {
        if(a > b)
            a = a - b;
        else
            b = b - a;
    }
    printf("NOD = %d", a);
    return a;
}

int * inc(int x, int * Mn, int n)
{
    int * I = (int *)malloc(sizeof(int) * (n + 1));
    memset(I, 0, sizeof(int) * (n + 1));
    for(int i = n - 1; i >= 0; i--)
    {
        int P = Mn[i] * x;
        if(P > 9)
        {

            I[i + 1] = (Mn[i] * x) % 10 + I[i + 1];
            int t = I[i + 1];
            if(t >= 10)
            {
                I[i + 1] = I[i + 1] % 10;
                I[i] = I[i] + t / 10 + (Mn[i] * x) / 10;
            }
            else I[i] = I[i] + (Mn[i] * x) / 10;
        }
        else I[i + 1] = I[i + 1] + P;
    }
    return I;
}


int main()
{
    int n = 0;
    printf("Input number of digits 1st = ");
    scanf("%d", &n);
    printf("Input numbers of 1st with a space = ");
    int *Mn = get(n);
    int *N = (int *)malloc(sizeof(int) * n);
    
    for(int i = 0; i < n; i++) N[i] = Mn[i];
    
    int *I1 = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) I1[i] = Mn[i];
    printf("\n");
    
    int m = 0;
    printf("Input number of digits 2nd = ");
    scanf("%d", &m);
    printf("Input numbers of 2nd with a space = ");
    int *Mm = get(m);
    int *M = (int *)malloc(sizeof(int) * m);
    for(int i = 0; i < m; i++) M[i] = Mm[i];
    
    int *I2 = (int *)malloc(sizeof(int) * m);
    for(int i = 0; i < m; i++) I2[i] = Mm[i];

    int *Mm2;
    if(n > m)
    {
        Mm2 = change(n, m, Mn, Mm);
        printf("\nBig number: ");
        prin(Mn, n);
        printf("\nLittle number: ");
        prin(Mm2, n);
        printf("\nSum = ");
        int *Sum = sum(Mn, Mm2, n);
        prin(Sum, n);
        
        int *d = Diff(Mn, Mm2, n);
        printf("\nDiff = ");
        prin(d, n);
        
        int c = comp(n, m, Mn, Mm2);
        printf("\n %d \n", c);
	    free(Mm2);
    }
    else
    {
        Mm2 = change(m, n, Mm, Mn);
        if(n == m){
            printf("\n1st number: ");
            prin(Mm, m);
            printf("\n2nd number: ");
            prin(Mm2, m);
        }
        else{
            printf("\nBig number: ");
            prin(Mm, m);
            printf("\nLittle number: ");
            prin(Mm2, m);
        }
        
        printf("\nSum = ");
        int *Sum = sum(Mm, Mm2, m);
        prin(Sum, m);
        
        int *d = Diff(Mm, Mm2, m);
        printf("\nDiff = ");
        prin(d, m);
        int c = comp(n, m, Mm, Mm2);if(c > 0){
            prin(Mn, n);
            printf(" > ");
            prin(Mm2, n);
        }
        if(c < 0){
            prin(Mn, n);
            printf(" < ");
            prin(Mm2, n);
        }
        else printf("numbers are equal!");
        printf("\n %d \n", c);
        free(Mm2);
    }  
    
    int Nn = inp(n, N);
    int Nm = inp(m, M);

    nod(Nn, Nm);
    
    int k = 0;
    printf("\nEnter the number, which you want to multiply = ");
    scanf("%d", &k);
    
    int * II1 = inc(k, I1, n);
    int * II2 = inc(k, I2, m);
    
    printf("number * %d : ", k);
    prin(II1, (n + 1));
    printf(" and ");
    prin(II2, (m + 1));
    printf("\n");

    free(Mn);
    free(M);
    free(N);    
    free(Mm);
    free(I1);
    free(I2);
    return 0;
}
