#include<stdio.h>
#include<math.h>
#include<ctype.h>
double ary[1000005];
int main()
{
     int j,i, cas,base,no,number;
     for(i = 1;i<=1000002;i++)
               {
                    ary[i] = log10(i)+ary[i-1];
               }
     scanf("%d",&cas);
     for(j=1;(j<=cas)&&cas<=50000;j++)
     {
 
          scanf("%d%d",&number,&base);
          if((number>=0)&&(number<=pow(10,6))&&(base<=1000)&&(base>=2))
          {
 
          no =(int)(ary[number]/log10(base))+1;
          printf("Case %d: %d\n",j,no);
          }
 
     }
          return 0;
}
