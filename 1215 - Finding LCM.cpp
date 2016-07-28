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

ll prime[78598];
bool is_prime[1000000];
ll tot;

void solve()
{
    tot=0;
    is_prime[0]=is_prime[1]=1;
    for(ll i=2; i<1000000; i++)
        if(!is_prime[i])
        {
            prime[tot++]=i;
            for(ll j=i*2; j<1000000; j+=i)
            {
                is_prime[j]=1;
            }
        }
}

int function_for_prime(ll n, ll p)
{
    int count=0;
    while(n%p==0&&n>0)
    {
        count++;
        n/=p;
    }
    return count;
}
int main()
{
    solve();
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        ll a=ILL, b=ILL, L=ILL;
        if(L%a||L%b)
            pf("Case %d: impossible\n",cs);
        else
        {
            ll res=1;
            for(int i=0; prime[i]*prime[i]<=L; i++)
            {
                int count=0;
                while(L%prime[i]==0&&L>0)
                {
                    L/=prime[i];
                    count++;
                }

                int count1=function_for_prime(a, prime[i]);
                int count2=function_for_prime(b, prime[i]);
                if(count>max(count1,count2))
                {
                    for(int x=1; x<=count; x++)
                        res*=prime[i];
                }
            }
            if(L>1)
            {
                int count1=function_for_prime(a, L);
                int count2=function_for_prime(b, L);
                if(max(count1,count2)==0)
                    res*=L;
            }
            pf("Case %d: %lld\n",cs,res);
        }
    }
    return 0;
}
