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
#define endl	    '\n'

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
int m,n;
string str[501];
int ans[501][501];
int found=0;
void bfs(int x,int y)
{
    queue<pi>q;
    q.push(pi(x,y));
    ans[x][y]=1000;
    if(str[x][y]=='C')
        found++;
    while(!q.empty())
    {
        pi u=q.front();
        q.pop();
        x=u.first;
        y=u.second;
//        cout<<x<< " "<<y <<endl;
        if(y<n-1)
        {
            if(ans[x][y+1]<0&&str[x][y+1]!='#')
            {
                if(str[x][y+1]=='C')
                    found++;
                ans[x][y+1]=1000;
                q.push(pi(x,y+1));
            }
        }
        if(y>0)
        {
            if(ans[x][y-1]<0&&str[x][y-1]!='#')
            {
                if(str[x][y-1]=='C')
                    found++;
                ans[x][y-1]=1000;
                q.push(pi(x,y-1));
            }
        }
        if(x<m-1)
        {
            if(ans[x+1][y]<0&&str[x+1][y]!='#')
            {
                if(str[x+1][y]=='C')
                    found++;
                ans[x+1][y]=1000;
                q.push(pi(x+1,y));
            }
        }
        if(x>0)
        {
            if(ans[x-1][y]<0&&str[x-1][y]!='#')
            {
                if(str[x-1][y]=='C')
                    found++;
                ans[x-1][y]=1000;
                q.push(pi(x-1,y));
            }
        }
    }
    return;
}
void func(int xi, int yi)
{
    found=0;
    bfs(xi,yi);
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            if(ans[i][j]==1000)
            {
                ans[i][j]=found;
            }
    return;
}
int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        m=II, n=II;
        int q=II;
        for(int i=0; i<m; i++)
            cin>>str[i];
        memset(ans,-1,sizeof ans);
        pf("Case %d:\n",cs);
        for(int i=0; i<q; i++)
        {
            int xi=II,yi=II;
            if(ans[xi-1][yi-1]!=-1)
            {
                pf("%d\n",ans[xi-1][yi-1]);
                continue;
            }
            func(xi-1,yi-1);
            pf("%d\n",found);
        }
    }
    return 0;
}
