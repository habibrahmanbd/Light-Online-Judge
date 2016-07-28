#include <iostream>
#include <stdio.h>
#include <string.h>
#define inf 1000000000
using namespace std;
int h[20],a[20][20];
char s[20][20];
int dp[66000];
int lim,N;
int DP(int mask)
{
    int i,j,ans,a1;
    int d[16];

    if(mask==lim)   return 0;

    if(dp[mask]!=(-1))  return dp[mask];

    for(i=0;i<N;i++)    d[i] = 1;

    // computing the damage;
    for(i=0;i<N;i++){
        if((mask>>i)&1){
                for(j=0;j<N;j++)
                    d[j]=max(d[j],a[i][j]);
        }
    }

    ans =  inf;
    int t1;

    for(i=0;i<N;i++)
    {
        if((mask>>i)&1) continue;

        t1 = (h[i]-1)/d[i] +1;
        a1 = DP(mask|1<<i);
        a1 =a1 + t1;
        ans = min(ans, a1);
    }

    dp[mask]= ans;

    return ans;
}
int main()
{
    int t,tc,i,j,ans;

    scanf("%d",&t);
    tc = 0;

    while(tc<t)
    {
        tc++;
        scanf("%d",&N);

        for(i=0;i<N;i++)
            scanf("%d",&h[i]);


        for(i=0;i<N;i++)
        {
            scanf("%s",&s[i]);
            for(j=0;j<N;j++)
                a[i][j] = s[i][j] - '0';
        }

        lim  = 1<<N;
        lim--;

        memset(dp,-1,sizeof(dp));

        ans= DP(0);
        cout<<dp[0]<<endl;
        printf("Case %d: %d\n",tc,ans);

    }

    return 0;
}
