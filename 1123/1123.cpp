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
vector<edge> e;
vector<edge> ne;
int p[MAXP];
int findp(int x)
{
    return (p[x] == x)? x : p[x] = findp(p[x]);
}
int MST(int n){  //start Minimum spanning tree
    for(int i=1;i<=n;i++){ //make itself parents
            p[i] = i;
        }
    sort(e.begin(),e.end());
    int cost =0, num =0,u,v;
    //cout<<"Choice \t Edge \t Weight"<<endl<<endl;
    for(int j=1,i =0 ;i<e.size(); i++){
        u = findp(e[i].u);
        v = findp(e[i].v);
        if( u!= v){
             p[u] = v;
            cost += e[i].w;
            num++;
            ne.push_back(edge(e[i].u,e[i].v,e[i].w));
            //cout<<" "<<j++<<"\t [ "<<mps[u]<<","<<mps[v]<<" ] \t"<<e[i].w<<endl;
        }
        if(num == n-1) return cost;;
    }
    return -1;
}   //End MST


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tc;
    cin>>tc;
    for(int tCase=1;tCase<=tc;tCase++)
    {
        int nCheck[205];
        memset(nCheck,0,sizeof(nCheck));
        int nE,nN,w,m=1,mycity,cn=0; edge ed; int  u,v;
        cin>>nN>>nE;

        cout<<"Case "<<tCase<<":"<<endl;
        for(int i =0;i<nE; i++){
            scanf("%d %d %d",&u,&v,&w);
            //cin>>u>>v>>w;
            if(nCheck[u]==0)
                {
                    nCheck[u]=true;
                    cn++;
                }
            if(nCheck[v]==0)
                {
                    nCheck[v]=true;
                    cn++;
                }
            ed.u = u;
            ed.v = v;
            ed.w = w;
            e.push_back(ed);
            if(cn<nN)printf("%d\n",-1);
            else{


                int re = MST(nN);
                if( re  == -1)
                    printf("%d\n",-1);
                else
                    printf("%d\n",re);

                e.clear();
                e.assign(ne.begin(),ne.end());
                ne.clear();
            }
        }
        e.clear();

    }

    return 0;
}

