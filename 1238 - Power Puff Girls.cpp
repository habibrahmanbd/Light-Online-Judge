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
vector<int>adjList[401];
bool vis[401];
int lv[401];
void bfs(int node,int d)
{
    queue<int>q;
    q.push(node);
    vis[node]=1;
    lv[node]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=1;
        if(vis[d])
            return;
        for(int i=0; i<adjList[u].size(); i++)
        {
            int v=adjList[u][i];
            if(!vis[v])
            {
                q.push(v);
                lv[v]=lv[u]+1;
                vis[v]=1;
            }
        }
    }
    return;
}
int func(int s, int d)
{
    memset(vis, 0, sizeof vis);
    memset(lv,0, sizeof lv);
    bfs(s,d);
    return lv[d];
}
int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        for(int i=0; i<401; i++)
            adjList[i].clear();
        int n=II, m=II;
        string str[n];
        for(int i=0; i<n; i++)
            cin>>str[i];
        int a,b,c,h;
        int count=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                count++;
                if(str[i][j]=='a')
                    a=count;
                if(str[i][j]=='b')
                    b=count;
                if(str[i][j]=='c')
                    c=count;
                if(str[i][j]=='h')
                    h=count;
                if(i==0||i==n-1)
                    continue;
                if(j==0||j==m-1)
                    continue;
                else
                {
                    if(str[i][j]!='#' && str[i][j]!='m')
                    {
                        if(!(str[i][j+1]=='#'||str[i][j+1]=='m'))
                            adjList[count].pb(count+1);
                        if(!(str[i][j-1]=='#'||str[i][j-1]=='m'))
                            adjList[count].pb(count-1);
                        if(!(str[i+1][j]=='#'||str[i+1][j]=='m'))
                            adjList[count].pb(count+m);
                        if(!(str[i-1][j]=='#'||str[i-1][j]=='m'))
                            adjList[count].pb(count-m);
                    }
                }
            }
        }
        int ans1=-1,ans2=-1,ans3=-1;
        ans1 = func(a,h);
        ans2 = func(b,h);
        ans3 = func(c,h);
        int res=max(max(ans1,ans2),ans3);
        pf("Case %d: %d\n",cs, res);
    }
    return 0;
}
