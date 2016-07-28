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
#define INF         LLONG_MAX
#define sqr(n)      (n*n)

#define endl	    '\n'

template <typename T>inline T BigMod (T b,T p,T m)
{
    if (p == 0) return 1;
    if (p%2 == 0)
    {
        T s = BigMod(b,p/2,m);
        return ((s%m)*(s%m))%m;
    }
    return ((b%m)*(BigMod(b,p-1,m)%m))%m;
}
template <typename T>inline T ModInv (T b,T m)
{
    return BigMod(b,m-2,m);
}
template <typename T>inline T Bigmod(T b,T p,T m)
{
    if(p==0) return 1;
    else if (!(p&1)) return sqr(Bigmod(b,p/2,m)) % m;
    else return ((b % m) * Bigmod(b,p-1,m)) % m;
}
template <typename T>inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <typename T>inline T lcm(T a,T b)
{
    if(a<0)return lcm(-a,b);
    if(b<0)return lcm(a,-b);
    return a*(b/gcd(a,b));
}
template <typename T>inline T euclide(T a,T b,T &x,T &y)
{
    if(a<0)
    {
        T d=euclide(-a,b,x,y);
        x=-x;
        return d;
    }
    if(b<0)
    {
        T d=euclide(a,-b,x,y);
        y=-y;
        return d;
    }
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        T d=euclide(b,a%b,x,y);
        T t=x;
        x=y;
        y=t-(a/b)*y;
        return d;
    }
}
template <typename T>inline void _in(T &x)
{
    register int c = getchar();
    x = 0;
    bool neg = 0;
    for(; ((c<48 | c>57) && c != '-'); c = getchar());
    if(c=='-')
    {
        neg=1;
        c=getchar();
    }
    for(; c>47 && c<58; c = getchar())
    {
        x = (x<<1) + (x<<3) + c - 48;
    }
    if(neg) x=-x;
}

template <typename T>inline T Set(T N,T pos)
{
    return N=N | (1<<pos);
}
template <typename T>inline T Reset(T N,T pos)
{
    return N= N & ~(1<<pos);
}
template <typename T>inline bool Check(T N,T pos)
{
    return (bool)(N & (1<<pos));
}
template <class T, class X > inline T   togglebit(T a, X i)
{
    T t=1;
    return (a^(t<<i));
}

inline double DEG(double x)
{
    return (180.0*x)/(PI);
}
inline double RAD(double x)
{
    return (x*(double)PI)/(180.0);
}


//------------------------------------------------------

//this is a BFS problem. The first portion is really analytical that
//we need at most n-1 edges to connect all the nodes. so, n-1 is the ans. On
//the second portion, first we should think that every node has some node connected below
//and some node connected above. so, for every node it is , n-(friends in top + friends in bottom +1(himself)) pair possible.
//That is ans?? No, we have some over count. Because 2->3 not paired and 3->2 not paired  is same.
//so, for every node we have counted  twice, is n't it? Yes, we did so. So, ans is total pairs for every node divided by 2

bool vis[100005];
int friends_in_top[100005];
int friends_in_bottom[100005];
vi adjList[100005];
int outdegree[100005];
int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        int n=II;
        clr(vis,0);
        clr(friends_in_top,0);
        clr(friends_in_bottom,0);
        clr(outdegree,0);
        for(int i=1; i<n; i++)
        {
            int u=II, v=II;
            adjList[u].pb(v);
            adjList[v].pb(u);
            outdegree[u]++;
        }
        queue<int>q;
        q.push(1);
        vis[1]=1;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int i=0; i<adjList[u].size(); i++)
            {
                int v=adjList[u][i];
                if(!vis[v])
                {
                    friends_in_top[v]=friends_in_top[u]+1;
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
        clr(vis,0);
        FRI(1,n,1)
        if(outdegree[i]==0)
            q.push(i);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            vis[u]=1;
            for(int i=0; i<adjList[u].size(); i++)
            {
                int v=adjList[u][i];
                if(!vis[v])
                {
                    friends_in_bottom[v]+=friends_in_bottom[u]+1;
                    outdegree[v]--;
                    if(outdegree[v]==0)
                        q.push(v);
                }
            }
        }
        ll _pair=0;
        for(int i=1; i<=n; i++)
            _pair+=n-(friends_in_top[i]+friends_in_bottom[i]+1);
        pf("Case %d: %d %lld\n",cs, n-1, _pair/2);
        if(cs<t)
            for(int i=0; i<100005; i++)
                adjList[i].clear();
    }
    return 0;
}
