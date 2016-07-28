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
#define MS 100000

#define eui 0.57721566490153286060651209008240243104215933593992
int main()
{
//    freopen("input.txt", "r", stdin);
    int test, cs= 1;
    int n;
    double h[MS+1];
    scanf("%d", &test);
    h[0] = 0.0;
    double nh = 1.0;
    int ind = 1000;
    for(int i = 2; i <= 100000000; i++)
    {
        nh += 1.0/i;
        if(i == ind)
        {
            h[ind/1000] = nh;
            ind += 1000;
        }
    }

    while( test-- )
    {
        scanf("%d", &n);
        nh = h[n/1000];
        for(int i = (n/1000) * 1000 + 1 ; i <= n; i++)
            nh += 1.0/i;
        printf("Case %d: %.10lf\n", cs++, nh );
    }
    return 0;
}
