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
#define mod         330000007
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

string s1, s2;
ll dp[30][30][30];
bool visit[30][30][30];
ll len1,len2;
bool visit_lcs[30][30];
ll dp_lcs[30][30];
ll calLCS(ll i, ll j)
{
    if(s1[i]=='\0'||s2[j]=='\0')
        return 0;
    if(visit_lcs[i][j]==true)
        return dp_lcs[i][j];
    ll ans=0;
    if(s1[i]==s2[j])
        ans = 1 + calLCS(i+1,j+1);
    else
    {
        ll v1 = calLCS(i+1,j);
        ll v2 = calLCS(i,j+1);
        ans =max (v1,v2);
    }
    dp_lcs[i][j]=ans;
    visit_lcs[i][j]=true;
    return dp_lcs[i][j];
}
ll solve(ll s1_len, ll s2_len, ll lcs_len)
{
    if(s1_len == len1 && s2_len != len2)
        return solve(s1_len, s2_len+1, lcs_len);

    if(s2_len == len2 && s1_len!= len1)
        return solve(s1_len+1, s2_len, lcs_len);

    if(s1_len== len1 && s2_len == len2 && lcs_len == 0)
        return 1;

    if(s1_len== len1 && s2_len == len2 && lcs_len != 0)
        return 0;

    if(visit[s1_len][s2_len][lcs_len] == 1)
        return dp[s1_len][s2_len][lcs_len];

    if(s1[s1_len] == s2[s2_len])
        return dp[s1_len][s2_len][lcs_len] = solve(s1_len+1, s2_len+1, lcs_len -1);

    visit[s1_len][s2_len][lcs_len]=1;
    return dp[s1_len][s2_len][lcs_len] = solve(s1_len+1, s2_len, lcs_len) + solve(s1_len, s2_len+1, lcs_len);
}

int main()
{
    int t=II;
    sf("\n");
    for(int cs=1; cs<=t; cs++)
    {
        memset(visit, 0, sizeof visit);
        memset(dp, 0, sizeof dp);
        memset(visit_lcs, 0, sizeof visit_lcs);
        memset(dp_lcs, 0, sizeof dp_lcs);
        char a[31],b[31];
        gets(a);
        gets(b);
        s1 = (string)a;
        s2 = (string)b;
        len1=s1.length();
        len2=s2.length();
        ll temp=calLCS(0,0);
        pf("Case %d: %lld %lld\n",cs,len1+len2-temp,solve(0,0, temp));
    }
    return 0;
}
