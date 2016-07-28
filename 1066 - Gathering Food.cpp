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
int d_x[]= {0, 1, 0, -1};
int d_y[]= {1, 0, -1, 0};
//------------------------------------------------------

struct node
{
    int x,y,time;

    node(int x,int y, int time)
    {
        this->x=x,this->y=y,this->time=time;
    }
    node()
    {
    }
};
int n;
bool BOUNDARY(int x, int y)
{
    if(x>=0&&x<n&&y>=0&&y<n)
        return 1;
    return 0;
}
char last='A';
char str[11][11];
bool visited[11][11];
int bfs(node Node, char current)
{
    if(last==current)
        return Node.time;
    memset(visited,0,sizeof visited);
    queue<node>q;
    q.push(Node);
    while(!q.empty())
    {
        Node = q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int x=Node.x+d_x[i];
            int y=Node.y+d_y[i];
//            int time=Node.time;
            if(!BOUNDARY(x,y))
                continue;
            if(str[x][y]==current+1)
                return bfs(node(x,y,Node.time+1),current+1);
            else if(!visited[x][y]&&(str[x][y]=='.'||(isalpha(str[x][y])&&str[x][y]<=current)))
            {
                q.push(node(x,y,Node.time+1));
                visited[x][y]=1;
            }
        }
    }
    return -1;
}
int main()
{
    int t=II;
    for(int cs=1; cs<=t; cs++)
    {
        n=II;
        last='A';
        sf("\n");
        node parent=node();
        for(int i=0; i<n; i++)
            cin>>str[i];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(isalpha(str[i][j]))
                {
                    if(str[i][j]=='A')
                        parent = node(i, j, 0);
                    else
                        last=max(last, str[i][j]);
//                    putchar(last);
                }
            }
        }
        int result = bfs(parent, 'A');
//        cout<<result<<endl;
        if(result>=0)
            pf("Case %d: %d\n",cs, result);
        else
            pf("Case %d: Impossible\n",cs);
    }
    return 0;
}
