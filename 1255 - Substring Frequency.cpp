#include <cstdio>
#include <cstring>
#include <time.h>
using namespace std;

#define MAX_N 1000010
long long c=0;
char T[MAX_N], P[MAX_N];
int b[MAX_N], n, m;


void kmpPreprocess()
{
    int i = 0, j = -1;
    b[0] = -1;
    while (i < m)
    {
        while (j >= 0 && P[i] != P[j])
            j = b[j];
        i++;
        j++;
        b[i] = j;
    }
}

void kmpSearch()
{
    int i = 0, j = 0;
    c=0;
    while (i < n)
    {
        while (j >= 0 && T[i] != P[j])
            j = b[j];
        i++;
        j++;
        if (j == m)
        {
            c++;
            j = b[j];
        }
    }
}

int main()
{
    long long test;
    scanf("%lld",&test);
    for(long long sex=1; sex<=test; sex++)
    {
        scanf("%s",T);
        scanf("%s",P);
        n = (int)strlen(T);
        m = (int)strlen(P);
        kmpPreprocess();
        c=0;
        kmpSearch();
        printf("Case %lld: %lld\n",sex,c);
    }
    return 0;
}
