#include<bits/stdc++.h>
#define MAX 30002
#define MSET(A,F) memset(A,F,sizeof(A))
#define ADJC(ADJ,N)    for(int i=0;i<N;i++) ADJ[i].clear()

using namespace std;
struct node
{
    int u,w;
    node(int i, int j){u=i;w=j;}
};
vector<node>adj[MAX];
int vis[MAX],cost[MAX],maxi,Nstart;
void bfs(int src)
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
            int af = adj[f][i].u;
            if(!vis[af] )
            {
                cost[af] = cost[f] + adj[f][i].w;
                if(cost[af]>maxi)
                {
                    maxi = cost[af];
                    Nstart = af;
                }
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
        int n,u,v,w;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            cin>>u>>v>>w;
            adj[u].push_back(node(v,w));
            adj[v].push_back(node(u,w));
        }
        MSET(vis,0);
        MSET(cost,0);
        maxi = INT_MIN;
        bfs(0);
        //int nStart = max_element(cost,cost+n) - cost;
        MSET(vis,0);
        //MSET(cost,0);
        maxi = INT_MIN;
        bfs(Nstart);
        ADJC(adj,n);
        cout<<"Case "<<t<<": "<<maxi<<endl;
    }
    return 0;
}

