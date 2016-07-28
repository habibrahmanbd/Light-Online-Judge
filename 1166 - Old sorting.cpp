#include<stdio.h>
int main()
{
    int test,k=0,n;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        int i,arr[n],count=0,j,temp,min=101,min_in;
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        for(i=0;i<n;i++)
        {
            if(arr[i]<min)
            {
                min=arr[i];
                min_in=i;
            }
        }
        for(j=0;j<n-1;j++)
        {
            for(i=j+1;i<n;i++)
            {
                if(arr[i]<arr[min_in])
                {
                    temp=arr[j];
                    arr[j]=arr[i];
                    arr[i]=temp;
                    count++;
                }
            }
        }
        printf("Case %d: %d\n",++k,count);
    }
    return 0;
}
//not solved
