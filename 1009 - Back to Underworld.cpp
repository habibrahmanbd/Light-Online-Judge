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
enum {NOT_VISITED,BLACK,RED};
#define sz 20005
int visited[sz];
list<int>adjList[sz];

int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        int n=II;
        memset(visited, 0, sizeof visited);
        for(int i=0; i<sz; i++)
            adjList[i].clear();
        for(int i=0; i<n; i++)
        {
            int u=II, v=II;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }
        int res=0;
        for(int i=0; i<sz; i++)
        {
            if(!adjList[i].empty()&&visited[i]==NOT_VISITED)
            {
                int black=0,red =0;
                queue<int>Q;
                Q.push(i);
                visited[i]=BLACK;
                black++;
                while(!Q.empty())
                {
                    int u=Q.front();
                    Q.pop();
                    for(list<int>::iterator it = adjList[u].begin(); it!=adjList[u].end(); it++)
                    {
                        int v=*it;
                        if(visited[v]==NOT_VISITED)
                        {
                            Q.push(v);
                            if(visited[u]==BLACK)
                            {
                                red++;
                                visited[v]=RED;
                            }
                            else
                            {
                                black++;
                                visited[v]=BLACK;
                            }
                        }
                    }
                }
//                cout<<res<<endl;
                res+=max(red, black);
            }

        }
        pf("Case %d: %d\n", cs, res);
    }
    return 0;
}
