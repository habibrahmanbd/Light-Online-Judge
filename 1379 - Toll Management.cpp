using namespace std;
#include<bits/stdc++.h>

#define db          double
#define ll          long long
#define ull         unsigned long long

#define vi          vector<int>
#define vl          vector<long>
#define vll         vector<ll>

#define mii         map<int,int>
#define mll         map<ll,ll>

#define pi          pair<int,int>
#define pl          pair<long,long>
#define pll         pair<ll,ll>

#define pb          push_back
#define mp          make_pair
#define xx          first
#define yy          second

#define pf          printf
#define sf          scanf
#define II          ({int a; _in(a); a;})
#define IL          ({long a; _in(a); a;})
#define ILL         ({ll a; _in(a); a;})
#define ID          ({db a; sf("%lf",&a); a;})
#define IF          ({float a; sf("%f",&a); a;})
#define IC          ({char a; sf("%c",&a); a;})

#define FRI(a,b,c)  for(int i=a;   i<=b; i+=c)
#define FRL(a,b,c)  for(long i=a;  i<=b; i+=c)
#define FRLL(a,b,c) for(ll i=a;    i<=b; i+=c)

#define all(V)      V.begin(),V.end()
#define clr(A,B)    memset(A,B,sizeof A)

#define _F_in       freopen("in.txt","r",stdin)
#define _F_out      freopen("out.txt","w",stdout)

#define PI          2*acos(0.0)
#define mod         1000000007
#define INF         10000007;
#define sqr(n)      (n*n)

#define endl	    '\n'

template <typename T>inline T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T>inline T ModInv (T b,T m){return BigMod(b,m-2,m);}
template <typename T>inline T Bigmod(T b,T p,T m){ if(p==0) return 1; else if (!(p&1)) return sqr(Bigmod(b,p/2,m)) % m;else return ((b % m) * Bigmod(b,p-1,m)) % m;}
template <typename T>inline T gcd(T a,T b){ if(b==0)return a; return gcd(b,a%b);}
template <typename T>inline T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template <typename T>inline T euclide(T a,T b,T &x,T &y) {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template <typename T>inline void _in(T &x){register int c = getchar();x = 0;bool neg = 0;for(;((c<48 | c>57) && c != '-');c = getchar()); if(c=='-') {neg=1;c=getchar();}for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}if(neg) x=-x;}

template <typename T>inline T Set(T N,T pos){ return N=N | (1<<pos);}
template <typename T>inline T Reset(T N,T pos){return N= N & ~(1<<pos);}
template <typename T>inline bool Check(T N,T pos){return (bool)(N & (1<<pos));}
template <class T, class X > inline T   togglebit(T a, X i) { T t=1;return (a^(t<<i)); }

inline double DEG(double x) { return (180.0*x)/(PI);}
inline double RAD(double x) { return (x*(double)PI)/(180.0);}


//------------------------------------------------------
//the solution idea i get from Leonard Boshell the Boss of CP
//Link is: http://lbv-pc.blogspot.com/2012/10/highest-paid-toll.html
typedef pair<long, int> pli;
const int dd=2, sz=10005;
vector<pair<long, int> >adjList[dd][sz];
bool vis[dd][sz];
ll dist[dd][sz];
priority_queue<pli, vector<pli>, greater<pli > >q;
void Dijkstra(int source,int tp)
{
    q.push(mp(0,source));
    dist[tp][source]=0;
    while(!q.empty())
    {
        pli u_n=q.top();
        int u=u_n.yy;
        int u_d = u_n.xx;
        q.pop();
        if(!vis[tp][u])
        {
            for(int i=0; i<adjList[tp][u].size(); i++)
            {
                int v=adjList[tp][u][i].yy;
                int cost=adjList[tp][u][i].xx;
                if(dist[tp][v]>dist[tp][u]+cost)
                {
                    dist[tp][v]=dist[tp][u]+cost;
                    q.push(mp(dist[tp][v],v));
                }
            }
            vis[tp][u]=1;
        }
    }
}
int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        int n=II,source,sink;
        long m=IL,p;
        source=II,sink=II,p=ILL;
        for(int i=0; i<sz; i++)
        {
            adjList[0][i].clear();
            adjList[1][i].clear();
            dist[0][i]=dist[1][i]=INF;
            vis[0][i]=vis[1][i]=0;
        }
        for(int i=0; i<m; i++)
        {
            int u=II, v=II;
            ll cost=ILL;
            adjList[0][u].pb(mp(cost,v));
            adjList[1][v].pb(mp(cost,u));
        }
        Dijkstra(source,0);
        Dijkstra(sink,1);
        ll ans=-1;
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<adjList[0][i].size(); j++)
            {
                int u=i;
                int v=adjList[0][i][j].yy;
                ll co=adjList[0][i][j].xx;
                ll total_cost=dist[0][i]+dist[1][v]+co;
                if(total_cost<=p)
                    ans=max(ans,co);
            }
        }
        pf("Case %d: %lld\n",cs, ans);
    }
    return 0;
}
