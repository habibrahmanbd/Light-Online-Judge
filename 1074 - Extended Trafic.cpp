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

#define _F_in       freopen("1074 - in.txt","r",stdin)
#define _F_out      freopen("1074 - out.txt","w",stdout)

#define PI          2*acos(0.0)
#define mod         1000000007
#define INF         INT_MAX
#define sqr(n)      (n*n)
#define cube(n)     (n*n*n)

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
#define SIZE 202
//#define INF 2000000000
vi adjList[SIZE],cost[SIZE];
int arr[SIZE];
vector<ll>dist;
//0 based
void BellmanFord(int source,int nodes) //returns true if it has negative cycle
{

    dist.clear();
    int i,j,k,w,v;
    for(i=0; i<=nodes; i++) //distance from source
        dist.push_back(INF);
    dist[source]=0;
    for(i=1; i<=nodes-1; i++)
    {
        for(j=1; j<=nodes; j++)
        {
            for(k=0; k<adjList[j].size(); k++)
            {
                v=adjList[j][k];
                w=cost[j][k];
                if(dist[j]!=INF)
                    dist[v]=min(dist[v],dist[j]+w);
//                cout<<"Dist for: "<<v<<" Dist is: "<<dist[v]<<endl;
            }
        }
    }

//    for(i=1; i<=nodes; i++)
//    {
//        for(j=0; j<adjList[i].size(); j++)
//        {
//            v=adjList[i][j];
//            w=cost[i][j];
//            if(dist[v]>dist[i]+w)
//                return true;
//        }
//    }
//    return false;
}


int main()
{
//    cout<<INF<<endl;
//    _F_in;
//    _F_out;
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
//        cerr<<"Case "<<cs<<":\n";
        int n=II;
        for(int i=1; i<=n; i++)
            arr[i]=II;
        int m=II;
        for(int i=1; i<=m; i++)
        {
            int u=II, v=II;
            adjList[u].pb(v);
            cost[u].pb(cube((arr[v]-arr[u])));
        }
//        cout<<"Cycle :"<<BellmanFord(1,n)<<endl;
        BellmanFord(1,n);
        int q=II;
        pf("Case %d:\n",cs);
        for(int i=1; i<=q; i++)
        {
            int des=II;
//            cout<<"For: "<<des<<" Dist: "<<dist[des]<<endl;
            if(dist[des]<3||(dist[des]==INF))
            {
                pf("?\n");
//                cerr<<'?'<<endl;
            }
            else
            {
                pf("%lld\n",dist[des]);
//                cerr<<dist[des]<<endl;
            }
        }
        if(cs<t)
            for(int i=0; i<SIZE; i++)
            {
                adjList[i].clear();
                cost[i].clear();
            }
//        for(int i=1; i<=n; i++)
//            cout<<dist[i]<<endl;
    }
    return 0;
}
