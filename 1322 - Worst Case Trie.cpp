using namespace std;
#include<bits/stdc++.h>
#define db          double
#define ll          long long
#define ull         unsigned long long
#define vi          vector<int>
#define vl          vector<long>
#define vll         vector<ll>
#define pi          pair<int,int>
#define pl          pair<long,long>
#define pll         pair<ll,ll>
#define pb          push_back
#define pf          printf
#define sf          scanf
#define mii         map<int,int>
#define mll         map<ll,ll>
#define II          ({int a; sf("%d",&a); a;})
#define IL          ({long a; sf("%ld",&a); a;})
#define ILL         ({ll a; sf("%lld",&a); a;})
#define ID          ({db a; sf("%lf",&a); a;})
#define IF          ({float a; sf("%f",&a); a;})
#define IC          ({char a; sf("%c",&a); a;})
#define FRI(a,b,c)  for(int i=a;   i<=b; i+=c)
#define FRL(a,b,c)  for(long i=a;  i<=b; i+=c)
#define FRLL(a,b,c) for(ll i=a;    i<=b; i+=c)
#define in          freopen("in.txt","r",stdin)
#define out         freopen("out.txt","w",stdout)
#define PI          2*acos(0.0)
#define mod         10000
#define INF         1<<29
ll dp[mod+1];
inline void func()
{
    dp[0]=1;
    dp[1]=2;
    FRL(1,mod,1)
    {
        dp[i]=(dp[i-1]*i+1)%mod;
    }
}
int main()
{
    func();
    ll t=ILL;
    ll i=1;
    while(t--)
    {
        ll k=ILL;
        if(k>=7)
            cout<<"Case "<<i++<<": "<<setfill('0')<<setw(4)<<dp[k%mod]<<endl;
        else
            cout<<"Case "<<i++<<": "<<dp[k%mod]<<endl;
    }
    return 0;
}
