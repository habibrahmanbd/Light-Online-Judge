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
    for(ll cs=1; cs<=t; cs++)
    {
        ll n=ILL, m=ILL, k=ILL;
        ll arr[n+1][m+1];
        memset(arr,0, sizeof arr);
        for(ll i=1; i<=n; i++)
        {
            for(ll j=1; j<=k; j++)
            {
                ll temp=ILL;
                if(arr[i][abs(temp)]==2) continue;
                if(temp<0)
                    if(arr[i][abs(temp)]==1)
                        arr[i][abs(temp)]=2;
                    else
                        arr[i][abs(temp)]=-1;
                else if(temp>0)
                {
                    if(arr[i][temp]==-1)
                        arr[i][temp]=2;
                    else
                        arr[i][temp]=1;
                }
            }
        }

//        //
//        cout<<"START_DEBUG:\n";
//        for(ll i=1; i<=n; i++)
//        {
//            for(ll j=1; j<=m; j++)
//            {
//                pf("%lld ",arr[i][j]);
//            }
//            pf("\n");
//        }
//        cout<<"END_DEBUG\n";
//        //

        ll p=ILL;
        ll ans[m+1];
        memset(ans,0,sizeof ans);
        for(ll i=1; i<=p; i++)
        {
            ll temp=ILL;
            ans[temp]=1;
        }
//        //
//        cout<<"STR_DB:\n";
//        for(ll i=1; i<=m; i++)
//            pf("%lld ",ans[i]);
//        cout<<"\nEN_DB\n";
//        //

        bool flag=1;
        for(ll i=1; i<=n; i++)
        {
            bool f=0;
//            ll count=0;
            for(ll j=1; j<=m; j++)
            {
                if(arr[i][j]==-1||arr[i][j]==1)
                {
                    if(arr[i][j]==-1&&ans[j]==0)
                    {
                        f=1;
                        break;
                    }
                    else if(arr[i][j]==1&&ans[j]==1)
                    {
                        f=1;
                        break;
                    }
                }
                else if(arr[i][j]==2)

                {
                    f=1;
                    break;
                }
            }
//            if(count==m)
//                f=1;
            if(f==0)
            {
                flag=0;
                break;
            }

        }

        if(flag==1)
            pf("Case %lld: Yes\n",cs);
        else
            pf("Case %lld: No\n",cs);
    }
    return 0;
}
