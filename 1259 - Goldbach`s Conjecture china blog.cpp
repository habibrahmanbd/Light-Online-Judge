#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int prime[700000];
bool is_prime[10000000];
int tot;

void solve()
{
    tot=0;
    is_prime[0]=is_prime[1]=1;
    for(int i=2;i<10000000;i++)
        if(!is_prime[i]){
            prime[tot++]=i;
            for(int j=i*2;j<10000000;j+=i){
                is_prime[j]=1;
            }
        }
}

int main()
{
    solve();
    int t;
    int xp=0;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int res=0;
        for(int i=0;prime[i]<=n/2;i++){
            int j=n-prime[i];
            if(!is_prime[j]) res++;
        }
        printf("Case %d: %d\n",++xp,res);
    }
    return 0;
}
