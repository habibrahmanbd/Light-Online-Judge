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
#define sz 1005
vi adjList[sz], RadjList[sz], resAdjList[sz];
int belongs_to[sz],out[sz];
bool used[sz];
bool flag;
set<int>nodes;
vi order;
int scc=0;
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
    belongs_to[u]=scc;
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
    if(out[u]>1)
    {
        flag=0;
        return;
    }
    for(int i=0; i<resAdjList[u].size(); i++)
    {
        int v=resAdjList[u][i];
        dfs3(v);
    }
}

int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
//        pf("Case %d: ",cs);
        int n=II;
        for(int i=0; i<sz; i++)
        {
            adjList[i].clear();
            RadjList[i].clear();
            resAdjList[i].clear();
            used[i]=0;
            belongs_to[i]=-1;
            out[i]=0;
        }
        order.clear();
        nodes.clear();
        nodes.insert(0);
        for(int _n=1; _n<=n; _n++)
        {
            long k=IL;
            for(long i=1; i<=k; i++)
            {
                int u=II, v=II;
                adjList[u].pb(v);
                RadjList[v].pb(u);
                nodes.insert(u);
                nodes.insert(v);
            }
        }
        clr(used,0);
        set<int>:: iterator it = nodes.begin();
        for( ; it!=nodes.end(); it++)
        {
            if(!used[*it])
                dfs1(*it);
        }
        clr(used,0);
        reverse(all(order));
        scc=0;
        for(int i=0; i<order.size(); i++)
        {
            int  v=order[i];
//            cout<<"V : "<<v<<endl;
            if(!used[v])
            {
                scc++;
                dfs2(v);
            }
        }
//        cout<<"Zero : "<<belongs_to[0]<<endl;
        clr(used,0);
        it=nodes.begin();
        for( ; it!=nodes.end(); it++)
        {
            int u=*it;
            for(int i=0; i<adjList[*it].size(); i++)
            {
                int v=adjList[u][i];
                if(belongs_to[u]!=belongs_to[v])
                {
                    resAdjList[belongs_to[u]].pb(belongs_to[v]);
                    out[belongs_to[u]]++;
//                    cout<<out[]
                }
            }
        }
//        for(int i=1; i<=scc; i++)
//        {
//            pf("Out: %d\n", out[i]);
//        }
        clr(used,0);
        flag=1;
        dfs3(belongs_to[0]);
        if(flag)
        {
            for(int i=1; i<=scc; i++)
            {
                if(!used[i])
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag)
            pf("Case %d: YES\n",cs);
        else
            pf("Case %d: NO\n",cs);
    }
    return 0;
}
