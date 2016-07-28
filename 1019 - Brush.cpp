/*******************************
*   Bismillah hir Rohmanir Rahim *
*   Habibur Rahman Habib        *
*   Dept. of CSE, RUET          *
*   habib_cse_ruet@yahoo.com  *
********************************/

using namespace std;
//C headers
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
#include <ctime>
//C++ headers
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
//type def
#define PI 2*acos (0.0)
typedef long long ll;
typedef unsigned long long int64u;
#define db double
#define pb push_back
#define pii pair<int ,int >
#define NL puts("")
#define MAX(p,q) p>q?p:q
#define MIN(p,q) p<q?p:q
#define MOD 100000007
#define INF LLONG_MAX
//Intput_Output
#define input freopen ("input.txt", "r", stdin);
#define output freopen ("output.txt", "w", stdout);
#define pf printf
#define sf scanf
#define co cout
#define ci cin
#define II ({ int a; scanf("%d",&a); a;}) //Integer Input
#define IL ({ ll a; scanf("%lld",&a);  a;})  //Long Integer Input
#define ID ({ db a; scanf("%lf",&a);  a;}) //Double input
#define IC ({ char a; scanf("%c",&a);  a;}) //Character Input
#define IS ({ string a; cin >> a;  a;}) //String input
#define ICA(n) ({ char a[n]; scanf("%s",&a);  a;}) //Char-Array Input
#define OC(cs) printf("Case %d: ",cs);  //Case Input
//Loops.....
#define FOR(p, n, m) for(long int i=p; i<=n; i+=m)  //For Loop increment
#define FOR_R(p, n, m) for(long int j=p; j>=n; j-=m)  //For loop decrement
//Problem wise define.....
#define mx 1<<13
//vector<int>edge[mx];
//stack<int>S;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll testCase;
    cin>>testCase;
    for(ll oc=1; oc<=testCase;oc++)
    {
        ll n,m;
        cin>>n>>m;
        vector< vector<pair<ll,ll> > >g(n);
        for(ll i=0; i<m; i++)
        {
            ll a,b, c;
            cin>>a>>b>>c;
            g[a-1].push_back(make_pair(b-1,c));
            g[b-1].push_back(make_pair(a-1,c));
        }
        ll s=0;
        vector<ll>d(n,INF),p(n);
        d[s]=0;
        bool u[n];
        memset(u,0,sizeof u);
        for(ll i=0; i<n; ++i)
        {
            ll v=-1;
            for(ll j=0; j<n; ++j)
            {
                if(!u[j]&&(v==-1||d[j]<d[v]))
                    v=j;
            }
            if(d[v]==INF)
                break;
            u[v]=true;
            for(size_t j=0; j<g[v].size(); ++j)
            {
                ll to =g[v][j].first, len= g[v][j].second;
                if(d[v]+len<d[to])
                {
                    d[to]=d[v]+len;
                    p[to]=v;
                }
            }
        }
        pf("Case %lld: ",oc);
        if(u[n-1]==true)
            pf("%lld\n",d[n-1]);
        else
            pf("Impossible\n");
    }
    return 0;
}
