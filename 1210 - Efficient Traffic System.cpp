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
#define IS          ({string a; _in_cin_string(a); a;})

#define FRI(a,b,c)  for(int i=a;   i<=b; i+=c)
#define FRL(a,b,c)  for(long i=a;  i<=b; i+=c)
#define FRLL(a,b,c) for(ll i=a;    i<=b; i+=c)

#define all(V)      V.begin(),V.end()
#define clr(A,B)    memset(A,B,sizeof A)

#define _F_in       freopen("in.txt","r",stdin)
#define _F_out      freopen("out.txt","w",stdout)

#define PI          2*acos(0.0)
#define mod         1000000007
#define INF         LLONG_MAX
#define sqr(n)      (n*n)

#define endl	    '\n'

template <typename T>inline T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T>inline T ModInv (T b,T m){return BigMod(b,m-2,m);}
template <typename T>inline T Bigmod(T b,T p,T m){ if(p==0) return 1; else if (!(p&1)) return sqr(Bigmod(b,p/2,m)) % m;else return ((b % m) * Bigmod(b,p-1,m)) % m;}
template <typename T>inline T gcd(T a,T b){ if(b==0)return a; return gcd(b,a%b);}
template <typename T>inline T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template <typename T>inline T euclide(T a,T b,T &x,T &y) {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template <typename T>inline void _in(T &x){register int c = getchar();x = 0;bool neg = 0;for(;((c<48 | c>57) && c != '-');c = getchar()); if(c=='-') {neg=1;c=getchar();}for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}if(neg) x=-x;}
template <typename T>inline void _in_cin_string(T &x){register char c=getchar();for(;c != ' '&&c!='\n';c = getchar()) x+=c;}

template <typename T>inline T Set(T N,T pos){ return N=N | (1<<pos);}
template <typename T>inline T Reset(T N,T pos){return N= N & ~(1<<pos);}
template <typename T>inline bool Check(T N,T pos){return (bool)(N & (1<<pos));}
template <class T, class X > inline T   togglebit(T a, X i) { T t=1;return (a^(t<<i)); }

inline double DEG(double x) { return (180.0*x)/(PI);}
inline double RAD(double x) { return (x*(double)PI)/(180.0);}


//------------------------------------------------------
//I have learned kosaraju's Algorithm for finding the strongly connected
//component. Then I have tried to solve this problem.
//and finally took help from many other coder to solve trick by KosaRaju's algorithm.
#define sz 20005
ll scc=0;
vi adjList[sz], RadjList[sz];
vector<bool> used;
vi order;
int belongs[sz];
int indegree[sz],outdegree[sz];
void dfs1(int u)
{
    used[u]=1;
    for(int i=0; i<adjList[u].size(); i++)
    {
        int v=adjList[u][i];
        if(!used[v])
            dfs1(v);
    }
    order.pb(u);
}

void dfs2(int u)
{
    used[u]=1;
    belongs[u]=scc;
    for(int i=0; i<RadjList[u].size(); i++)
    {
        int v=RadjList[u][i];
        if(!used[v])
            dfs2(v);
    }
}

void dfs3(int u)
{
    used[u]=1;
    for(int i=0; i<adjList[u].size(); i++)
    {
        int v=adjList[u][i];
        if(belongs[u]!=belongs[v])
        {
            indegree[belongs[v]]++;
            outdegree[belongs[u]]++;
        }
        if(!used[v])
            dfs3(v);
    }
}
ll ans=0;

int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        int n=II;
        ll m=ILL; //number of nodes, edges
        for(ll i=1; i<=m; i++)
        {
            int u=II, v=II;
            adjList[u].pb(v);
            RadjList[v].pb(u);
        }
        used.assign(n+1, false);
        for(int i=1; i<=n; i++)
        {
            if(!used[i])
                dfs1(i);
        }
        used.assign(n+1, false);
        reverse(all(order));
        for(int i=0; i<order.size(); i++)
        {
            int  v=order[i];
            if(!used[v])
            {
                scc++;
                dfs2(v);
//                component.clear();
            }
        }
        used.assign(n+1,false);
        clr(indegree,0);
        clr(outdegree,0);
        for(int i=1; i<=n; i++)
        {
//            int v=order[i];
            if(!used[i])
                dfs3(i);
        }
        int _in=0,_out=0;
        for(int i=1; i<=scc && scc>1; i++)
        {
            if(!indegree[i])
                _in++;
            if(!outdegree[i])
                _out++;
        }
        pf("Case %d: %d\n",cs, max(_in, _out));

        if(cs<t)
        {
            scc=0;
            order.clear();
            for(int i=1; i<=n; i++)
            {
                adjList[i].clear();
                RadjList[i].clear();
            }
        }
    }
    return 0;
}
