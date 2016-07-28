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
#define endl        '\n'

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
    db x, y, z;
    double dist(points p)
    {
        p.x -= x;
        p.y -= y;
        p.z -= z;
        return sqrt(p.x * p.x + p.y * p.y+ p.z*p.z);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    for(ll cs=1; cs<=t; cs++)
    {
        points a,b,p;
        cin>>a.x>>a.y>>a.z;
        cin>>b.x>>b.y>>b.z;
        cin>>p.x>>p.y>>p.z;
        db res=(db)(1e15);
        for(ll i=0; i<=50; i++)
        {
            points left, right;

            left.x= a.x+(b.x-a.x)/3.0;

            left.y= a.y+(b.y-a.y)/3.0;

            left.z= a.z+(b.z-a.z)/3.0;

            right.x= b.x-(b.x-a.x)/3.0;

            right.y= b.y-(b.y-a.y)/3.0;

            right.z= b.z-(b.z-a.z)/3.0;

            db m1 = p.dist(left);

            db m2 = p.dist(right);

            res=min(res,min(m1,m2));

            if(m1>m2)
                a=left;
            else
                b=right;
//            cout<<res<<endl;
        }
        cout<<"Case "<<cs<<": "<<setprecision(10)<<res<<endl;
    }
    return 0;
}
