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
template <typename T>inline T triangle_area(T x1, T y1, T x2, T y2, T x3, T y3) { return ((x1*(y2-y3))-(x2*(y1-y3))+(x3*(y1-y2))); }
template <typename T>inline void _in(T &x){register int c = getchar();x = 0;bool neg = 0;for(;((c<48 | c>57) && c != '-');c = getchar()); if(c=='-') {neg=1;c=getchar();}for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}if(neg) x=-x;}
template <typename T>inline void _in_cin_string(T &x){register char c=getchar();for(;c != ' '&&c!='\n';c = getchar()) x+=c;}

template <typename T>inline T Set(T N,T pos){ return N=N | (1<<pos);}
template <typename T>inline T Reset(T N,T pos){return N= N & ~(1<<pos);}
template <typename T>inline bool Check(T N,T pos){return (bool)(N & (1<<pos));}
template <class T, class X > inline T   togglebit(T a, X i) { T t=1;return (a^(t<<i)); }

inline double DEG(double x) { return (180.0*x)/(PI);}
inline double RAD(double x) { return (x*(double)PI)/(180.0);}


//------------------------------------------------------
struct point { ll x,y; };
ll dp[16][16];
ll ans[(1<<16)+1];
int n;
void pre_process()
{
    point _p[n];
    for(ll i=0; i<n; i++)
        _p[i].x=ILL, _p[i].y=ILL;
    clr(dp,0);
    for(ll i=0; i<(1<<n); i++) ans[i]=INF;

    for(ll i=0; i<n; i++)
    {
        for(ll j=i+1; j<n; j++)
        {
            for(ll k=0; k<n; k++)
            {
//                cout<<(triangle_area(_p[i].x,_p[i].y,_p[j].x, _p[j].y,_p[k].x,_p[k].y))<<endl;
                if(triangle_area(_p[i].x,_p[i].y,_p[j].x, _p[j].y,_p[k].x,_p[k].y)==0)
                    dp[i][j]=Set(dp[i][j],k);
            }
        }
    }
}
ll dp_rec(ll s)
{
    if(ans[s]!=INF)
        return ans[s];
    int cnt_bit=0;
    for(ll i=0; i<n; i++)
        if(Check(s, i))
            cnt_bit++;
    if(cnt_bit==0)
        return 0;
    if(cnt_bit<=2)
        return 1;
//    cout<<"here";
    ll i=0;
    while(!Check(s,i)) i++;
    for(ll j=i+1; j<n; j++)
        if(Check(s, j))
            ans[s]=min(ans[s],dp_rec(s-(s&dp[i][j]))+1);
    return ans[s];
}
int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        n=II;
        pre_process();
        pf("Case %d: %lld\n",cs, dp_rec((1<<n)-1));
    }
    return 0;
}
