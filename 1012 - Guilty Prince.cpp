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


int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
//        cout<<"here";
        int w=II, h=II;
        string str[22];
        for(int i=1; i<=h; i++)
            cin>>str[i];
        vector<int>adjList[402];
//        clear(adjList);
        int x=1;
        int root;

        for(int i=1; i<=h; i++)
        {
            for(int j=0; j<w; j++)
            {
//                cout<<i<<" "<<j<<" "<<"DEBUG\n";
                if(str[i][j]=='@')
                    root=x;
                if(str[i][j]=='.'||str[i][j]=='@')
                {
                    if(j==0&&(str[i][j+1]=='.'||str[i][j+1]=='@'))
                    {
                        adjList[x].pb(x+1);
                        adjList[x+1].pb(x);
                    }
                    if(j==w-1&&(str[i][j-1]=='.'||str[i][j-1]=='@'))
                    {
                        adjList[x].pb(x-1);
                        adjList[x-1].pb(x);

                    }
                    if(j>0&&j<w-1)
                    {
                        if(str[i][j-1]=='.'||str[i][j-1]=='@')
                        {
                            adjList[x].pb(x-1);
                            adjList[x-1].pb(x);
                        }
                        if(str[i][j+1]=='.'||str[i][j+1]=='@')
                        {
                            adjList[x].pb(x+1);
                            adjList[x+1].pb(x);
                        }
                    }
                    if(i==1&&(str[i+1][j]=='.'||str[i+1][j]=='@'))
                    {
                        adjList[x].pb(x+w);
                        adjList[x+w].pb(x);
                    }
                    if(i==h&&(str[i-1][j]=='.'||str[i-1][j]=='@'))
                    {
                        adjList[x].pb(x-w);
                        adjList[x-w].pb(x);
                    }
                    if(i>1&&i<h)
                    {
                        if(str[i-1][j]=='.'||str[i-1][j]=='@')
                        {
                            adjList[x].pb(x-w);
                            adjList[x-w].pb(x);
                        }
                        if(str[i+1][j]=='.'||str[i+1][j]=='@')
                        {
                            adjList[x].pb(x+w);
                            adjList[x+w].pb(x);
                        }
                    }
                }
                x++;
            }
        }
//        cout<<"hi\n";

        bool vis[500];
        memset(vis,0,sizeof vis);
        stack<int>S;
        S.push(root);
        //vis[root]=1;
        while(!S.empty())
        {
            int u=S.top();
//            cout<<"U: "<<u<<endl;
            S.pop();
            vis[u]=1;
            for(int i=0; i<adjList[u].size(); i++)
            {
                if(!vis[adjList[u][i]])
                    S.push(adjList[u][i]);
            }
        }
        int count=0;
        for(int i=1; i<=h*w; i++)
            if(vis[i]==1)
                count++;
        pf("Case %d: %d\n",cs,count);
//        cout<<"Why\n";
    }
    return 0;
}
