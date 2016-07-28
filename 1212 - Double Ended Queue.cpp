/*********************************
*   Bismillah hir Rohmanir Rahim *
*   Habibur Rahman Habib         *
*   Dept. of CSE, RUET           *
*   habib_cse_ruet@yahoo.com     *
**********************************/

using namespace std;
//C headers
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
#include <ctime>
//C++ headers
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
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
#define IL ({ int64 a; scanf("%lld",&a);  a;})  //Long Integer Input
#define ID ({ db a; scanf("%lf",&a);  a;}) //Double input
#define IC ({ char a; scanf("%c",&a);  a;}) //Character Input
#define IS ({ string a; cin >> a;  a;}) //String input
#define ICA(n) ({ char a[n]; scanf("%s",&a);  a;}) //Char-Array Input
#define OC(cs) printf("Case %ld:\n",cs);  //Case Input
//Loops.....
#define FOR(p, n, m) for(long int i=p; i<=n; i+=m)  //For Loop increment
#define FOR_R(p, n, m) for(long int j=p; j>=n; j-=m)  //For loop decrement
//Problem wise define.....
int main()
{
    input;
    int64 t=IL;
    int64 oc=1;
    while(oc<=t)
    {
        int64 n=IL, m=IL;
        deque<int> d;
        OC(oc++);
        while(m--)
        {
            string s=IS;
            if(s=="pushLeft")
            {
                int64 p=IL;
                if(d.size()<n){
                    d.push_front(p);
                    pf("Pushed in left: %ld\n",p);
                }
                else
                    pf("The queue is full\n");
            }
            if(s=="pushRight")
            {
                int64 p=IL;
                if(d.size()<n){
                    d.push_back(p);
                    pf("Pushed in right: %ld\n",p);
                }
                else
                    pf("The queue is full\n");
            }
            if(s=="popLeft")
            {
                if(d.size()>0){
                    int64 data = d.front();
                    d.pop_front();
                    pf("Popped from left: %ld\n",data);
                }
                else
                    pf("The queue is empty\n");
            }
            if(s=="popRight")
            {
                if(d.size()>0){
                    int64 data = d.back();
                    d.pop_back();
                    pf("Popped from right: %ld\n",data);
                }
                else
                    pf("The queue is empty\n");
            }
        }
    }
    return 0;
}
