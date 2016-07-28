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
#define in          freopen("in.txt","r",stdin)
#define out         freopen("out.txt","w",stdout)
#define PI          2*acos(0.0)
#define mod         1000000007
#define INF         1<<29
#define N           1002

//  An useful observation is that a parallelogram is a figure formed by 4 points
//  where the sum of x-coordinates of one pair of points is equal to the sum
//  of x-coordinates of the other two points, and the same happens with the
//  y-coordinates.

int T,n;
struct ed
{
    int x,y;
    bool operator < (const ed &a)const
    {
        if(a.x!=x)return a.x>x;
        return a.y>y;
    }
    bool operator ==(const ed &a)const
    {
        return a.x==x&&a.y==y;
    }
} edg[N*N];
int cnt[N*N];
int cp;
struct nd
{
    int x,y;
} nod[N];
int main()
{
    T=II;
    int tt=0;
    while(T--)
    {
        n=II;
        for(int i=1; i<=n; i++)
            nod[i].x=II,nod[i].y=II;
        cp=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                ed gg;
                gg.x=nod[i].x+nod[j].x;
                gg.y=nod[i].y+nod[j].y;
                edg[cp++]=gg;
            }
        }
        sort(edg,edg+cp);
        int yu=unique(edg,edg+cp)-edg; // Remove all the consecutive same elements
//        cout<<yu<<endl;
        memset(cnt,0,sizeof(cnt));
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                ed gg;
                gg.x=nod[i].x+nod[j].x;
                gg.y=nod[i].y+nod[j].y;
                int id=lower_bound(edg,edg+yu,gg)-edg; // returns the id of gg point
//                cout<<id<<endl;
                ans+=cnt[id];
                cnt[id]++;
            }
        }
//      those two for loop uses to detect the same element appears in the combination... If two same pair are same then it added to cnt 1.
        printf("Case %d: %d\n",++tt,ans);
    }
    return 0;
}
