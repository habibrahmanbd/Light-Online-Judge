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
#define sz 30005
vector<vector<pi> >adjList;
bool visited[sz];
long cost[sz];
void dfs(int u)
{
//    visited[u]=1;
    for(int i=0; i<adjList[u].size(); i++)
    {
        int v=adjList[u][i].first;
        int temp_cost=adjList[u][i].second;

        if(!visited[v])
        {
            visited[v]=1;
//            cout<<u<< " "<<v<< " "<<temp_cost<<endl;
            cost[v]=cost[u]+temp_cost;
//            cout<<cost[v]<<endl;
            dfs(v);
        }
    }
    return;
}
int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        int n=II;
        memset(visited, 0, sizeof visited);
        memset(cost, 0, sizeof cost);
        vector<vector<pi> >temp(sz);
        swap(temp,adjList);
        for(int i=0; i<n-1; i++)
        {
            int u=II, v=II, w=II;
            adjList[u].pb(pi(v,w));
            adjList[v].pb(pi(u,w));
        }
        visited[0]=1;
        dfs(0);
        int res=-1;
        int ase=0;
        for(int i=0; i<n; i++)
            if(res<cost[i])
            {
//                pf("hello\n");
                res=cost[i];
                ase = i;
            }
//        pf("Why ase not showed!!");
//        cout<<ase<<endl;
        memset(visited, 0, sizeof visited);
        memset(cost,0, sizeof cost);
        visited[ase]=1;
        dfs(ase);
        res=-1;
        for(int i=0; i<n; i++)
            res = res<cost[i]?cost[i]:res;
        pf("Case %d: %ld\n", cs, res);

    }
    return 0;
}
