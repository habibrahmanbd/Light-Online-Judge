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
#define INF         mod
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

//complexity VE
#define SIZE 105
//#define INF 2000000000
vector<ll>dist(SIZE);
bool vis[SIZE];
vi res;
//0 based
struct graph
{
    int u, v, w;
    graph( int x, int y, int z)
    {
        u=x, v=y, w=z;
    }
};
vector<graph > gr;

bool BellmanFord(int nodes) //returns true if it has negative cycle
{
    ll i,j,k,w,v,u;
    for(i=0; i<nodes+2; i++)
        dist[i]=INF;
    for(i=1; i<nodes; i++) //number of iteration to do. For bellman ford algorithm it is 1 to n-1
    {
        for(j=0; j<gr.size(); j++) //current and next loop the edges to visit
        {
            u=gr[j].u;
            v=gr[j].v;
            w=gr[j].w;
//            cout<<dist[v]<<endl;
            dist[v]=min(dist[v],dist[u]+w);
//            cout<<dist[v]<<endl;
        }
    }


    for(j=0; j<gr.size(); j++)
    {
        u=gr[j].u;
        v=gr[j].v;
        w=gr[j].w;
        if(dist[v]>dist[u]+w)
        {
            dist[v]=dist[u]+w;
            return 1;
        }
    }
    return 0;
}


int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        clr(vis,0);
        int n=II, m=II, p=II;
        for(int i=1; i<=m; i++)
        {
            int u=II, v=II,income=II, expance=II;
//            adjList[v].pb(u);
            gr.pb(graph(u,v,((expance*p)-income)));
        }
        pf("Case %d: ",cs);
        bool res_cycle=BellmanFord(n);
//        cout<<res.size()<<endl;
        if(res_cycle)
            pf("YES\n");
        else
            pf("NO\n");
        if(cs<t)
        {
            res.clear();
            gr.clear();
        }
    }
    return 0;
}
