using namespace std;
#include<bits/stdc++.h>
#define db          double
#define ll          long long
#define ull         unsigned long long
#define vi          vector<int>
#define vl          vector<long>
#define vll         vector<ll>
#define pi          pair<int,int>
#define pl          pair<long,long>
#define pll         pair<ll,ll>
#define pb          push_back
#define mp          make_pair
#define pf          printf
#define sf          scanf
#define mii         map<int,int>
#define mll         map<ll,ll>
#define II          ({int a; sf("%d",&a); a;})
#define IL          ({long a; sf("%ld",&a); a;})
#define ILL         ({ll a; sf("%lld",&a); a;})
#define ID          ({db a; sf("%lf",&a); a;})
#define IF          ({float a; sf("%f",&a); a;})
#define IC          ({char a; sf("%c",&a); a;})
#define FRI(a,b,c)  for(int i=a;   i<=b; i+=c)
#define FRL(a,b,c)  for(long i=a;  i<=b; i+=c)
#define FRLL(a,b,c) for(ll i=a;    i<=b; i+=c)
#define all(V)      V.begin(),V.end()
#define in          freopen("in.txt","r",stdin)
#define out         freopen("out.txt","w",stdout)
#define PI          2*acos(0.0)
#define mod         1000000007
#define INF         LLONG_MAX
#define endl        '\n'

template <class T> inline T bigmod(T p,T e,T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}
//------------------------------------------------------
#define SZ 100010
ll lazy[5*SZ],tree[5*SZ];
void update_tree(ll node, ll a, ll b, ll i, ll j, ll val)
{
    if(lazy[node]!=0)
    {
        tree[node]+=lazy[node];
        if(a!=b)
        {
            lazy[(node<<1)+1]+=(lazy[node]/(b-a+1))*(((a+b)/2)-a+1);
            lazy[(node<<1)+2]+=(lazy[node]/(b-a+1))*(b-((a+b)/2));
        }
        lazy[node]=0;
    }
    if(a>b || a>j || b<i)
    {
        return;
    }
    if(a>=i && b<=j)
    {
        tree[node]+=val*(b-a+1);
        if(a!=b)
        {
            ll mid=(a+b)/2;
            lazy[(node<<1)+1]+=val*(mid-a+1);
            lazy[(node<<1)+2]+=val*(b-mid);
        }
        return;
    }
    ll mid=(a+b)/2;
    update_tree((node<<1)+1,a,mid,i,j,val);
    update_tree((node<<1)+2,mid+1,b,i,j,val);
    tree[node]=tree[(node<<1)+1]+tree[(node<<1)+2];
}
ll query(ll node, ll a, ll b, ll i, ll j)
{
    if(a>b || a>j || b<i)
    {
        return 0;
    }
    if(lazy[node]!=0)
    {
        tree[node]+=lazy[node];
        if(a!=b)
        {
            lazy[(node<<1)+1]+=(lazy[node]/(b-a+1))*(((a+b)/2)-a+1);
            lazy[(node<<1)+2]+=(lazy[node]/(b-a+1))*(b-((a+b)/2));
        }
        lazy[node]=0;
    }
    if(a>=i && b<=j)
    {
        return tree[node];
    }
    ll mid=(a+b)/2;
    ll q1=query((node<<1)+1,a,mid,i,j);
    ll q2=query((node<<1)+2,mid+1,b,i,j);
    ll res=q1+q2;
    return res;
}
int main()
{
//	ios::sync_with_stdio(false);
    long long t=ILL;
    for(long long cs=1; cs<=t; cs++)
    {
        printf("Case %lld:\n",cs);
        ll i;
        ll n=ILL,c=ILL;
        for(i=0; i<5*SZ-1; i++)
        {
            lazy[i]=0;
            tree[i]=0;
        }
        int key;
//            cin>>n>>c;
        while(c--)
        {
            key=ILL;
            if(key==0)
            {
                ll x,y,v;
                x=ILL,y=ILL,v=ILL;
                update_tree(0,0,n-1,x,y,v);
            }
            else
            {
                ll x,y;
                x=ILL,y=ILL;
                pf("%lld\n",query(0,0,n-1,x,y));
            }
        }
    }
    return 0;
}
