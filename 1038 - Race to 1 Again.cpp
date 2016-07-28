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
set<ll>S;
db dp[100010];
int main()
{
    dp[0]=0;
    dp[1]=0;
    for(ll i=1; i<=100009; i++)
    {
        S.clear();
        for(ll j=1; j<=((int)sqrt(i)+1); j++)
        {
            if(i%j==0)
            {
                S.insert(j);
                S.insert((i/j));
            }
        }
        if(i>1)
        {
            ll n = S.size();
            db sum= 0.0;
            std::set<ll>::iterator it = S.begin();
            for(ll j=0; j<n-1; j++)
            {
                sum+=dp[*it];
                it++;
            }
            sum+=(db)n;
            dp[i] = (sum/(db)(n-1));
        }
    }
    int t=II;
    int i=1;
    while(t--)
    {
        ll temp=ILL;
        pf("Case %d: %lf\n",i++,dp[temp]);
    }
    return 0;
}
