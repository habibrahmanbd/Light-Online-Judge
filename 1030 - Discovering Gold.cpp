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
int gold[102];
double dp[102],res;

int main()
{
//    ios_base::sync_with_stdio(false);cin.tie(0);
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        int n=II;
        for(int i=1; i<=n; i++)
            gold[i]=II;
        res=0.0;
        if(n<=2)
        {
            for(int i=1; i<=n; i++)
                res+=(db)gold[i];
        }
        else
        {
            dp[1]=(db)gold[1];
            dp[n]=(db)gold[n];
            for(int i=n-1; i>=1; i--)
            {
                int _in,_out;
                if(n-i<6)
                {
                    _in=n-i;
                    _out=i+6-n;
                }
                else
                    _in=6,_out=0;
                db _in_sum=0.0;
                for(int k=1; k<=_in; k++)
                    _in_sum+=dp[i+k];
                if(_out<6)
                    dp[i]=(6.0/(6.0-(db)_out))*(((db)_in_sum/6.0)+((db)_in/6.0)*(db)gold[i]);
                else
                    dp[i]=(((db)_in_sum/6.0)+((db)_in/6.0)*(db)gold[i]);
            }
            res+=dp[1];
        }
        pf("Case %d: %.10lf\n",cs,res);

    }
    return 0;
}
