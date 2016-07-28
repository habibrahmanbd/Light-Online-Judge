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

#define _F_in       freopen("1041-in.txt","r",stdin)
#define _F_out      freopen("1041-out.txt","w",stdout)

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
map<string, int> mymap;
int n;
int mst_cost;
vector< vector< pi > > AdjList;
vector<bool> taken;                                  // global boolean flag to avoid cycle
priority_queue<pi> pq;            // priority queue to help choose shorter edges
int done_node=0;
void process(int vtx)      // so, we use -ve sign to reverse the sort order
{
    ++done_node;
    taken[vtx] = 1;
    for (int j = 0; j < (int)AdjList[vtx].size(); j++)
    {
        pi v = AdjList[vtx][j];
        if (!taken[v.xx])
            pq.push(mp(-v.yy, -v.xx));
    }
}
int main()
{
    _F_in;
    _F_out;
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        int m=II;
        n=1;
        AdjList.clear();
        AdjList.resize((2*m)+2);
        mymap.clear();
        taken.clear();
        mst_cost=0;
        for(int i=1; i<=m; i++)
        {
            string city1=IS, city2=IS;
            int w=II;
            if(!mymap[city1])
                mymap[city1]=n++;
            if(!mymap[city2])
                mymap[city2]=n++;
            int u=mymap[city1], v=mymap[city2];
            u--,v--; //making the zero based vertex
            AdjList[u].pb(mp(v,w));
            AdjList[v].pb(mp(u,w));
        }
        n--;
        taken.assign(n+5, 0);
        done_node=0;
        process(0);
        mst_cost = 0;
        while (!pq.empty())
        {
            pi front = pq.top();
            pq.pop();
            int u = -front.yy, w = -front.xx;
            if (!taken[u])
                mst_cost += w, process(u);
        }
//        cout<<done_node<< " "<<n<<endl;
        if(done_node==n)
            pf("Case %d: %d\n",cs, mst_cost);
        else
            pf("Case %d: Impossible\n",cs);
    }
    return 0;
}
