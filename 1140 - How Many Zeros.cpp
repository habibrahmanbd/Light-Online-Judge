using namespace std;
#include<bits/stdc++.h>
#define db          double
#define LL          long long
#define uLL         unsigned long long
#define vi          vector<int>
#define vl          vector<long>
#define vLL         vector<LL>
#define pi          pair<int,int>
#define pl          pair<long,long>
#define pLL         pair<LL,LL>
#define pb          push_back
#define pf          printf
#define sf          scanf
#define mii         map<int,int>
#define mLL         map<LL,LL>
#define II          ({int a; sf("%d",&a); a;})
#define IL          ({long a; sf("%ld",&a); a;})
#define ILL         ({LL a; sf("%lld",&a); a;})
#define ID          ({db a; sf("%lf",&a); a;})
#define IF          ({float a; sf("%f",&a); a;})
#define IC          ({char a; sf("%c",&a); a;})
#define FRI(a,b,c)  for(int i=a;   i<=b; i+=c)
#define FRL(a,b,c)  for(long i=a;  i<=b; i+=c)
#define FRLL(a,b,c) for(LL i=a;    i<=b; i+=c)
#define in          freopen("in.txt","r",stdin)
#define out         freopen("out.txt","w",stdout)
#define PI          2*acos(0.0)
#define mod         1000000007
#define INF         1<<29
LL digit[21];
LL dp[21][2][21];
LL dep_rec(LL len,bool flag,LL p,LL p2,bool fp)
{
    //fp  is using for insuring the equal to main number. If it came using the maximum digit before or not
    //flag will be true if previous element is zero is used for flagging the leading zeros
    //p1 is the number of zeros leading Zeros
    //p2 is the number of zeros both leading and non-leading
    if (len==0)
    {
        if (flag==false)
            return p2-p;
        else
            return 0;
    }
    if (fp==false && dp[len][flag][p2-p]!=-1)
        return dp[len][flag][p2-p];
    LL ret=0;
    LL fpmax = fp==true ? digit[len] : 9 ; // fp is true initially
    for (LL i=0 ; i<=fpmax ; i++)
    {
        bool ok = i==0 ? true : false;
        LL temp;
        if (i==0)
            temp=1 ;
        else
            temp=0 ;
        //fp  is using for insuring the equal to main number
        //flag will be true if previous element is zero
        //p1 is the number of zeros leading Zeros
        //p2 is the number of zeros both leading and non-leading
        ret += dep_rec(len-1, flag&&ok, flag==true ? p+temp : p , p2+temp, fp&&i==fpmax);
    }
    if (fp==false)
        return dp[len][flag][p2-p]=ret;
    return ret;
}
LL f(LL n)
{
    if (n==-1)
        return -1;
    if (n==0)
        return 0;
    LL len=0;
    while (n>0)
    {
        digit[++len]=n%10;
        n /= 10;
    }
    return dep_rec(len,true,0,0,true);
}
int main()
{
    int t;
    int ncase=1;
    cin>>t;
    while (t--)
    {
        LL a,b;
        a=ILL,b=ILL;
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %lld\n",ncase++,f(b)-f(a-1));
    }
    return 0;
}
