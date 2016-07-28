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
#define mp          make_pair
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
#define all(V)      V.begin(),V.end()
#define in          freopen("in.txt","r",stdin)
#define out         freopen("out.txt","w",stdout)
#define PI          2*acos(0.0)
#define mod         1000000007
#define INF         LLONG_MAX
#define endl	    '\n'

template <class T> inline T bigmod(T p,T e,T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}
//------------------------------------------------------

ll dp[16][1<<16];
ll val[16][16];
ll n;
ll solve(int pos, int mask)
{
    if(pos>=n)
        return 0;
    if(dp[pos][mask]==(ll)-1)
    {
        for(int i=0; i<n; i++)
        {
            if(!(mask&(1<<i)))
                dp[pos][mask]=max(dp[pos][mask],val[pos][i]+solve(pos+1, mask|(1<<i)));
        }
    }
    return dp[pos][mask];
}
int main()
{
    ll t=ILL;
    for(ll i=1; i<=t; i++)
    {
        memset(dp, -1, sizeof(dp));
//        memset(val, 0, sizeof val);
        n=ILL;
        for(ll j=0; j<n; j++)
            for(ll k=0; k<n; k++)
                val[j][k]=II;

        ll res=solve(0,0);
        pf("Case %lld: %lld\n",i,res);
    }
    return 0;
}
