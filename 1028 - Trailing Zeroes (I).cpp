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
#define s 1000010
bool col[s];
ll prime[s];
ll maxim;
void seive()//1 indexed
{
    ll i,j,k;
    col[0]=true;
    col[1]=true;
    k=0;
    prime[++k]=2;
    for(j=4;j<s;j+=2)
        col[j]=true;
    for(i=3;i<s;i+=2)
         if(!col[i])
         {
                prime[++k]=i;
                for(j=i*i;j<s;j+=2*i)
                    col[j]=true;
         }
    maxim=k;
    return;
}

int main()
{
    seive();
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        ll n=ILL;
        ll res=1;
        for(ll i=1; prime[i]*prime[i]<=n && i<=maxim; i++)
        {
            ll cnt=0;
            if(n%prime[i]==0)
            {
                while(n%prime[i]==0)
                {
                    n/=prime[i];
                    cnt++;
                }
            }
            res*=(cnt+1);
        }
        if(n>1)
            res*=2;
        res-=1;
        pf("Case %d: %lld\n",cs, res);
    }
    return 0;
}
