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
map<string,pair<ll ,ll> >month;
void func(ll &d1, string &m1, ll &y1, ll &d2, string &m2, ll &y2)
{
    if(y1<=y2)
    {
        if(y1<y2)
        {
            return;
        }
        else
        {
            if(month[m1].first<=month[m2].first)
            {
                if(month[m1].first<month[m2].first)
                    return;
                else
                {
                    if(d1<=d2)
                    {
                        if(d1<d2)
                            return;
                        else
                            return;
                    }
                    else
                    {
                        swap(d1,d2);
                        swap(m1,m2);
                        swap(y1,y2);
                        return;
                    }
                }
            }
            else
            {
                swap(d1,d2);
                swap(m1,m2);
                swap(y1,y2);
                return;
            }
        }
    }
    else
    {
        swap(d1,d2);
        swap(m1,m2);
        swap(y1,y2);
        return;
    }
    return;
}
int main()
{
    month["January"]    =mp(1,31);
    month["February"]   =mp(2,28);
    month["March"]      =mp(3,31);
    month["April"]      =mp(4,30);
    month["May"]        =mp(5,31);
    month["June"]       =mp(6,30);
    month["July"]       =mp(7,31);
    month["August"]     =mp(8,31);
    month["September"]  =mp(9,30);
    month["October"]    =mp(10,31);
    month["November"]   =mp(11,30);
    month["December"]   =mp(12,31);
    ll t=ILL;
    for(ll cs=1; cs<=t; cs++)
    {
        string m1;
        ll d1,y1;
        cin>>m1;
        sf(" %lld, %lld",&d1,&y1);
        string m2;
        ll d2,y2;
        cin>>m2;
        sf(" %lld, %lld",&d2,&y2);
        func(d1,m1,y1, d2,m2, y2);
        ll st=0,en=0;
        if(month[m1].first<=2)
        {
            if(month[m1].first<2)
                st=y1;
            else
            {
                if(d1<=29)
                    st=y1;
                else
                    st=y1+1;
            }
        }
        else
            st=y1+1;
        if(month[m2].first>=2)
        {
            if(month[m2].first>2)
            {
                en=y2;
//                cout<<"ver\n";
            }
            else
            {
                if(d2>=29)
                {
                    en=y2;
//                    cout<<"Anni\n";
                }
                else
                {
//                        cout<<d2<<"\n";
                    en=y2-1;
//                    cout<<"serry\n";
                }
            }
        }
        else
            en=y2-1;
        ll res1 =(en/4)-(en/100) + (en/400);
        if(st)
            st--;
        ll res2 =(st/4)-(st/100) + (st/400);
//        cout<<st<<" "<<en<<endl;
//        cout<<"Res1: "<<res1<<" Res2: "<<res2<<endl;
//        if(res1>res2)
        pf("Case %lld: %lld\n",cs,res1-res2);
//        else
//            cout<<res2-res1<<endl;
    }
    return 0;
}
