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
//------------------------------------------------------


int main()
{
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        ll n=ILL;
        ll zeros=-1,ones=-1;
        ll i=0;
        if((n&1<<i)==0)
        {
            i++;
            while((n&1<<i)==0)
                i++;
            zeros=i-1;
            while(n&1<<i)
                i++;
            ones=i-1;
//            cout<<"BUG 1\n";
        }
        else
        {
//            cout<<"BUG 2\n";
            while(n&1<<i)
                i++;
            ones=i-1;
        }
        ll res=n;
        if(zeros==-1)
        {
            n=(n^1<<ones);
            n=(n|1<<(ones+1));
            res=n;
        }
        else
        {
            ll num_0 = zeros+1;
            ll num_1 = ones-zeros;
//            cout<<"num -1 :" <<num_1<<endl;
//            cout<<"num -0 :" <<num_0<<endl;
            res=n;
//            if(num_0>=num_1)
            if(1)
            {
                ll ro=0;
                for(ro=0; ro<num_1-1; ro++)
                {
//                    cout<<"here";
                    if(ro<num_1)
                        res=(res|1<<ro);
                }
                for(ro; ro<=ones; ro++)
                {
                    if(n&1<<ro)
                    {
                        res= (res^1<<ro);
                    }
                }
                res = res|(1<<(ones+1));
            }
//            else
//            {
//                ll ro=0;
//                for(ro=0; ro<=zeros; ro++)
//                    res=(res|1<<ro);
////                cout<<"Ro: "<<ro<<endl;
//                for(ro; ro<(num_0<<1); ro++){
//                    res= res^(1<<ro);
//                }
//                res = res^(1<<ones);
//                res = (res|1<<(ones+1));
//            }
        }
        pf("Case %lld: %lld\n",cs,res);
    }
    return 0;
}
