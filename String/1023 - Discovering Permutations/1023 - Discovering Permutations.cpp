#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int n,k;
        cin>>n>>k;
        string str="";
        for(char i='A';i<n+'A';i++)
            str +=i;
        cout<<"Case "<<t<<":"<<endl;
        int cnt=0;
        do
        {
            cout<<str<<endl;
            cnt++;
            if(cnt==k) break;
        }while(next_permutation(str.begin(),str.end()));
    }
    return 0;
}
