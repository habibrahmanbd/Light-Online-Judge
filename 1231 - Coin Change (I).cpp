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
#define MOD 100000007
#define INF 1<<29
//Intput_Output
#define input freopen ("input.txt", "r", stdin);
#define output freopen ("output.txt", "w", stdout);
#define pf printf
#define sf scanf
#define co cout
#define ci cin
#define II ({ int a; scanf("%d",&a); a;}) //Integer Input
#define IL ({ int64 a; scanf("%I64d",&a);  a;})  //Long Integer Input
#define ID ({ db a; scanf("%lf",&a);  a;}) //Double input
#define IC ({ char a; scanf("%c",&a);  a;}) //Character Input
#define IS ({ string a; cin >> a;  a;}) //String input
#define ICA(n) ({ char a[n]; scanf("%s",&a);  a;}) //Char-Array Input
#define OC(cs) printf("Case %d:",cs);  //Case Input
//Loops.....
#define f(p, n, m) for(long int i=p; i<=n; i+=m)  //For Loop increment
#define fr(p, n, m) for(long int j=p; j>=n; j-=m)  //For loop decrement
//Problem wise define.....
int n,k;
int coins[51];
int number_of_coins[51];
int dp[51][1001];
int coin_change(int i,int amount)
{
    if(i>=n)
    {
        if(amount==k)
            return 1;
        else
            return 0;
    }
    if(amount>k)
        return 0;
    if(amount==k)
        return 1;
    if(dp[i][amount]!=-1)
        return dp[i][amount];
    int     ret=0;
    for(int j=1; j<=number_of_coins[i]; j++)
    {
        if(amount + coins[i]*j<=k)
            ret += coin_change(i+1, amount+coins[i]*j)%MOD;
        else
            break;
    }
    ret += coin_change(i+1,amount)%MOD;
    return dp[i][amount] = ret%MOD;
}
int main()
{
    input;
    int  t=II;
    int cs=1;
    while(t--)
    {
        memset(dp,-1,sizeof dp);
        n=II,k=II;
        f(0,n-1,1)
        coins[i]=II;
        f(0,n-1,1)
        number_of_coins[i]=II;
        pf("Case %d: %d\n",cs++,coin_change(0,0)%MOD);
    }
    return 0;
}
