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
#define PI          acos(-1.0)
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


int main()
{
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        db r1=ID, r2=ID, r3=ID;
        db a=r1+r2, b=r2+r3, c=r3+r1;
        db A = acos(((b*b)+(c*c)-(a*a))/(2.0*b*c));
        db B = acos(((a*a)+(c*c)-(b*b))/(2.0*a*c));
        db C = acos(((b*b)+(a*a)-(c*c))/(2.0*b*a));
        db sum=0.0;
        sum = ((r1*r1*B)/2.0);
        sum += ((r2*r2*C)/2.0);
        sum += ((r3*r3*A)/2.0);

        db s = (a+b+c)/2.0;
        db Area_T = sqrt(s*(s-a)*(s-b)*(s-c));
        pf("Case %lld: %.10lf\n",cs,fabs(Area_T)-sum);

    }
    return 0;
}
