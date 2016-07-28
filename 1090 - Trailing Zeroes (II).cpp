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

ll function_for_prime(ll n, ll p)
{
    ll count=0;
    while(n%p==0&&n>0)
    {
        count++;
        n/=p;
    }
    return count;
}

ll num_2[1000001];
ll num_5[1000001];

void call()
{
    num_2[0]=num_5[0]=num_2[1]=num_5[1]=0;
    for(ll i=2; i<=1000000; i++)
    {
        num_2[i]=num_2[i-1]+function_for_prime(i,2);
        num_5[i]=num_5[i-1]+function_for_prime(i,5);
    }
}

int main()
{
    call();
    int t=II;
    for(int  cs=1; cs<=t; cs++)
    {
        ll n=ILL, r=ILL, p=ILL, q=ILL;
//
//        cout<<num_2[n]<<" "<<num_5[n]<<endl;
//        cout<<num_2[r]<<" "<<num_5[r]<<endl;
//        cout<<num_2[n-r]<<" "<<num_5[n-r]<<endl;

        ll n_2= num_2[n]-num_2[r]-num_2[n-r]+(function_for_prime(p,2)*q);
        ll n_5= num_5[n]-num_5[r]-num_5[n-r]+(function_for_prime(p,5)*q);
        pf("Case %d: %lld\n",cs,min(n_2,n_5));
    }
    return 0;
}

///memory less solution of Zubayer Hasan Bhai
/*
#include <cstdio>

int calcf5(int n)
{
    int ret = 0;
    while(n > 0)
    {
        n /= 5;
        ret += n;
    }
    return ret;
}

int calcf2(int n)
{
    int ret = 0;
    while(n > 0)
    {
        n >>= 1;
        ret += n;
    }
    return ret;
}

int calcn2(int n)
{
    int ret = 0;
    while((n&1) == 0)
    {
        ret++;
        n >>= 1;
    }
    return ret;
}

int calcn5(int n)
{
    int ret = 0;
    while(n % 5 == 0)
    {
        ret++;
        n /= 5;
    }
    return ret;
}

int main()
{
    int test, cs, n, r, p, q, t5, t2;
    scanf("%d", &test);
    for(cs = 1; cs <= test; cs++)
    {
        scanf("%d %d %d %d", &n, &r, &p, &q);
        t5 = calcf5(n) - calcf5(r) - calcf5(n - r) + q * calcn5(p);
        t2 = calcf2(n) - calcf2(r) - calcf2(n - r) + q * calcn2(p);
        printf("Case %d: %d\n", cs, t5 < t2 ? t5 : t2);
    }
    return 0;
}
*/
