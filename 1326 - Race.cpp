/*******************************
*   Bismillah hir Rohmanir Rahim *
*   Habibur Rahman Habib        *
*   Dept. of CSE, RUET          *
*   habib_cse_ruet@yahoo.com  *
********************************/

using namespace std;

#include <bits/stdc++.h>
//type def
#define PI 2*acos (0.0)
typedef long long int64;
typedef unsigned long long int64u;
#define db double
#define pb push_back
#define pii pair<int ,int >
#define NL puts("")
#define MAX(p,q) p>q?p:q
#define MIN(p,q) p<q?p:q
#define INF 1<<29
//Intput_Output
#define input freopen ("input.txt", "r", stdin);
#define output freopen ("output.txt", "w", stdout);
#define pf printf
#define sf scanf
#define co cout
#define ci cin
#define II ({ int a; scanf("%d",&a); a;}) //Integer Input
#define IL ({ long a; scanf("%ld",&a);  a;})  //Long Integer Input
#define ILL ({ int64 a; scanf("%I64d",&a);  a;})  //Long Integer Input
#define ID ({ db a; scanf("%lf",&a);  a;}) //Double input
#define IC ({ char a; scanf("%c",&a);  a;}) //Character Input
#define IS ({ string a; cin >> a;  a;}) //String input
#define ICA(n) ({ char a[n]; scanf("%s",&a);  a;}) //Char-Array Input
#define OC(cs) printf("Case %d: ",cs);  //Case Input
//Loops.....
#define f(p, n, m) for(long int i=p; i<=n; i+=m)  //For Loop increment
#define fr(p, n, m) for(long int j=p; j>=n; j-=m)  //For loop decrement
//Problem wise define.....
#define MOD 10056
int fact[1010];
int nSr[1010][1010];
int stirling(long n, long r)
{
    if(n==r||r==1)
        return 1;
    if(n<r)
        return 0;
    if(nSr[n][r]!=-1)
        return nSr[n][r];
    else
        return nSr[n][r]=(stirling(n-1,r-1)%MOD+(r%MOD*stirling(n-1,r)%MOD)%MOD)%MOD;
}
int main()
{
//    input;
    int t=II;
    memset(fact,-1,sizeof fact);
    memset(nSr,-1,sizeof nSr);
    fact[0]=1;
    fact[1]=1;
    for(int i=2; i<=1000; i++)
        fact[i]=(fact[i-1]%MOD * i%MOD )% MOD;
    int cs=1;
    while(t--)
    {
        int res=0;
        int n=II;
        for(int i=1; i<=n; i++)
            res = (res % MOD + (stirling(n,i)%MOD*fact[i]%MOD)%MOD)%MOD;
        OC(cs++);
        pf("%d\n",res);
    }
    return 0;
}
