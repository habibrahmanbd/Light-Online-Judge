#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctype.h>
using namespace std;
struct list
{
    string str;
};
int main()
{
    int tcase;
    cin>>tcase;
    getchar();
    for(int j=1;j<=tcase;j++)
    {
        printf("Case %d:\n",j);
        int i=0, pivot=0;
        struct list *data[200];
        data[i] = new list;
        data[i]->str = "http://www.lightoj.com/";
        string check;
        while(1)
        {
            cin>>check;
            if(check=="QUIT")
                break;
            if(check=="VISIT"){
                data[++i] = new list;
                pivot=i;
                cin>>data[i]->str;
                cout<<data[i]->str<<endl;
            }
            if(check=="BACK"){
                if((i-1)>=0){
                    cout<<data[--i]->str<<endl;
                }
                else
                    cout<<"Ignored\n";
            }
            if(check=="FORWARD"){
                if((i+1)<=pivot){
                    cout<<data[++i]->str<<endl;
                }
                else
                    cout<<"Ignored\n";
            }


        }
    }
    return 0;

}
