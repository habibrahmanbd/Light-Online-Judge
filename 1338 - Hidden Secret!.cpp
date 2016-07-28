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
    sf("\n");
    for(ll cs=1; cs<=t; cs++)
    {
        char str1[105],str2[105];
        gets(str1);
        gets(str2);
        ll a[26]={0},b[26]={0};
        for(ll i=0; i<strlen(str1); i++)
        {
            if(str1[i]==' ')
                continue;
            else
            {
                a[tolower(str1[i])-'a']++;
            }
        }
        for(ll i=0; i<strlen(str2); i++)
        {
            if(str2[i]==' ')
                continue;
            else
            {
                b[tolower(str2[i])-'a']++;
            }
        }
        bool flag=0;
        for(ll i=0; i<26; i++)
        {
            if(b[i]<=a[i])
                continue;
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            pf("Case %lld: No\n",cs);
        }
        else
            pf("Case %lld: Yes\n",cs);
    }
    return 0;
}
