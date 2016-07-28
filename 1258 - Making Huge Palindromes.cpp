/*
Algorithm: KMP
A nice tutorial on KMP: http://www.iti.fh-flensburg.de/lang/algorithmen/pattern/kmpen.htm

Consider the 4th test case
P = anncbaaababaaa
Let
Q = aaababaaabcnna (reverse of P)

Now look how can we construct the shortest palindrome by adding character to the right of P,
with the help of Q

P : anncbaaababaaa|||||
Q : |||||aaababaaabcnna
Ans:anncbaaababaaabcnna

So all we need to do is search for the longest prefix of Q in P. You can do this by using KMP.
*/
#include <cstdio>
#include <cstring>
#include <time.h>
using namespace std;

#define MAX_N 1000004
//long long c=0;
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
int match=0;
void kmpSearch()
{
    int i = 0, j = 0;
//    c=0;
    while (i < n)
    {
        while (j >= 0 && T[i] != P[j])
            j = b[j];
        i++;
        j++;
//        if (j == m)
//        {
//            c++;
//            j = b[j];
//        }
    }
    match=j;
}

int main()
{
    int test;
    scanf("%d",&test);
    int ss=1;
    while(test--)
    {
        scanf("%s",T);
//        scanf("%s",P);
        n = (int)strlen(T);
        int j=0;
        for(int i=n-1; i>=0; i--)
            P[j++]=T[i];
        P[j]='\0';
        m = n;
        kmpPreprocess();
//        c=0;
        kmpSearch();
        printf("Case %d: %d\n",ss++,2*n-match);
    }
    return 0;
}

/*
Special Thanks to "Rafi Kamal, BUET 10" brother for his nice support pushing the solution to GITHUB
*/
