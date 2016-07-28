//link: http://lightoj.com/volume_showproblem.php?problem=1028

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<utility>
#include<set>


#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define sf scanf
#define pf printf
#define pb push_back
#define MP make_pair
#define fr first
#define sc second
#define ll long long
#define dd double
#define all(v) v.begin(), v.end()
#define PI acos(-1.0)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define paii pair<int, int>
#define pall pair<ll, ll>
#define SZ(a) int(a.size())
#define read(nm) freopen(nm, "r", stdin)
#define write(nm) freopen(nm, "w", stdout)
#define dump(x) cout<<#x<<" = "<<x<<endl

using namespace std;

#define take(args...) asdf,args
#define debug(args...) asdfg,args; cout<<endl
struct ASDF{
    ASDF& operator,(int &a) {
        sf("%d", &a);
        return *this;
    }
    ASDF& operator,(long int &a){
        sf("%ld", &a);
        return *this;
    }
    ASDF& operator,(long long int &a){
        sf("%lld", &a);
        return *this;
    }
    ASDF& operator,(char &c){
        sf("%c", &c);
        return *this;
    }
    ASDF& operator,(double &d){
        sf("%lf", &d);
        return *this;
    }

    template<typename T>
    ASDF& operator,(T &a){
        cin>>a;
        return *this;
    }
}asdf;
struct ASDFG{
    template<typename T>
    ASDFG& operator,(vector<T> &v){
        pf("[");
        cout<<v[0];
        FOR(i, 1, SZ(v)){
            cout<<", "<<v[i];
        }
        pf("]");
        return *this;
    }

    template<typename T>
    ASDFG& operator,(T x) {
        cout<<x<<" ";
        return *this;
    }


}asdfg;



//Header ends here

#define MAXX 1000002

bool isPrime[MAXX];
vector<int>primes;

void generate()
{
    primes.pb(2);
    mem(isPrime, 1);
    for(int i=3; i<1002; i+=2)
    {
        if(isPrime[i])
        {
            for(int j=i*i; j<MAXX; j+=i+i)
            {
                isPrime[j] = false;
            }
        }
    }
    for(int i=3; i<MAXX; i+=2)
    {
        if(isPrime[i])
        {
            primes.pb(i);
        }
    }
}

int main()
{
    generate();
//    cout<<SZ(primes)<<endl;
    int kases, kaseno = 0;
    ll n;

    take(kases);
    ll cnt;
    ll gun;
    while(kases--)
    {
        take(n);
        cnt = 1;


        for(int i=0; i<SZ(primes) && primes[i]*primes[i]<=n; i++ )
        {
            gun = 1;
            while(n % primes[i] == 0)
            {
                gun++;
                n /= primes[i];
            }
            cnt = cnt*gun;
        }

        if(n != 1)
        {
            cnt *= 2;
        }

        pf("Case %d: %lld\n", ++kaseno, cnt-1);

    }


}
