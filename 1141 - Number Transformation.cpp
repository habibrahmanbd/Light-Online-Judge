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
int S,T;
vi pmf[1001];
void primefactor(int n)
{
    int temp=n;
    for(int i=2; i*i<=temp; i++)
    {
        if(n%i==0)
        {
            int count=0;
            while(n%i==0)
            {
                n/=i;
                count++;
            }
            if(count)
                pmf[temp].pb(i);
        }
    }
    if(n>1&&n<temp)
        pmf[temp].pb(n);
    if(n==temp)
        pmf[temp].clear();
//    pf("%d: ",temp);
//    for(int i=0; i<pmf[temp].size(); i++)
//        pf("%d ",pmf[temp][i]);
//    pf("\n");
    return;
}
int bfs()
{
    int dp[1001];
    memset(dp, -1, sizeof dp);
    queue<int>q;
    q.push(S);
    dp[S]=0;
    int from, to;
    while(!q.empty())
    {
        from=q.front();
        q.pop();
        for(int i=0; i<pmf[from].size(); i++)
        {
//            cout<<pmf[from][i]
            to=from+pmf[from][i];
            if(dp[to]==-1&&to<=T)
            {
                dp[to]=dp[from]+1;
                q.push(to);
                if(to==T)
                    return dp[T];
            }
        }
    }
    return dp[T];
}
int main()
{
    for(int i=2; i<=1000; i++)
        primefactor(i);
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        S=II,T=II;
        pf("Case %d: %d\n",cs,bfs());
    }
    return 0;
}
