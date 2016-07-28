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

struct points
{
    db x, y;
    double dist(points p)
    {
        p.x -= x;
        p.y -= y;
        return sqrt(p.x * p.x + p.y * p.y);
    }
};
int main()
{
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        points a,b,c,d;
        a.x=ID,a.y=ID;
        b.x=ID,b.y=ID;
        c.x=ID,c.y=ID;
        d.x=ID,d.y=ID;
        db res=(db)LONG_LONG_MAX;
        for(ll i=0; i<=100; i++)
        {
            points a_a,b_b, c_c, d_d;

            a_a.x= a.x+(b.x-a.x)/3.0;
            a_a.y= a.y+(b.y-a.y)/3.0;

            c_c.x= c.x+(d.x-c.x)/3.0;
            c_c.y= c.y+(d.y-c.y)/3.0;

            b_b.x= b.x-(b.x-a.x)/3.0;
            b_b.y= b.y-(b.y-a.y)/3.0;

            d_d.x= d.x-(d.x-c.x)/3.0;
            d_d.y= d.y-(d.y-c.y)/3.0;

            db m1 = a_a.dist(c_c);
            db m2 = b_b.dist(d_d);
            res=min(res,min(m1,m2));

            if(m1>m2)
                a=a_a,c=c_c;
            else
                b=b_b,d=d_d;
//            cout<<res<<endl;
        }
        pf("Case %lld: %.10lf\n",cs,res);
    }
    return 0;
}
