#include<bits/stdc++.h>
using namespace std;
struct node
{
    int f,c;
    node(int i,int j){f = i;c = j;}
};
vector<node>adj[105];
int cost,check[105];

void dfs(int src )
{

    check[src] = true;
    for(int i=0;i<2;i++)
    {
        if(!check[adj[src][i].f]){
            cost += adj[src][i].c;
            //cout<<adj[src][i].f<<" - "<<adj[src][i].c<<" ";
            dfs(adj[src][i].f);

            }
    }
    //return cost;
}
int main()
{
    //for(int i=0;i<12;i++) cout<<check[i]<<" ";
    //freopen("in.txt","r",stdin);
    int tc,n,u,v,c;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        int left[105],right[105],totalCost=0;
        for(int j=0;j<105;j++) adj[j].clear();
        cost =0;
        cout<<"Case "<<i<<": " ;
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>u>>v>>c;
            adj[u].push_back(node(v,c));
            adj[v].push_back(node(u,-c));
            totalCost += c;
        }
        memset(check,0,sizeof(check));
        dfs(1);
        //goSum += -adjList[0][1].second
        cost -= adj[1][1].c;
        //cout<<cost<<endl;
        cost = (totalCost -abs(cost))/2;
        //cout<<cost<<endl;
        cout<<min(cost,(totalCost-cost))<<endl;

    }
    return 0;
}
