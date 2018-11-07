/*
Name    :      Md. Ashraful Haque
Study   :      CSE, DUET
Address :      Dhaka, Bangladesh
 E-mail :      ashraful.duetg@gmail.com
FB      :      fb.com/ashrafulDUET1
 */
 
 #include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 1,-1,-1,2,-2,2,-2};
int dy[] = {2,-2, 2,-2,1,1,-1,-1};
int VisDist[15][15];
string arr[50];
int fx,fy,fr,m,n;
struct node{
    int x,y,r;
    node(int a, int b, int c=0){x=a;y=b;r=c;}
};
void get(node obj)
{
    fx = obj.x;
    fy = obj.y;
    fr = obj.r;
}

int  bfs(int x, int y,int desx,int desy)
{
    if(x==desx && y ==desy) return 0;
    memset(VisDist,-1,sizeof(VisDist));
    queue<node>q;
    q.push(node(x,y));
    VisDist[x][y]=0;
    while(!q.empty())
    {
        get(q.front());
        q.pop();
        for(int i=0;i<8;i++)
        {
            x = fx + dx[i];
            y = fy + dy[i];
            if((x>=0 && x<m) && (y>=0 && y<n))
            {
                if(VisDist[x][y]==-1)
                {
                    VisDist[x][y] = VisDist[fx][fy] +1;
                    if(x==desx && y ==desy)
                    {
                        return VisDist[x][y];
                    }
                    q.push(node(x,y));
                }
            }

        }
    }
    return -1;

}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    for(int tc=1;tc<=T;tc++)
    {
        int mini=INT_MAX,flag=0;
        cin>>m>>n;
        for(int i=0;i<m;i++){
            cin>>arr[i];
        }
        vector<node>allRider;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][j]!='.')
                {
                    allRider.push_back(node(i,j,arr[i][j]-'0'));
                }
            }
        }
        int result =INT_MAX;
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            int sum=0,f=0;
            for(int k=0;k<allRider.size();k++)
            {
                int retDis = bfs(allRider[k].x,allRider[k].y,i,j);
                if(retDis==-1)
                {
                    f =1;
                    break;
                }
                sum += (retDis + allRider[k].r - 1)/allRider[k].r;
            }
            if(f == 0 && sum<result)
                result =sum;
        }
        cout<<"Case "<<tc<<": ";
        if(result==INT_MAX)
            cout<<-1<<endl;
        else
            cout<<result<<endl;
    }
    return 0;
}
































