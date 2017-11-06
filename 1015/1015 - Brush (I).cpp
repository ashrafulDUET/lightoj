#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    int Case1,Case2,temp,j=1;
    long long sum = 0;
    cin>>Case1;
    while(Case1)
    {
        sum =0;
        cin>>Case2;
        for(int i = 0;i<Case2; i++)
        {
            cin>>temp;
            if(temp>0)
                sum +=temp;
        }
        cout<<"Case "<<j++ <<": "<<sum;
            cout<<endl;
        Case1--;
    }
    return 0;
}
