#include<stdio.h>
int main()
{
    int T,n,m,sign_count=1,num;
    scanf("%d",&T);
    int p_case=1;
        while(T>0 && T<=10000)
    {
        int sum=0;
        scanf("%d%d",&n,&m);
        if(n>=2 && n<=1000000000)
            if(m>=1)
        if(n%m==0)
        {
            int t_n=1;
            while(t_n<=n)
            {
                int p=1;
                while(p<=m)
                {
                num=t_n;
                if(sign_count%2==1)
                {
                    num*=-1;
                    sum+=num;
                }
                else
                {
                    sum+=num;
                }
                t_n++;
                p++;
                }
                sign_count++;

            }

        }
        printf("Case %d: %d\n",p_case++,sum);
        T--;
        }
        return 0;
}
