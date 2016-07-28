/*******************************
*   Bismillah hir Rohmanir Rahim *
*   Habibur Rahman Habib        *
*   Dept. of CSE, RUET          *
*   habib_cse_ruet@yahoo.com  *
********************************/

using namespace std;

#include <bits/stdc++.h>
//type def
#define PI 2*acos (0.0)
typedef long long int64;
typedef unsigned long long int64u;
#define db double
#define pb push_back
#define pii pair<int ,int >
#define NL puts("")
#define MAX(p,q) p>q?p:q
#define MIN(p,q) p<q?p:q
#define MOD 100000007
#define INF 1<<29
//Intput_Output
#define input freopen ("input.txt", "r", stdin);
#define output freopen ("output.txt", "w", stdout);
#define pf printf
#define sf scanf
#define co cout
#define ci cin
#define II ({ int a; scanf("%d",&a); a;}) //Integer Input
#define IL ({ int64 a; scanf("%I64d",&a);  a;})  //Long Integer Input
#define ID ({ db a; scanf("%lf",&a);  a;}) //Double input
#define IC ({ char a; scanf("%c",&a);  a;}) //Character Input
#define IS ({ string a; cin >> a;  a;}) //String input
#define ICA(n) ({ char a[n]; scanf("%s",&a);  a;}) //Char-Array Input
#define OC(cs) printf("Case %ld:\n",cs);  //Case Input
//Loops.....
#define f(p, n, m) for(long int i=p; i<=n; i+=m)  //For Loop increment
#define fr(p, n, m) for(long int j=p; j>=n; j-=m)  //For loop decrement
//Problem wise define.....
//long tree[100002];
void update(long tree[], long idx, long n, long value)
{
    while(idx<=n)
    {
        tree[idx]+=value;
        idx+=idx & (-idx);
    }
}
long query(long tree[], long idx)
{
    long sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=idx&(-idx);
    }
    return sum;
}
int main()
{
    input;
//    double cl=clock();
    long t=IL,cs=0;
    while(t--)
    {
        long n=IL,q=IL;
        long tree[n+2];
        f(0,n+1,1) tree[i]=0;
        f(1,n,1){
        long a=IL;
        update(tree,i,n,a);
        }
        OC(++cs);
        f(1,q,1)
        {
            int p=II;
            if(p==1)
            {
                long idx=II;
                long result= query(tree,idx+1)-query(tree,idx);
                pf("%ld\n",result);
                update(tree, idx+1, n, -result);
            }
            else if(p==2)
            {
                long idx=IL, value=IL;
                update(tree,idx+1,n,value);
            }
            else if(p==3)
            {
                long idxi=IL, idxj=IL;
                pf("%ld\n",query(tree,idxj+1)-query(tree, idxi));
            }
        }

    }
//    cl=clock()-cl;
//    pf("Total Execution time: %lf\n",cl/CLOCKS_PER_SEC);
    return 0;
}
