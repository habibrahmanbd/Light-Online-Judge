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
#define maxN 50005

int n, scc, idx;
int number[maxN], lowest_node[maxN], belongs[maxN];
int minimum_node_under_scc[maxN], total_nodes_under_this_scc[maxN];
vi adj[maxN], belongsAdj[maxN];
stack<int> st;

void tarjan(int u)
{
    st.push(u);
    number[u] = lowest_node[u] = ++idx;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (belongs[v]>= 0) continue;
        if (number[v])
            lowest_node[u] = min(lowest_node[u], number[v]);
        else
        {
            tarjan(v);
            lowest_node[u] = min(lowest_node[u], lowest_node[v]);
        }
    }
    if (number[u] == lowest_node[u])
    {
        int v;
        minimum_node_under_scc[scc] = n;
        total_nodes_under_this_scc[scc] = 0;
        do
        {
            v = st.top();
            st.pop();
            belongs[v] = scc;
            minimum_node_under_scc[scc] = min(minimum_node_under_scc[scc], v);
            total_nodes_under_this_scc[scc]++;
        }
        while (v != u);
        scc++;
    }
}

int dfs(int u)
{
    int res = total_nodes_under_this_scc[u];
    for(int i=0; i<belongsAdj[u].size(); i++)
        res += dfs(belongsAdj[u][i]);
    return res;
}

int solve()
{
    scc = idx = 0;
    for(int i=1; i<=n; i++)
        if (!number[i]) tarjan(i);

    for(int u=1; u<=n; u++)
    {
        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            if (belongs[u] != belongs[v]) belongsAdj[belongs[u]].pb(belongs[v]);
        }
    }

    int m = 0, ans = 1;
    for(int i=0; i<scc; i++)
    {
        int cnt = dfs(i);
        if (cnt > m || (cnt == m && minimum_node_under_scc[i] < ans))
        {
            m = cnt;
            ans = minimum_node_under_scc[i];
        }
    }
    return ans;
}

int main()
{
    int cases=II, u, v;
    for (int cs=1; cs<=cases; cs++)
    {
        n=II;
        for(int i=0; i<=n; i++)
        {
            adj[i].clear();
            belongsAdj[i].clear();
            number[i] = lowest_node[i] = 0;
            belongs[i]=-1;
        }
        for(int i=1; i<=n; i++)
        {
            u=II,v=II;
            adj[u].pb(v);
        }
        pf("Case %d: %d\n", cs, solve());
    }
    return 0;
}
