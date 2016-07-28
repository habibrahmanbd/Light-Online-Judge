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


int main()
{
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        ll s=ILL;
        ll x = (ll)ceil(sqrt(s));
        ll y = (((x*x) + ((x - 1)*(x-1)) + 1) / 2LL) - s;
        if (x & 1)
        {
            if (y < 0) y = x + y, swap(x,y);
            else y = x - y;
        }
        else
        {
            if (y < 0) y = x + y;
            else y = x - y, swap(x, y);
        }
        /*************************TLE SOLUTION************************
        //        ll even=0;
        //        ll i;
        //        ll x=1,y=1;
        //        ll po=0;
        //        for(i=1; i<s; i+=even)
        //            even+=2,x++,y++,po++;
        //        ll temp=even;
        //        temp--;
        //        ll bac = (i-even);
        //        ll remain = (i-s);
        //        if(po%2)
        //        {
        //            if(remain<=(temp+1)/2)
        //            {
        //                x-=remain;
        //                cout<<"Here in Odd Po & remain<=(temp+1)/2"<<endl;
        //            }
        //            else
        //            {
        //                cout<<"Here in Odd Po & remain>(temp+1)/2"<<endl;
        //                y--;
        //                remain-=(temp+1)/2;
        //                x=1;
        //                x+=(remain-1);
        //            }
        //
        //        }
        //        else
        //        {
        //            if(remain<=(temp+1)/2)
        //                y-=remain;
        //            else
        //            {
        //                x--;
        //                remain-=(temp+1)/2;
        //                y=1;
        //                y+=(remain-1);
        //            }
        //        }
        /******************************************************/
        pf("Case %lld: %lld %lld\n",cs,x,y);
    }
    return 0;
}
