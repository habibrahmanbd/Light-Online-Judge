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
        int n=II, w=II, k=II;
        int y[n+3],temp;
        for(int i=0; i<n; i++)
            temp=II,y[i]=II;
        sort(y,y+n);
        y[n++]=INT_MAX;
        int dp[105][105];
        memset(dp, 0, sizeof dp);
        for(int i=0; i<n-1; i++)
        {
            for(int j=0; j<k; j++)
            {
                if(i!=0)
                    dp[i][j]=max(dp[i][j],dp[i-1][j]);
                int high=i;
                while(y[high]<=y[i]+w)
                    high++;
                dp[high][j+1]=max(dp[high][j+1],dp[i][j]+high-i);
            }
        }
        int res=0;
        for(int i=0;i<n; i++)
        {
            for(int j=0; j<=k; j++)
            {
                res=max(res, dp[i][j]);
//                cout<<res<<endl;
            }
        }
        pf("Case %d: %d\n",cs,res);
    }
    return 0;
}
