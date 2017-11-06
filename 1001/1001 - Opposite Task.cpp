#include<iostream>
using namespace std;
int main()
{
    int cas,comNum;
    cin>>cas;
    while(cas--)
    {
        cin>>comNum;
        if(comNum>10)
        {
            cout<<comNum-10<<" "<<10<<endl;
        }
        else
        {
            cout<<comNum<<" "<<0<<endl;
        }
 
    }
    return 0;
}
