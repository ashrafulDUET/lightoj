#include<bits/stdc++.h>
#define MAXP 100005
using namespace std;
struct edge{
    int u,v,w;
    edge(){}
    edge(int a, int b, int c)
    {
        u=a;v=b;w=c;
    }
    bool operator <(const edge &p)const{
        return (w<p.w);
    }
};
vector<edge>adj[1000];
vector<edge> e;
int p[MAXP];
map<string,int>mp;
map<int,string>mps;
int findp(int x)
{
    return (p[x] == x)? x : p[x] = findp(p[x]);
}
int MST(int n){  //start Minimum spanning tree
    sort(e.begin(),e.end());
    int cost =0, num =0,u,v;
    //cout<<"Choice \t Edge \t Weight"<<endl<<endl;
    for(int j=1,i =0 ;i<e.size(); i++){
        u = findp(e[i].u);
        v = findp(e[i].v);
        if( u!= v){
             p[u] = v;//Same as : p[findp(u)] = p[v];
            cost += e[i].w;
            num++;
            adj[stoi(mps[u])].push_back(edge(stoi(mps[u]),stoi(mps[v]),e[i].w));
            adj[stoi(mps[v])].push_back(edge(stoi(mps[v]),stoi(mps[u]),e[i].w));
            //cout<<" "<<j++<<"\t [ "<<mps[u]<<","<<mps[v]<<" ] \t"<<e[i].w<<endl;
        }
        if(num == n-1) break;
    }
    return cost;
}   //End MST

bool vVis[16005];
queue<int> qbsf;
int result[16005];
void bfs(int src)
    {
        memset(vVis,0,sizeof(vVis));
        memset(result,0,sizeof(result));
        qbsf.push(src);
        vVis[src]=1;
        while(!qbsf.empty())
        {
            int u = qbsf.front();
            qbsf.pop();
            for(int i=0,len = adj[u].size();i<len;i++)
            {
                if(vVis[adj[u][i].v]==0)
                {
                    qbsf.push(adj[u][i].v);
                    vVis[adj[u][i].v] = 1;

                    if(result[u]>adj[u][i].w)
                        result[adj[u][i].v] =result[u];
                    else
                        result[adj[u][i].v] = adj[u][i].w;
                }
            }
        }
    }
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tc;
    cin>>tc;
    for(int tCase=1;tCase<=tc;tCase++)
    {
        int nE,nN,w,m=1,mycity; edge ed; string u,v;
        cin>>nN>>nE;
        for(int i=1;i<=nN;i++){ //make itself parents
            p[i] = i;
        }
        for(int i =0;i<nE; i++){
            cin>>u>>v>>w;
            if(mp.find(u)==mp.end()){
                    mp[u] =m++;
                    mps[m-1] = u;
            }
            if(mp.find(v)==mp.end()){
                mp[v] =m++;
                mps[m-1] = v;
            }
            ed.u = mp[u];
            ed.v = mp[v];
            ed.w = w;
            e.push_back(ed);
        }
        int re = MST(nN);
        cin>>mycity;
        bfs(mycity);
        cout<<"Case "<<tCase<<":"<<endl;
        for(int i=0;i<nN;i++)
        {
            if(vVis[i])
                cout<<result[i]<<endl;
            else
                cout<<"Impossible"<<endl;

        }
        mp.clear();
        mps.clear();
        e.clear();
//        for(int i=0;i<nN;i++)
//        {
//            cout<<i<<" : ";
//            for(int j=0;j<adj[i].size();j++)
//                cout<<adj[i][j].v<<" ";
//            cout<<endl;
//        }
        for(int i=0;i<nN;i++)
            adj[i].clear();

    }

    return 0;
}
