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
int dp[10][100][1001][2];
int x,y;
char str[100];
int len_str;
int dprec(int n,int sum, int div, bool equ)
{
//    cout<<str<<endl;
    int ret=0;
    if(n==len_str)
    {
        if(sum==0  &&  div==0)
            ret=1;
        return ret;
    }
    if(dp[n][sum][div][equ]!=-1)
        return dp[n][sum][div][equ];
    int ending;
    int pp = str[n]-'0';
    if(equ==true)
        ending = pp;
    else
        ending=9;
    int i;
    for(i=0; i<ending; i++)
        ret+=dprec(n+1,(sum+i)%x,((10*div)+i)%x, 0);
    ret+=dprec(n+1,(sum+i)%x,((10*div)+i)%x, equ);
    dp[n][sum][div][equ]=ret;
    return ret;
}
void con(int temp)
{
    char s[100];
    int i=0;
    while(temp>0)
    {
        s[i++]=((temp%10)+'0');
        temp/=10;
    }
    s[i]='\0';
    int k=0;
    for(int j=i-1; j>=0; j--)
        str[k++]=s[j];
    len_str=k;
    str[k]='\0';
    //cout<<t<<endl;
}
int main()
{
    int t;
    sf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        memset(dp,-1,sizeof dp);
        int a,b;
        sf("%d %d %d",&a,&b,&x);
        con(b);
        int res1 = dprec(0,0,0,1);
        int res2;
        if(a-1!=0)
        {
            memset(dp,-1,sizeof dp);
            con(a-1);
            res2 = dprec(0,0,0,1);
        }
        else
            res2 = 1;
        pf("Case %d: %d\n",i,res1-res2);
    }
    return 0;
}
