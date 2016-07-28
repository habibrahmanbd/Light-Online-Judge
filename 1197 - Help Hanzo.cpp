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
#define p_z 1000005
ll prime[p_z/10];
bool is_prime[p_z+10];
ll total=0;
void prime_generate()
{
    is_prime[0]=is_prime[1]=1;
    for(ll i=4; i<=p_z; i+=2)
        is_prime[i]=1;
    for(ll i=2; i<=p_z; i++)
    {
        if(!is_prime[i])
        {
            prime[total++]=i;
            for(ll j=i*i; j<=p_z; j+=i)
                is_prime[j]=1;
        }
    }
    return;
}
bool vis[p_z+10];
int main()
{
    prime_generate();
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        ll a=ILL, b=ILL;
        ll ans=0;
        if(b<=100000)
        {
            ans=0;
            ll i;
            if(a<=2)
                i=3;
            else
                i=(a%2!=0?a:a+1);
            for(i; i<=b; i+=2)
            {
                if(is_prime[i]==0)
                    ans++;
            }
            if(a<=2&&b>=2)
                ans++;
        }
        else
        {
            ans=0;
            memset(vis,0,sizeof vis);
            ll n=(b-a);
            for(ll i=0; i<total&&prime[i]*prime[i]<=b; i++)
            {
                ll st=max((ll)a/prime[i]*prime[i], (ll)prime[i]*prime[i]);
                for(ll j=st; j<=b; j+=prime[i])
                    if(j>=a)
                        vis[b-j]=1;
            }
            for(ll i=0; i<=n; i++)
                if(vis[i]==0)
                    ans++;
            if(a==1)
                ans--;
        }
        pf("Case %d: %lld\n",cs, ans);

    }
    return 0;
}
