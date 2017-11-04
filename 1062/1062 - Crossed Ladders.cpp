#include<bits/stdc++.h>
#define invs(c) (1./sqrt(c))
using namespace std;
int main()
{
    //freopen("in.inp","r",stdin);
    int tc;double x,y,c;
    scanf("%d",&tc);
    for(int i=1;i<=tc;i++)
    {
        scanf("%lf%lf%lf",&x,&y,&c);
        double l=0,r=min(x,y),mid;
        while(fabs(r-l)>1e-10)
        {
            mid = (l+r)/2;
            if((invs(x*x - mid*mid) + invs(y*y - mid*mid)) < (1./c))
                l=mid;
            else
                r = mid;
        }
        printf("Case %d: %.10lf\n",i,mid);
 
 
    }
    return 0;
}
