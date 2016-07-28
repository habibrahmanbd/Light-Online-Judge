#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <list>
#include <queue>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <sstream>
#include <bitset>
#include <set>
#define sf scanf
#define pf printf
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    int t,c=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=1;i<=n;i++)
            cin>>arr[i];
        int p;
        cout<<"Case "<<c++<<":"<<endl;
        cin>>p;
        while(p--)
        {
            int x, y, k;
            cin>>x>>y>>k;
            arr[x]=y;
            sort(arr+1, arr+n);
            cout<<arr[k]<<endl;
        }
    }
    return 0;
}
