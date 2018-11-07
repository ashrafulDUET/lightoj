/*
Name    :      Md. Ashraful Haque
Study   :      CSE, DUET
Address :      Dhaka, Bangladesh
 E-mail :      ashraful.duetg@gmail.com
FB      :      fb.com/ashrafulDUET1
 */

#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
struct edge{
    int u,v,w;
};
vector<edge> e; int p[MAXN];
bool cmpl(const edge p1, const edge p2){
        return (p1.w<p2.w);
    }
bool cmpg(const edge p1, const edge p2){
        return (p1.w>p2.w);
    }
int findp(int x){
    return (p[x] == x)? x : p[x] = findp(p[x]);
}
int MST(int n,int cp){  //start Minimum spanning tree
    if(cp==1)
        sort(e.begin(),e.end(),cmpg);
    else
        sort(e.begin(),e.end(),cmpl);
    for(int i=0;i<=MAXN;i++) p[i] = i;
    int cost =0, num =0,u,v,len = e.size();
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
        if(num == n) break;
    }
    return cost;
}   //End MST
int main(){
    //freopen("in.txt","r",stdin);
    int tc,nE,nN,u,v; edge ed;long long remn,remx;
    cin>>tc;
    for(int t =1;t<=tc;t++)
        {
            cin>>nN;
            while(1)
            {
                scanf("%d%d%d",&ed.u,&ed.v,&ed.w);
                if(ed.u==0 && ed.v==0 &&ed.w==0)
                    break;
                e.push_back(ed);
            }
            remx = MST(nN,1);
            remn = MST(nN,0);
            e.clear();
            if((remn+remx)&1)
                printf("Case %d: %lld/2\n",t,(remn+remx));
            else
                printf("Case %d: %lld\n",t,(remn+remx)/2);
        }
    return 0;
}
