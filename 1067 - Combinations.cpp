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
#define OC(cs) printf("Case %d:",cs);  //Case Input
//Loops.....
#define f(p, n, m) for(long int i=p; i<=n; i+=m)  //For Loop increment
#define fr(p, n, m) for(long int j=p; j>=n; j-=m)  //For loop decrement
//Problem wise define.....
#define MOD 1000003
long long fact[1000002];
long long BigMod(long long b,long long p)
{
    if(p==1)
        return b;
    if(p%2==1)
        return(BigMod(b,p-1)*b)%MOD;
    else
    {
        long long res=BigMod(b,p/2);
        return (res*res)%MOD;
    }
}
int main()
{
    int64 t=ILL;
    int64 cs=1;
    fact[0]=1;
        fact[1]=1;
    for(long long i=2; i<1000001; i++)
        fact[i]=(fact[i-1]*i)%MOD;
//    vector<int64>r;
//    r[1]=1;
//    for(long long i=2; i<1000004;i++)
//        r[i] = (MOD - (MOD/i) * r[MOD%i] % MOD) % MOD;
    while(t--)
    {
        int64 n=ILL, r=ILL;
        //cout<<fact[n-r]<<" "<<fact[r]<<endl;
        int64 p  = ((fact[n-r]%MOD)*(fact[r]%MOD))%MOD;
        //cout<<BigMod(p,MOD-2)<<endl;
        int64 res = (fact[n]%MOD*BigMod(p,MOD-2)%MOD)%MOD;
//        int q= r[p];
//        int64 res = (fact[n]%MOD*r[p]%MOD)%MOD;
        pf("Case %lld: %lld\n",cs++,res);
    }
    return 0;
}
