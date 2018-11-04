#include<bits/stdc++.h>
#define MAX 1003
#define MSET(A,F) memset(A,F,sizeof(A))
#define ADJC(ADJ,N)    for(int i=0;i<N;i++) ADJ[i].clear()

using namespace std;

vector<int>adj[MAX];
void primeFac(int x)
{
    int c = x;
    for(int i=2;i<=sqrt(c)+1;i++)
    {
        if(c%i==0)
        {
            if(i!=x)
            {
                adj[x].push_back(i);
            }
            while(c%i==0)
                c/=i;
        }
    }
    if(c>1 && c!=x)adj[x].push_back(c);
}
int dist[MAX],re;
void primefactor( int n){
    int ind = n;
    int div = 2;
    int add = 0 ;
    while(n > 1){
        add = 0;
        while( n % div == 0 ){
            add = div;
            n /= div;
        }
        div += 1;
        if( add ) adj[ind].push_back(add);
    }
    if( add == ind ) adj[ind].clear();
}
void bfs(int u, int v)
{

    queue<int>fifo;
    fifo.push(u);
    dist[u]= 0;
    while(!fifo.empty())
    {
        int f = fifo.front();
        fifo.pop();

        for(int i=0;i<(int) adj[f].size();i++)
        {
            int af = f + adj[f][i];

            if(af == v)
                {
                    re = dist[f] + 1;
                    return ;
                }
            else if(af<v && dist[af]==0)
            {
                dist[af] =dist[f] + 1;
                fifo.push(af);
            }
        }
    }

    //return dist[v];

    re = dist[v];
}


int main(){
    freopen("in.txt","r",stdin);
    for(int i=1;i<1001;i++)primeFac(i);
    int T;
    cin>>T;
    for(int t =1;t<=T;t++)
    {
        int u,v,temp;
        cin>>u>>v;
        MSET(dist,0);
        bfs(u,v);
        if(re==0)re=-1; //it can solved by easy way for simplicity, I used this Greedy code.
        if(u==v) re=0;
        cout<<"Case "<<t<<": "<<re<<endl;
    }
    return 0;
}
