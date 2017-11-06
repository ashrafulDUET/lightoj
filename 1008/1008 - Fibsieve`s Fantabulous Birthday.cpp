#include<stdio.h>
#include<math.h>
int main()
{
    int Case,l=0;
    long long int Sqrt,second,row,column;
    scanf("%d",&Case);
    while(Case--)
        {
            scanf("%lld",&second);
            Sqrt=ceil(sqrt(second));
 
            if(Sqrt&1)
            {
                if(Sqrt*Sqrt-second<Sqrt)
                {
                    row = Sqrt;
                    column = Sqrt*Sqrt-second +1 ;
                }
                else
                {
                    column = Sqrt;
                    row = second - (Sqrt-1)*(Sqrt-1);
                }
            }
            else
            {
                if(Sqrt*Sqrt-second<Sqrt)
                {
                    column = Sqrt;
                    row = Sqrt*Sqrt-second +1 ;
                }
                else
                {
                    row = Sqrt;
                    column = second - (Sqrt-1)*(Sqrt-1);
                }
            }
            printf("Case %d: %lld %lld\n",++l,column,row);
        }
    return 0;
}
