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
#define EPS 0.000000001
int main()
{
    ll t=ILL;
    for(ll i=1; i<=t; i++)
    {
        db a,b;
        sf("%lf : %lf",&a,&b);
        db high=400.0, low=0.0;
        while(fabs(high-low)>EPS)
        {
            db len =(high+low)/2.0;
            db half_len = len/2.0;
            db width = (b*len)/a;
            db half_width = width/2.0;
            db rad = sqrt((half_len*half_len) + (half_width*half_width));
            db theta = acos(half_len/rad);
            db arc  = theta*rad;
            db ex_arc = (200.0-len)/2.0;
            if(arc>ex_arc)
                high = len;
            else low = len;
        }
        pf("Case %lld: %.8lf %.8lf\n",i, low, (b*low)/a);
    }
    return 0;
}
