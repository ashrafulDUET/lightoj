#include<bits/stdc++.h>
#define MAX 102
#define MSET(A,F) memset(A,F,sizeof(A))
#define ADJC(ADJ,N)    for(int i=0;i<N;i++) ADJ[i].clear()

using namespace std;
struct node
{
    int u,w;
    node(int i, int j){u=i;w=j;}
};
vector<int>adj[MAX];
int vis[MAX],cost1[MAX],cost2[MAX],maxi,Nstart;
void bfs(int src, int *cost)
{
    vis[src] = 1;
    queue<int>fifo;
    fifo.push(src);
    cost[src] = 0;
    while(!fifo.empty())
    {
        int f = fifo.front();
        fifo.pop();
        for(int i=0;i<adj[f].size();i++)
        {
            int af = adj[f][i];
            if(!vis[af] )
            {
                cost[af] = cost[f] + 1;
                vis[af] =  1;
                fifo.push(af);
            }
        }
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    for(int t =1;t<=T;t++)
    {
        int n,edge,u,v,w,re=0,re2=0;
        cin>>n>>edge;
        for(int i=0;i<edge;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cin>>u>>v;



        MSET(vis,0);
        MSET(cost1,0);
        MSET(cost2,0);

        bfs(u,cost1);
        MSET(vis,0);

        bfs(v,cost2);

        maxi = 0;
        for(int i=0;i<n;i++)
        {
           maxi = max(maxi,cost1[i] + cost2[i]);
        }







        ADJC(adj,n);
        cout<<"Case "<<t<<": "<<maxi<<endl;
    }
    return 0;
}

