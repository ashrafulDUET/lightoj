#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
struct edge{
    int u,v,w;
    bool operator <(const edge &p)const{
        return (w<p.w);
    }
};
vector<edge> e;
int p[MAXN];
 
//--->>>>>>>>----------->>START BFS<<-----------<<<<<<<<<<<<<<---
    bool vVis[MAXN];
    queue<int> qbsf;
    vector<int>gCompo[MAXN];
    void bfs(int src)
        {
 
            qbsf.push(src);
            vVis[src]=1;
            while(!qbsf.empty())
            {
                int u = qbsf.front();
                qbsf.pop();
                //cout<<u<<" ";
                for(int i=0,len = gCompo[u].size();i<len;i++)
                {
                    if(vVis[gCompo[u][i]]==0)
                    {
                        qbsf.push(gCompo[u][i]);
                        vVis[gCompo[u][i]] = 1;
 
                    }
                }
            }
 
        }
    //--->>>>>>>>----------->>END BFS<<-----------<<<<<<<<<<<<<<---
    //---------Start finding component.------
    int findComp(int nN)    //Number of node in graph gCompo.
    {
        int cnt=0;
        for(int i =1;i<=nN;i++)
            {
                if(vVis[i]==0)
                {
                    bfs(i);
                    cnt++;
                }
            }
 
        for(int i=1;i<=nN;i++)
            {
                gCompo[i].clear();
                vVis[i]=0;
            }
        return cnt;
    }
    //---------End finding component.------
int findp(int x){
    if(p[x] == x) return x;
    return p[x] = findp(p[x]);
}
long long MST(int n){  //start Minimum spanning tree
    sort(e.begin(),e.end());
    for(int i=0;i<MAXN;i++) p[i] = i;
    int num =0,u,v;long long  cost =0;
    //cout<<"Choice \t Edge \t Weight"<<endl<<endl;
    for(int j=1,i =0 ;i<e.size(); i++){
        u = findp(e[i].u);
        v = findp(e[i].v);
        if(u != v){
            p[u] = v; //Same as : p[p[u]] = p[v]; make v is the root parents of u.
            cost += e[i].w;
            num++;
            //cout<<" "<<j++<<"\t [ "<<e[i].u<<","<<e[i].v<<" ] \t"<<e[i].w<<endl;
        }
        if(num == n-1) break;
    }
    e.clear();
    return cost;
}   //End MST
int main(){
    //freopen("in.txt","r",stdin);
    int tc,nE,nN,airC,u,v; edge ed;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++)
    {
        scanf("%d%d%d",&nN,&nE,&airC);
        for(int j=1;j<=nE;j++)
        {
            scanf("%d%d%d",&ed.u,&ed.v,&ed.w);
            if(ed.w<airC)
            {
                e.push_back(ed);
                gCompo[ed.u].push_back(ed.v);
                gCompo[ed.v].push_back(ed.u);
            }
        }
        long long com = findComp(nN);
//        cout<<"\nCompotent : "<<com<<endl;
        long long re = MST(nN);
        printf("Case %d: %lld %lld\n",t,(re+airC*com),com);
    }
 
    return 0;
}
