#include<stdio.h>
#include<math.h>
int main()
{
    int binary(long bin);
    int a[4],test,k=0;
    long b[4];
    scanf("%d",&test);
    while(test--)
    {
    scanf("%d.%d.%d.%d",&a[0],&a[1],&a[2],&a[3]);
    scanf("%ld.%ld.%ld.%ld",&b[0],&b[1],&b[2],&b[3]);
    b[0]=binary(b[0]);
    b[1]=binary(b[1]);
    b[2]=binary(b[2]);
    b[3]=binary(b[3]);
    if(a[0]==b[0]&&a[1]==b[1]&&a[2]==b[2]&&a[3]==b[3])
        printf("Case %d: Yes\n",++k);
    else printf("Case %d: No\n",++k);
    }

    return 0;
}
int binary(long bin)
{
    int rem,sum=0,i=0;
    while(bin!=0)
    {
        rem=bin%10;
        bin/=10;
        sum+=rem*pow(2,i++);
    }
    return sum;
}
