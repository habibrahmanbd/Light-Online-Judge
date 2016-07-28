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
#define INF         100007
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
#define sz 10005
vector<pi > adjList[sz],tempList[sz];
int n,d;
int dist[sz][11];
typedef pair<int, pi > ppii;
int Dijkstra()
{
    FRI(0,sz-1,1)
    for(int j=0; j<=10; j++)
        dist[i][j]=INF;
    set<ppii >q;
    q.insert(mp(0,mp(0,0)));
    dist[0][0]=0;
    while(!q.empty())
    {
        ppii u_n = *q.begin();
        q.erase(u_n);
        int used_d=u_n.yy.yy;
        int u=u_n.yy.xx;
        int cost_u=u_n.xx;
        if(u==n-1)
            return dist[u][used_d];
//        cout<<"U: "<<u<<" Used_d: "<<used_d<<" Cost: "<<cost_u<<endl;

        for(int i=0; i<adjList[u].size(); i++)
        {
            pi v_d = adjList[u][i];
            int v=v_d.xx;
            int cost_v=v_d.yy;
            if(dist[v][used_d]>dist[u][used_d]+cost_v)
            {
                if(dist[v][used_d]!=INF)
                    q.erase(mp(dist[v][used_d],mp(v,used_d)));
                dist[v][used_d]=dist[u][used_d]+cost_v;
                q.insert(mp(dist[v][used_d],mp(v,used_d)));
            }
        }
        if(used_d==d)
            continue;
        for(ll i=0; i<tempList[u].size(); i++)
        {
            pi v_d = tempList[u][i];
            int v=v_d.xx;
            int cost_v=v_d.yy;
            if(dist[v][used_d+1]>dist[u][used_d]+cost_v)
            {
                if(dist[v][used_d+1]!=INF)
                    q.erase(mp(dist[v][used_d+1],mp(v,used_d+1)));
                dist[v][used_d+1]=dist[u][used_d]+cost_v;
                q.insert(mp(dist[v][used_d+1], mp(v,used_d+1)));
            }
        }
    }
    return -1;
}

int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        for(int i=0; i<sz; i++)
        {
            adjList[i].clear();
            tempList[i].clear();
        }
        n=II;
        int  m=II, k=II;
        d=II;
        for(int i=0; i<m; i++)
        {
            int u=II, v=II, w=II;
            adjList[u].pb(mp(v,w));
        }
        for(int i=0; i<k; i++)
        {
            int u=II, v=II, w=II;
            tempList[u].pb(mp(v,w));
        }
        int ans=Dijkstra();
        if(ans==-1)
            pf("Case %d: Impossible\n",cs);
        else
            pf("Case %d: %d\n",cs,ans);
    }
    return 0;
}
