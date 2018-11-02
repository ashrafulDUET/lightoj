#include<bits/stdc++.h>
using namespace std;

vector<int>adj[1005];
int cost,check[1005],money[1005],avgMon,comMon,comNum;

void dfs(int src )
{
    comMon += money[src];
    check[src] = true;
    comNum++;
    for(int i=0;i<adj[src].size();i++)
    {
        if(!check[adj[src][i]])
            {
                dfs(adj[src][i]);
            }
    }
    //return cost;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tc,n,m,u,v,c;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        int cnt=0,totalMon=0,re = 0;
        for(int j=0;j<1005;j++) adj[j].clear();
        cout<<"Case "<<i<<": " ;
        cin>>n>>m;
        for(int j=1;j<=n;j++) {

            cin>>money[j];
            totalMon += money[j];
        }
        for(int j=1;j<=m;j++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(check,0,sizeof(check));
        if(totalMon % n != 0) {
            cout<<"No"<<endl;//cout<<totalMon<<" % "<<n <<"No *******"<<endl;
            continue;
        }
        else{
            avgMon = totalMon / n;
        }
        for(int j =1;j<=n;j++)
        {
            comMon = comNum=0;
            if(!check[j])
            {
                dfs(j);
                cnt++;
                if((comMon/comNum) == avgMon)
                    re++;
            }

        }

        if(re == cnt)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

    }
    return 0;
}
