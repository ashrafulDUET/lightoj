#include<iostream>
#include<cmath>
#include<algorithm>
#include<stdio.h>
using namespace std;
double  a[2],temp,max1;
int main()
{
    //freopen("in.txt","r",stdin);
    int Case,j=1;
    cin>>Case;
   for(;j<=Case;)
    {
 
                cin>>a[0];
                cin>>a[1];
                cin>>a[2];
 
        sort(a,a+3);
            if((a[2]*a[2])==(a[0]*a[0])+(a[1]*a[1]))
                cout<<"Case "<<j++<<": yes"<<endl;
            else
                cout<<"Case "<<j++<<": no"<<endl;
    }
 
    return 0;
}
