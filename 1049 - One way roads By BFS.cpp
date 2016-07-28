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
#define sz 102
vector<int>adjList[sz];
int matrix[sz][sz];
int cost[sz];
bool vis[sz];
int bfs(int node)
{
    queue<int>q;
    q.push(node);
    vis[node]=1;
    cost[node]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<adjList[u].size(); i++)
        {
            int v=adjList[u][i];
            if(!vis[v])
            {
                cost[v]=cost[u]+matrix[u][v];
                vis[v]=1;
                q.push(v);
            }
        }
    }
}
int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        int n=II;
        for(int i=0; i<sz; i++)
            adjList[i].clear();
        memset(matrix,0,sizeof matrix);
        for(int i=1; i<=n; i++)
        {
            int u=II, v=II, w=II;
            adjList[u].pb(v);
            adjList[v].pb(u);
            matrix[v][u]=w;
            matrix[u][v]=0;
        }
        memset(cost,0,sizeof cost);
        memset(vis, 0, sizeof vis);
        vis[1]=1;
        bfs(adjList[1][0]);
        int ans1=cost[adjList[1][1]]+matrix[1][adjList[1][0]]+matrix[adjList[1][1]][1];
        memset(cost, 0 ,sizeof cost);
        memset(vis, 0 ,sizeof vis);
        vis[1]=1;
        bfs(adjList[1][1]);
        int ans2=cost[adjList[1][0]]+matrix[1][adjList[1][1]]+matrix[adjList[1][0]][1];
        pf("Case %d: %d\n",cs, min(ans1,ans2));
    }
    return 0;
}
// I have to try It this way
//https://github.com/pin3da/Programming-contest/blob/master/solved/lightoj/1049%20-%20One%20Way%20Roads/solution.cc
