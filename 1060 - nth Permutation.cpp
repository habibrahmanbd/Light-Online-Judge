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
#define in          freopen("in.txt","r",stdin)
#define out         freopen("out.txt","w",stdout)
#define PI          2*acos(0.0)
#define mod         1000000007
#define INF         1<<29
ll len;
ll fact[21];
ll arr[26]={0};
ll n,all;
void F()
{
    fact[0]=1;
    for(ll i=1; i<21;i++)
        fact[i]=fact[i-1]*i;
    return;
}
ll permutation(ll n)
{
    ll res = fact[n];
    for(ll i=0; i<26;i++)
        res/= fact[arr[i]];
    return res;
}
void solve(ll father, ll pos)
{
    if(pos==len)
        return;
    for(ll i=0; i<26;i++)
    {
        if(arr[i])
        {
            arr[i]--;
            ll res = permutation(len-pos-1);
            if(father+res>=n)
            {
                pf("%c",i+'a');
                solve(father, pos+1);
            }
            else
                father+=res, arr[i]++;
        }
    }
}
int main()
{
    F();
    ll t=ILL;
    ll cs=1;
    while(t--)
    {
        string s;
        cin>>s;
        n=ILL;
        len = s.length();
        memset(arr,0,sizeof arr);
        for(ll i=0; i<len;i++)
            arr[s[i]-'a']++;
        all = permutation(len);
        pf("Case %lld: ",cs++);
        if(n>all)
            pf("Impossible\n");
        else
            solve(0,0),pf("\n");
    }
    return 0;
}
