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
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        int n=II, d=II;
        deque<pi>dq1,dq2;
        vi v(n);
        for(int i=0; i<n; i++)
            v[i]=II;
        int ans=-1;
//        pf("here");
        for(int i=0; i<n; i++)
        {
            while(dq1.size()&&dq1.front().first>=v[i])
                dq1.pop_front();
            while(dq1.size()&&dq1.back().second<=i-d)
                dq1.pop_back();
            dq1.push_front(pi(v[i],i));
            while(dq2.size()&&dq2.front().first<=v[i])
                dq2.pop_front();
            while(dq2.size()&&dq2.back().second<=i-d)
                dq2.pop_back();
            dq2.push_front(pi(v[i],i));
            if(i>=d-1)
                ans=max(ans, abs(dq1.back().first-dq2.back().first));
        }
        pf("Case %d: %d\n",cs,ans);
    }
    return 0;
}
