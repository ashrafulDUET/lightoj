
#include<bits/stdc++.h>
#define SIZE 20005
using namespace std;
struct node{
    int f,s;

};
vector<int>adj[SIZE];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tc;
    cin>>tc;
    for(int t =1;t<=tc;t++)
    {
        cout<<"Case "<<t<<": ";
        int n,u,v;
        for(int i=0;i<SIZE;i++)
            adj[i].clear();
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
//        for(int i=1;i<4;i++){
//
//                cout<<i<<" : ";
//            for(int j=0;j<adj[i].size();j++)
//                cout<<adj[i][j]<<" ";
//            cout<<endl;
//        }

        int vis[SIZE],maxi=0;
        memset(vis,-1,sizeof(vis));
        for(int i=1;i<SIZE;i++)
        {
            int red=0,black=0;
            if(vis[i]==-1 && !adj[i].empty())
            {
                queue<int>  q;
                q.push(i);
                vis[i] = 1;
                red=1,black=0;

                while(!q.empty())
                {
                    int fst = q.front();
                    q.pop();
                    for(int j=0;j<adj[fst].size();j++)
                    {
                        int u = adj[fst][j];
                        if(vis[u]==-1)
                        {
                            if(vis[fst]==1)
                            {
                                vis[u] = 0;
                                black++;
                            }else
                            {
                                vis[u] = 1;
                                red++;
                                //cout<<red<<endl;
                            }
                            q.push(u);

                        }
                    }
                }

            }
            maxi +=max(red,black);
        }
        cout<<maxi<<endl;

    }
    return 0;
}
