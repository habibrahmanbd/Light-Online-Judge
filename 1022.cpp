#include<stdio.h>
#include<math.h>
#define pi (2*acos(0.0))
int main()
{
    int T,l=0;
    double r,sq_area,cr_area;
    scanf("%d",&T);
    if(T<=1000)
    while(T--)
    {
        scanf("%lf",&r);
        if(r>0 && r<=1000)
        {
        sq_area=(4*r*r);
        cr_area=(pi*r*r);
        printf("Case %d: %0.2lf\n",++l,(sq_area-cr_area));
        }
    }
    return 0;
}
