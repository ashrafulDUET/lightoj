#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    int tc,n,u,v,c;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        int left[105],right[105],cnt1=0,cnt2=0;
        memset(left,0,sizeof(left));
        memset(right,0,sizeof(right));
        cout<<"Case "<<i<<": " ;
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>u>>v>>c;
            if(!right[u] && !left[v])
            {
                cnt1 +=c;
                right[u] = left[v]= true;
            }
            else
            {
                cnt2 +=c;
                right[v] = left[u]= true;
            }
        }
        cout<<min(cnt1,cnt2)<<endl;
    }
    return 0;
}
