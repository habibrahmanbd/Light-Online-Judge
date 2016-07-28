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
#define clr(A,B)    memset((A),(B),sizeof (A))

#define _F_in       freopen("in.txt","r",stdin)
#define _F_out      freopen("out.txt","w",stdout)

#define PI          2*acos(0.0)
#define mod         1000000007
#define INF         8000
#define sqr(n)      (n*n)

#define endl	    '\n'
#define DEBUG(n)    pf("DEBUG : ");cout<<n<<endl;
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
//My thoughts and the solution trick shared by Leo is same--->
//http://lbv-pc.blogspot.com/2012/06/not-best.html?showComment=1451842825615#c1612568546319878738


#define sz 5005
vector<pl>adjList[sz];
bool vis[2][sz];
long dist[2][sz];
typedef pair<long,pair<long, long> > ppl;
priority_queue<ppl, vector< ppl >, greater< ppl > >q;
void Dijkstra(long source)
{
    for(long i=0; i<sz; i++)
    {
        dist[0][i]=INF;
        dist[1][i]=INF;
    }
    q.push(mp(0, mp(0,source)));
    dist[0][source]=0;
    while(!q.empty())
    {
        long t = q.top().xx;
//        long u_d=q.top().yy.xx;

        long u=q.top().yy.yy;
        long u_d=dist[t][u];
        q.pop();
//        cout<<"U: "<<u<<endl;
        if(!vis[t][u])
        {
            for(long i=0; i<adjList[u].size(); i++)
            {
                long v=adjList[u][i].xx;
                long d_v=adjList[u][i].yy;
                long alt=u_d+d_v;
//                cout<<"V: "<<v<<endl;
//                DEBUG(alt);
                if(alt<dist[0][v])
                {
                    dist[1][v]=dist[0][v];
                    q.push(mp(1, mp(dist[1][v],v)));
                    dist[0][v]=alt;
                    q.push(mp(0,mp(dist[0][v],v)));
                }
                else if(alt > dist[0][v] && alt < dist[1][v])
                {
                    dist[1][v]=alt;
                    q.push (mp(1, mp(dist[1][v], v)));
                }

            }
            vis[t][u]=1;
        }
    }
}


int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        int nodes=IL, edges=IL;
        for(int i=0; i<sz; i++)
            adjList[i].clear();
        clr(vis,0);
        for(long i=0; i<edges; i++)
        {
            long u=IL, v=IL, w=IL;
            adjList[u].pb(mp(v,w));
            adjList[v].pb(mp(u,w));
        }
        Dijkstra(1);
        pf("Case %d: %ld\n",cs, dist[1][nodes]);
//        if(cs<t)
//        {
//            while(!q.empty())
//                q.pop();
//        }
    }
    return 0;
}
