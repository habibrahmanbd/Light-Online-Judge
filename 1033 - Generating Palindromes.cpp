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
int dp[102][102];
int len;
string str;
int generate_palindrome(int st, int end)
{
//    pf("st: %d end= %d\n",st,end);
    if(st>=end)
        return 0;
    if(dp[st][end]==-1)
    {
//        int res=INT_MAX;
        int res1=INT_MAX,res2=INT_MAX,res3=INT_MAX;
        if(str[st]==str[end])
            res1=generate_palindrome(st+1,end-1);
        res2=1+generate_palindrome(st+1,end);
        res3=1+generate_palindrome(st,end-1);
        dp[st][end]=min(min(res1,res2),res3);

    }
    return dp[st][end];
}

int main()
{
//    ios_base::sync_with_stdio(false);cin.tie(0);
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        cin>>str;
        len=str.length();
        memset(dp, -1, sizeof dp);
        int res=generate_palindrome(0,len-1);
        pf("Case %d: %d\n",cs,res);
    }
    return 0;
}
