/*

Name    :      Md. Ashraful Haque
Study   :      CSE, DUET
Address :      Dhaka, Bangladesh

E-mail  :      ashraful.duetg@gmail.com
FB      :      fb.com/ashrafulDUET1

*/


#include <bits/stdc++.h>
#define INF 10000000
using namespace std;
int dx[] = {1,-1, 0, 0};
int dy[] = {0, 0, 1,-1};

char arr[205][205];
int vis[205][205];
int dist1[205][205];
int dist2[205][205];
int R,C,re;
struct node{
    int X,Y;
    node(int a, int b){X=a;Y=b;}
};
queue<node> q;
void BFS()
{
    int x, y ;
    memset(vis,0,sizeof(vis));
    while(!q.empty())
    {
        x = q.front().X;
        y = q.front().Y;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if( (x1>=0 && x1<R)  &&  (y1>=0 && y1<C) )
            if((!vis[x1][y1]) && (arr[x1][y1]!='#'))
            {
                vis[x1][y1]=1;
                if((dist1[x][y] + 1) < dist1[x1][y1] )
                    dist1[x1][y1] = dist1[x][y] + 1;
                q.push(node(x1,y1));
            }
        }
    }
}
void BFS2(int x, int y )
{
    memset(vis,0,sizeof(vis));
    memset(dist2,0,sizeof(dist2));
    re =-1;
    queue<node> q;
    q.push(node(x,y));
    vis[x][y]=1;
    while(!q.empty())
    {
        x = q.front().X;
        y = q.front().Y;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if(x1>=0 && x1<R && y1>=0 && y1<C)
            if((!vis[x1][y1]) && (arr[x1][y1]!='#') && ((dist2[x][y]+1)<dist1[x1][y1]))
            {

                vis[x1][y1]=1;
                dist2[x1][y1] = dist2[x][y] + 1;

                if((x1==R-1 || x1==0) || (y1==C-1 || y1==0))
                {
                    re = dist2[x1][y1] + 1;
                    return;
                }
                q.push(node(x1,y1));
            }
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    for(int tc=1;tc<=T;tc++)
    {
        int posJx=0,posJy=0,posFx=0,posFy=0;
        cin>>R>>C;
        for(int i=0;i<205;i++)
        {
            for(int j=0;j<205;j++)
            {
                dist1[i][j]= INF;
            }
        }
        for(int i=0;i<R;i++)
           cin>>arr[i];

        for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
         {
           if(arr[i][j]=='J')
                    {
                        posJx=i;
                        posJy=j;
                    }
            if(arr[i][j]=='F')
                    {
                        //posFx=i;
                        //posFy=j;
                        q.push(node(i,j));
                        vis[i][j]=1;
                        dist1[i][j] =0;
                    }

         }
        cout<<"Case "<<tc<<": ";
        if(posJx==posFx && posJy == posFy)
        {
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        if((posJx==R-1 || posJx==0) || (posJy==C-1 || posJy==0))
        {
            cout<<1<<endl;continue;
        }

        BFS();
        BFS2(posJx,posJy);
        if(re==-1)
        {
            cout<<"IMPOSSIBLE"<<endl;
        }
        else
        {
            cout<<re<<endl;
        }
    }

    return 0;
}











