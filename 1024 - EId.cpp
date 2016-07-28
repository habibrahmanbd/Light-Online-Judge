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
string tostring(ll a)
{
    string ret;
    while(a)
    {
        ret+=(a%10)+'0';
        a/=10;
    }
    return ret;
}
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
    return bigmod,(a,M-2,M);
}

bool flag[10000];
int primes[1230], len;
int fcnt[10000];
char buff[4096];
int reslen, mxf;

void sieve()
{
    int i, j, k;
    primes[0] = 2;
    len = 1;
    for(i = 3; i < 10000; i+=2)
    {
        if(!flag[i])
        {
            primes[len++] = i;
            if(i >= 100) continue;
            for(j=i*i, k=i<<1; j < 10000; j += k)
                flag[j] = true;
        }
    }
}

void factor(int a)
{
    int i, cnt, rt = (int)sqrt(a);
    for(i = 0; i < len && primes[i] <= rt; i++)
    {
        if(a % primes[i] == 0)
        {
            a /= primes[i], cnt = 1;
            while(a % primes[i] == 0)
            {
                a /= primes[i];
                cnt++;
            }
            rt = (int)sqrt(a);
            if(fcnt[primes[i]] < cnt)
                fcnt[primes[i]] = cnt;
//            if(primes[i] > mxf)
//                mxf = primes[i];
        }
    }
    if(a > 1)
    {
        if(fcnt[a] < 1)
            fcnt[a] = 1;
//        if(a > mxf)
//            mxf = a;
    }
}

void mul(int a)
{
    int i, k, carry, x;
    for(i = carry = k = 0; i < reslen || carry; i++, k++)
    {
        x = ((i < reslen)? buff[i]-48 : 0) * a + carry;
        buff[k] = x % 10 + 48;
        carry = x / 10;
    }
    buff[k] = 0, reslen = k;
}

int main()
{
    int i, j, test, cs, n, a, f;
    sieve();
    scanf("%d", &test);
    for(cs = 1; cs <= test; cs++)
    {
        scanf("%d", &n);
        memset(fcnt, 0, sizeof fcnt);
        buff[0] = '1';
        buff[1] = 0;
        reslen = 1;
        //mxf = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &a);
            factor(a);
        }
        //&& primes[i] <= mxf;
        for(i = 0; i < len; i++)
        {
            for(f = 1, j = 0; j < fcnt[primes[i]]; j++)
                f *= primes[i];
            if(f > 1) mul(f);
        }
        reverse(buff, buff+reslen);
        printf("Case %d: %s\n", cs, buff);
    }
    return 0;
}
