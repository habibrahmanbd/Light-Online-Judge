#include<bits/stdc++.h>
using namespace std;
#define mx 1429431
#define vi vector<int>

int Ans[2000005]= {0};

class SegmentTree
{
    vi st;
    int left(int p)
    {
        return p<<1;
    }
    int right(int p)
    {
        return (p<<1)+1;
    }
public:
    SegmentTree()
    {
        st.assign(6*mx+1,0);
        build(1,1,mx);
    }
    void build(int p, int L, int R)
    {
        if(L==R)
        {
            st[p]=1;
            return;
        }
        else
        {
            build(left(p),L,(L+R)>>1);
            build(right(p), ((L+R)>>1)+1,R);
            st[p] = st[left(p)]+st[right(p)];
        }
    }

    void update(int p, int L, int R, int pos)
    {
        int lt = (p<<1);
        int rt = (lt+1);
        int mid = (L+R)>>1;

        if(L==R)
        {
            st[p]=0;
        }
        else
        {
            if(st[left(p)]>=pos)
                update(left(p),L,mid,pos);
            else
                update(right(p),mid+1,R,(pos-st[left(p)]));
            st[p] = st[left(p)]+st[right(p)];
        }
    }

    int query(int p, int L, int R, int n)
    {
        int lt = (p<<1);
        int rt = (lt+1);
        int mid = (L+R)>>1;

        if(L==R)
            return L;
        else
        {
            if(st[lt]>=n)
                return query(left(p),L,mid,n);
            else
                return query(right(p),mid+1,R,n-st[left(p)]);

        }
    }
};


int main()
{
    int t,tc=1,n;
    scanf("%d",&t);

    SegmentTree st;
    int b=0;
    for(int i=2; i<=mx; i+=2)
    {
        st.update(1,1,mx,i-b);
        b++;
    }
    Ans[1]=1;
    for(int i=2; i<=mx; i++)
    {
        b=0;
        Ans[i] = st.query(1,1,mx,i);
        for(int j=Ans[i]; j<mx; j+=Ans[i])
        {
            st.update(1,1,mx,j-b);
            b++;
        }

    }

    while(tc<=t)
    {
        printf("Case %d: ",tc);
        scanf("%d",&n);
        printf("%d\n",Ans[n]);
        tc++;
    }
    return 0;
}
