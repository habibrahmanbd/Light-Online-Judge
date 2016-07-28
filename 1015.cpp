#include<stdio.h>
int main()
{
    int T,N,k,l=0,sum;
    scanf("%d",&T);
    if(T<=100)
    while(T--){
        scanf("%d",&N);
        if(N<=1000){
        sum=0;
        while(N--)
        {
            scanf("%d",&k);
            if(k>0)
            sum+=k;
        }
        printf("Case %d: %d\n",++l,sum);
    }
    }
    return 0;
}
