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
ll fact[21],n;
ll a[21];
void solve()
{
    ll m=0;
    for(ll i=20; i>=0; i--)
    {
        if(n>=fact[i])
        {
            n-=fact[i];
            a[m++]=i;
        }
    }
    if(n)
        n=-1;
    else n=m;
}
int main()
{
    fact[0]=(ll)1;
    for(ll i=1; i<=20 ;i++)
        fact[i]=fact[i-1]*i;
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        n=ILL;
        solve();
//        cout<<n<<endl;
        if(n<0)
            pf("Case %lld: impossible\n",cs);
        else
        {
            pf("Case %lld: ",cs);
            for(ll i=n-1; i>0; i--)
                pf("%lld!+",a[i]);
            pf("%lld!\n",a[0]);
        }
    }
    return 0;
}
