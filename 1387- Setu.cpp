#include<stdio.h>
#include<string.h>
int main()
{
    long int total=0,sum,n;
    char str[10];
        scanf("%d",&n);
        if(n>=1&&n<=100)
        {


            while(n>0)
            {
                scanf("%s",str);
                if((strcmp(str,"donate"))==0)
                {
                    scanf("%d",&sum);
                    if(sum>=100&&sum<=100000)
                    total+=sum;
                }
                if((strcmp(str,"report"))==0){
                    printf("%ld\n",total);
                }
                n--;

            }
        }
    return 0;
}
