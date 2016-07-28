#include<stdio.h>
int main()
{
    int t,a,b,temp,sum=0,ct=0,l=0,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        if(a>b)
        {
        temp=a;
        a=b;
        b=temp;
        }
        for(i=1;i<=b;i++)
        {
        sum=((sum*10)+i);
        }
        for(i=b;i>=a;i--)
        {
        if(sum%3==0)
        {
        ct++;
        }
        sum/=10;
        }
        printf("Case %d: %d\n",++l,ct);
    }
    return 0;

}
