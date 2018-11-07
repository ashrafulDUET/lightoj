/*
Name    :      Md. Ashraful Haque
Study   :      CSE, DUET
Address :      Dhaka, Bangladesh
 E-mail :      ashraful.duetg@gmail.com
FB      :      fb.com/ashrafulDUET1
 */


#include<bits/stdc++.h>
#define MAXN 55
using namespace std;
struct edge{
    int u,v,w;
    bool operator<(const edge &p)const{
        return (w<p.w);
    }
};
vector<edge> e; int p[MAXN];
//--->>>>>>>>----------->>START BFS<<-----------<<<<<<<<<<<<<<---
    bool vVis[55];
    queue<int> qbsf;
    vector<int>gCompo[55];
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
    return (p[x] == x)? x : p[x] = findp(p[x]);
}
long long MST(int n){  //start Minimum spanning tree
    sort(e.begin(),e.end());
    for(int i=0;i<=MAXN;i++) p[i] = i;
    int num =0,u,v,len = e.size();long long cost =0;
    //cout<<"Choice \t Edge \t Weight"<<endl<<endl;
    for(int j=1,i =0 ;i<len; i++){
        u = findp(e[i].u);
        v = findp(e[i].v);
        if(u != v){
            p[u] = v; //Same as : p[p[u]] = p[v]; make v is the root parents of u.
            cost += e[i].w;
            num++;
            //cout<<" "<<j++<<"\t [ "<<u<<","<<v<<" ] \t"<<e[i].w<<endl;
        }
        if(num == n-1) break;
    }
    return cost;
}   //End MST
int main(){
    //freopen("in.txt","r",stdin);
    int tc,nE,nN,u,v,w; edge ed;long long re,total;
    cin>>tc;
    for(int t =1;t<=tc;t++)
        {
            cin>>nN;total =0;
            for(int i=1;i<=nN;i++)
            {
                for(int j=1;j<=nN;j++)
                {
                    scanf("%d",&w);
                    total += w;
                    ed.u = i;
                    ed.v = j;
                    ed.w = w;
                    if(w!=0){
                        e.push_back(ed);
                        gCompo[i].push_back(j);
                        gCompo[j].push_back(i);
                    }
                }
            }
            re = MST(nN);
            int c = findComp(nN);
            if(c>1 || c==0 )
                printf("Case %d: -1\n",t);
            else
                printf("Case %d: %lld\n",t,total - re);
            e.clear();
        }
    return 0;
}
