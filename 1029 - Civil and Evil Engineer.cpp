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

#define _F_in       freopen("1029-in.txt","r",stdin)
#define _F_out      freopen("1029-out.txt","w",stdout)

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

#define node_sz 104
#define edge_sz 12009
vector<pair<ll, pll> > AdjList[2]; // G(COST,(U, V))
vector<pll >res;
ll n,m,cost;
vector<ll>p(node_sz);
ll dsu_get(ll v)
{
    return (v == p[v])? v:(p[v]=dsu_get(p[v]));
}
void dsu_unite(ll a, ll b)
{
    a = dsu_get(a);
    b = dsu_get(b);
    if (rand()&1)
        swap(a, b);
    if (a!=b)
        p[a]=b;
}

void KruskalsAlgorithm(ll typ)
{
    cost=0;
    sort(all(AdjList[typ]));
    p.resize(n+20);
    for (ll i=0; i<n+18; ++i)
        p[i]=i;
    for(ll i=0; i< AdjList[typ].size(); ++i)
    {
        ll a = AdjList[typ][i].yy.xx, b =AdjList[typ][i].yy.yy, l = AdjList[typ][i].xx;
        if (dsu_get(a)!=dsu_get(b))
        {
//            cout<<cost<<endl;
            cost += l;
            res.pb(AdjList[typ][i].yy);
            dsu_unite(a, b);
        }
    }
}

int main()
{
    _F_in;
    _F_out;
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        n=ILL, m=0;
        n++;
        AdjList[0].clear();
        AdjList[1].clear();
        p.clear();
        while(true)
        {
            ll u=ILL,v=ILL,w=ILL;
            if(u==0&&v==0&&w==0)
                break;
            m++;
            AdjList[0].pb(mp(w,mp(u, v)));
            AdjList[0].pb(mp(w,mp(v, u)));
            AdjList[1].pb(mp(-w,mp(u, v)));
            AdjList[1].pb(mp(-w,mp(v, u)));
        }
        ll result=0;
        KruskalsAlgorithm(0);
        p.clear();
        res.clear();
        result+=cost;
//        cout<<result<<endl;
        cost=0;
        KruskalsAlgorithm(1);
        result+=abs(cost);
        if(cs<t)
            res.clear();
//        cout<<result<<endl;
        if(!(result&1))
            pf("Case %d: %lld\n",cs, result>>1);
        else
            pf("Case %d: %lld/2\n",cs, result);
    }
    return 0;
}
