using namespace std;
#include<bits/stdc++.h>

#define ll          int

#define pf          printf
#define sf          scanf

#define _F_in       freopen("1114 - Easily Readable.txt","r",stdin)
#define _F_out      freopen("1114 - Easily Readable_out.txt","w",stdout)


//------------------------------------------------------

ll getId(char   c)
{
    if(c>='A'&&c<='Z')
        return c-'A';
    return c-'a'+26;
}

struct Node
{
    //bool EndMark;
    ll ended;
    Node *Next[52];
    Node()
    {
        for(ll i=0; i<52; i++)
        {
            Next[i]=NULL;
            //EndMark=0;
            ended=0;
        }
    }
}*Root;

ll Search(char *Str, ll Len)
{
    Node *Curr = Root;
    for(ll i=0; i<Len; i++)
    {
        ll Id = getId(Str[i]);
        if(Curr->Next[Id]==NULL)
            return 0;
        Curr = Curr->Next[Id];
    }
    return Curr->ended;
}

void Insert(char *str, ll Len)
{
    Node *Curr = Root;
    for(ll i=0; i<Len; i++)
    {

        ll Id = getId(str[i]);
        if(Curr->Next[Id]==NULL)
            Curr->Next[Id]=new Node();
        Curr = Curr->Next[Id];
    }
    Curr->ended++;
    return;
}

void Delete(Node *Curr)
{
    for(ll i=0; i<52; i++)
    {
        if(Curr->Next[i])
            Delete(Curr->Next[i]);
    }
    delete(Curr);
}



int main()
{
    _F_in;
    _F_out;
    ll t,ret,ans,n,len;
    sf("%d",&t);
    char str[100001];
    char nwstr[100001];
    for(ll cs=1; cs<=t ; cs++)
    {
        pf("Case %d:\n",cs);
        sf("%d",&n);
        Root = new Node();

        for(ll i=1; i<=n; i++)
        {
            sf("%s",str);
            len=strlen(str);
            if(len>2)
                sort(str+1,str+len-1);
            Insert(str,len);
        }
        sf("%d",&n);
        getchar();
        ans=1;

        for(ll i=1; i<=n; i++)
        {
            gets(str);
            char *s = strtok(str," ");
            while(s)
            {
                strcpy(nwstr,s);
                ll len = strlen(nwstr);
                if(len>2)
                    sort(nwstr+1,nwstr+len-1);
                ret = Search(nwstr,len);
                ans*=ret;
                s = strtok(NULL," ");
            }
            pf("%d\n",ans);
            ans=1;
        }
        Delete(Root);
    }
    return 0;
}
