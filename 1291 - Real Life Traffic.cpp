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

const int MAXN = 10001;
vi g[MAXN];
set<int> g2[MAXN];
bool used[MAXN];
int timer, tin[MAXN], fup[MAXN]; //tin is discovery time and fup is the finishing time for  a node
int scc=0; //strongly connected component
int belongs_to[MAXN];
set<pi> bridge; //the nodes which are bridge
int res[MAXN]; //this is for the result of scc connection
void dfs (int v, int p = -1)
{
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (int i=0; i<g[v].size(); ++i)
    {
        int to = g[v][i];
        if (to == p) continue;
        if (used[to])
            fup[v] = min (fup[v], tin[to]);
        else
        {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] > tin[v])
            {
                g2[v].erase(to);
                g2[to].erase(v);
                bridge.insert(mp(min(v,to),max(v,to)));
            }
        }
    }
}
void find_bridges(int n)
{
    timer = 0;
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs (i);
}
void dfs2(int u) // this dfs for detect the strongly connected component
{
    used[u]=1;
    belongs_to[u]=scc;
    set<int>::iterator it=g2[u].begin();
    for(; it!=g2[u].end(); it++)
    {
        int v=*it;
        if(!used[v])
            dfs2(v);
    }
}
int main()
{
    int t=II;
    for(int cs=1; cs <=t; cs++)
    {
        int n=II,m=II;
        for(int i=1; i<=m; i++)
        {
            int u=II, v=II;
            g[u].pb(v);
            g[v].pb(u);
            g2[u].insert(v);
            g2[v].insert(u);
        }

        timer = 0;
        clr(used,0);
        find_bridges(n);
        clr(belongs_to, 0);
        clr(used,0);
        for(int i=0; i<n; i++)
        {
            if(!used[i])
            {
                scc++;
                dfs2(i);
            }
        }
        clr(res,0);
        int ans=0;
        set<pi>::iterator it;
        for(it=bridge.begin(); it!=bridge.end(); it++)
        {
            res[belongs_to[it->xx]]++;
            res[belongs_to[it->yy]]++;
        }
        for(int i=1; i<=scc; i++)
        {
            if(res[i]==1) //if a scc node is 1 then it means that another edge is needed to form a cycle.
                ans++;
        }

//        cout<<scc<<endl;
        pf("Case %d: %d\n",cs,(ans+1)>>1); // when an edge is added to any graph it connects two nodes. So, main answer is divided by two.
        if(cs<t)
        {
            for(int i=0; i<MAXN; i++)
            {
                g[i].clear();
                g2[i].clear();
            }
            bridge.clear();
            scc=0;
        }
    }
    return 0;
}
