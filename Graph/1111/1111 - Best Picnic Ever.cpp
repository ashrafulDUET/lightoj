#include<bits/stdc++.h>
#define MAX 10003
#define MSET(A,F) memset(A,F,sizeof(A))
#define ADJC(ADJ,N)    for(int i=0;i<N;i++) ADJ[i].clear()

using namespace std;
struct node
{
    int u,w;
    node(int i, int j){u=i;w=j;}
};
vector<int>adj[MAX];
int vis[MAX],reach[MAX],citie[MAX];
void bfs(int src)
{
    vis[src] = 1;
    queue<int>fifo;
    fifo.push(src);
    reach[src] += 1;
    while(!fifo.empty())
    {
        int f = fifo.front();
        fifo.pop();
        for(int i=0;i<adj[f].size();i++)
        {
            int af = adj[f][i];
            if(!vis[af] )
            {
                //cout<<af<<" ";
                reach[af] += 1;
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
        int n,k,edge,u,v,temp,re=0;
        MSET(citie,0);
        MSET(reach,0);
        cin>>k>>n>>edge;

        for(int i=0;i<k;i++)
        {
            cin>>citie[i];
        }
        for(int i=0;i<edge;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            //adj[v].push_back(u);
        }

        for(int i=0;i<1003;i++)
        {
            if(citie[i])
            {
                MSET(vis,0);
                bfs(citie[i]);
            }
        }
//        for(int i=0;i<13;i++)
//        {
//            cout<<reach[i]<<" ";
//        }
        for(int i=0;i<1003;i++)
        {
            if(reach[i]==k)
                re++;
        }
        ADJC(adj,n);
        cout<<"Case "<<t<<": "<<re<<endl;
    }
    return 0;
}

