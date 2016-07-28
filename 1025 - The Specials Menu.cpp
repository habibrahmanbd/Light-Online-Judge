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
ll dp[60][60];
bool visit[60][60];
string w;
ll solve(int i, int j)
{
    if(j<i) // i and j cross themselves.
        return 0;
    if(j==i) //pointing the same character of the string
        return 1;
    if(!visit[i][j])
    {
        if(w[i]==w[j])
            dp[i][j]=(1+solve(i+1,j)+solve(i,j-1));
//            this expression basically is- 1 + solve(i+1,j-1) + ( solve(i+1,j) + solve(i, j-1) - solve(i+1, j-1))
        else
        {
            dp[i][j]=solve(i+1,j)+solve(i,j-1)-solve(i+1,j-1);
//            inclusion and exclusion is done here for the reason of over counting of solve(i+1, j-1)
        }
    }
    visit[i][j]=1;
    return dp[i][j];
}
//            the solution technique is given in http://codeforces.com/blog/entry/15372
int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        cin>>w;
        memset(dp, -1, sizeof dp);
        memset(visit, 0, sizeof visit);
        pf("Case %d: %lld\n", cs, solve(0,w.length()-1));
    }
    return 0;
}
