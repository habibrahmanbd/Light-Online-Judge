/*
	Author       :	Jan
	Problem Name :	Efficient Pseudo Code
	Algorithm    :	Math, Modular Inverse
	Complexity   :	O(sqrt(n))
*/

#include<bits/stdc++.h>
using namespace std;

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

#define CLR(a) memset(a,0,sizeof(a))

#define i64 long long

#define PrimeLIMIT 47000

unsigned int prime[PrimeLIMIT / 64], pr[5000], prlen;

#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))

void sieve()
{
    unsigned int i,j,sqrtN,i2;
    memset( prime, -1, sizeof( prime ) );
    sqrtN = (unsigned int)sqrt(( double )PrimeLIMIT) + 1;
    for(i=3; i<sqrtN; i+=2) if(gP(i))
        {
            i2=i<<1;
            for(j=i*i; j<PrimeLIMIT; j+=i2) rP(j);
        }
    pr[prlen++]=2;
    for(i=3; i<PrimeLIMIT; i+=2) if(gP(i)) pr[prlen++]=i;
}

#define MOD 1000000007

int n,m,cases,caseno;

struct Euclid
{
    i64 x,y,d;
};

i64 gcd(i64 a,i64 b)
{
    return !b ? a : gcd(b,a%b);
}

Euclid egcd(i64 a,i64 b)
{
    Euclid temp,temp1;

    if(!b) temp.x=1,temp.y=0,temp.d=a;
    else
    {
        temp1=egcd(b,a%b);
        temp.d=temp1.d,temp.x=temp1.y;
        temp.y=temp1.x-a/b*temp1.y;
    }
    return temp;
}

i64 bigMod(i64 a,i64 p,i64 m)
{
    if(!p) return 1;
    i64 x = bigMod(a,p/2,m);
    x = (x * x) % m;
    if(p&1) x = (a * x) % m;
    return x;
}

i64 modularInverse(i64 a,i64 n)
{
    Euclid t = egcd(a,n);
    if(t.d > 1) return 0;
    i64 r = t.x % n;
    return ( r<0 ? r + n : r );
}

void process()
{
    int sqrtN, i;
    i64 res;

    sqrtN = (int)sqrt((double)n) + 1;
    res = 1;
    for(i=0; pr[i]<=sqrtN; i++) if(!(n % pr[i]))
        {
            i64 cnt = 0;
            while(!(n % pr[i]))
            {
                cnt++;
                n /= pr[i];
            }
            res = ( res * ( bigMod( pr[i], cnt * m + 1, MOD ) + MOD - 1 ) ) % MOD;
            res = ( res * modularInverse( pr[i] - 1, MOD ) ) % MOD;
        }
    if(n > 1)
    {
        res = ( res * ( bigMod( n, m + 1, MOD ) + MOD - 1 ) ) % MOD;
        res = ( res * modularInverse( n - 1, MOD ) ) % MOD;
    }
    printf("Case %d: %d\n",++caseno, (int)res);
}

int main()
{
    sieve();
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d %d",&n,&m);
        process();
    }
    return 0;
}
