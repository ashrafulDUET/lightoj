#include<bits/stdc++.h>
#define  fst first
#define  snd second
using namespace std;
struct node
{
    int r,c,dist;
    node(int i,int j,int d){r = i;c = j;dist = d;}
};
vector<node>adj[105];
int cost,check[105],row,col;

int rowNum[5]={-1,0,1, 0};
int colNum[5]={ 0,1,0,-1};


char grid[25][25];
int vis[25][25];
int dis[25][25];
void reset()
{
    for(int i=0;i<15;i++)
        for(int j=0;j<15;j++)
            grid[i][j]=0;
}
int bfs(int r, int c)
{
    int step=0;
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
    queue<node> q;
    vis[r][c]=1;
    q.push(node(r,c,0));
    while(!q.empty())
    {
        node f = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nr = f.r + rowNum[i];
            int nc = f.c + colNum[i];
            if((nr>=0 && nr<row) && (nc>=0 && nc<col))
            {
                if(!vis[nr][nc] && grid[nr][nc]!='#' && grid[nr][nc]!='m')
                {
                    //cout<<nr<<" "<<nc<<endl;
                    if(grid[nr][nc]=='h')
                    {
                      return f.dist + 1;
                    }
                    vis[nr][nc] = 1;
                    q.push(node(nr,nc,f.dist+1));
                }
            }
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int tc,a1,a2,b1,b2,c1,c2,h1,h2; char ch;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        cin>>row>>col;
        for(int r=0;r<row;r++)
        {
            cin>>ws;
            for(int c=0;c<col;c++)
            {
                char inp;
                scanf("%c",&inp);
                if(inp=='a')
                {
                    a1=r;a2=c;
                }
                else if(inp=='b')
                {
                    b1=r;b2=c;
                }
                else if(inp=='c')
                {
                    c1=r;c2=c;
                }
                grid[r][c]=inp;


            }
        }
        //cout<<b1<<" " <<b2<<endl<<endl;;
        cout<<"Case "<<i<<": "<<max(bfs(a1,a2),max(bfs(b1,b2),bfs(c1,c2)))<<endl;
//        for(int r=0;r<row;r++){
//            cout<<grid[r] <<endl;
//        }

    }

    return 0;
}
