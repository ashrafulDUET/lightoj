/*

Name    :      Md. Ashraful Haque
Study   :      CSE, DUET
Address :      Dhaka, Bangladesh

E-mail  :      ashraful.duetg@gmail.com
FB      :      fb.com/ashrafulDUET1

*/


///#include<bits/stdc++.h>
#include <time.h>

#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include<complex>
using namespace std;
///----------------------------------------------------------------------------------------------
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)
#define UI              unsigned int
#define LL              long long int
#define ULL             unsigned long long int
#define HI              printf("HI\n")
#define SF              scanf
#define PF              printf
#define SF1(a)          scanf("%d",&a)
#define SF2(a,b)        scanf("%d %d",&a,&b)
#define SF3(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define SF4(a,b,c,d)    scanf("%d %d %d %d",&a,&b,&c,&d)
#define SF1LL(a)        scanf("%lld",&a)
#define SF2LL(a,b)      scanf("%lld %lld",&a,&b)
#define SF3LL(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define SF4LL(a,b,c,d)  scanf("%lld %lld %lld %lld",&a,&b,&c,&d)

#define FIR              first
#define SEC              second
#define PB              push_back
#define POB             pop_back
#define PUF             push_front
#define POF             pop_front

#define PLL             pair<LL,LL>
#define PII             pair<int, int>
#define PDD             pair<double, double>
#define MKP             make_pair
#define MAX3(a,b,c)     max(a,max(b,c))
#define MIN3(a,b,c)     min(a,min(b,c))
#define POPC(a)         (__builtin_popcount(a))
#define Unique(a)       sort(all(a)),a.erase(unique(all(a)),a.end())

#define SQR(a)          ((a)*(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define MEM(a,x)        memset((a),x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))
#define PI              acos(-1.0)
#define ALL(a)          a.begin(),a.end()

#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())
#define SIZ(s)           ((int)s.size())
#define END             cout<<endl


#define DEBI4(a,b,c,d)  cout << "   --> " << #a << " = " << a << " \n"<< "   --> " << #b << " = " \
<< b << " \n"<< "   --> " << #c << " = " << c << " \n"<< "   --> " << #d << " = " << d << " \n"

template<class T1,class T2,class T3,class T4,class T5,class T6> void debt6(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

/// <---------------------------  For Bitmasking  -------------------------------->

//template <class T, class X> inline bool getbit(T a, X i) { T t=1; return ((a&(t<<i))>0);}
//template <class T, class X> inline T setbit(T a, X i) { T t=1;return (a|(t<<i)); }
//template <class T, class X> inline T resetbit(T a, X i) { T t=1;return (a&(~(t<<i)));}
//template <class T, class X> inline T togglebit(T a, X i) { T t=1;return (a^((t<<i)));}
//template <class T> inline T countbit(T a) {return __builtin_popcount( a );}

/// <---------------------------  End of Bitmasking  -------------------------------->

/// <--------------------------- For B - Base Number System ----------------------------------->
//int base;
//int pw[10];
//void calPow(int b){
//    base = b;
//    pw[0] = 1;
//    for( int i = 1; i<10; i++ ){
//        pw[i] = pw[i-1]*base;
//    }
//}
//int getV(int mask, int pos){
//    mask /= pw[pos];
//    return ( mask%base );
//}
//int setV(int mask, int v, int pos){
//    int rem = mask%pw[pos];
//    mask /= pw[pos+1];
//    mask = ( mask*base ) + v;
//    mask = ( mask*pw[pos] ) + rem;
//    return mask;
//}
/// <--------------------------- End B - Base Number System ----------------------------------->

// moves

int dx[]= {0,0,1,-1};/*4 side move*/
int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/

//double Expo(double n, int p) {
//	if (p == 0)return 1;
//	double x = Expo(n, p >> 1);
//	x = (x * x);
//	return ((p & 1) ? (x * n) : x);
//}



//template <class T> inline T bigmod(T p,T e,T M) { T ret = 1; for(; e > 0; e >>= 1) { if(e & 1) ret = (ret * p) % M; p = (p * p) % M; } return (T)ret; }
//template <class T> inline T gcd(T a,T b){while (a&&b)a>b?a%=b:b%=a;return a+b;}
//template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

///--------------------------------------------------Reference Kazi Nayeem and Never Mind----------------------------------------------------

string grid[15],temp;char Next;
int M,N,Q,maxcNum=0,re;
int vis[510][510],cost,dist[15][15];
void bfs(int x, int y)
{
    if(grid[x][y]== (maxcNum + 'A')){re =0;return;}
    re =-1;
    queue<pair<int , int > >q;
    q.push({x,y});
    vis[x][y] = 1;
    grid[x][y]='.';
    while(!q.empty())
    {
        pair<int , int >  from = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = from.FIR + dx[i];
            int ny = from.SEC + dy[i];
            if((nx>=0 && nx<M) && (ny>=0 && ny<M) && !vis[nx][ny] && (grid[nx][ny]=='.' || grid[nx][ny] == Next))
               {

                   vis[nx][ny]=1;
                   dist[nx][ny] = dist[from.FIR][from.SEC] + 1;
                   q.push({nx,ny});
                   if(grid[nx][ny] == (maxcNum + 'A'))
                   {
                       grid[nx][ny]='.';
                        re = dist[nx][ny];
                        return;
                   }
                   if(grid[nx][ny] == Next)
                   {
                        Next++;
                        grid[nx][ny]='.';
                         MEM(vis,0);
                        vis[nx][ny] = 1;
                        while(!q.empty())
                            q.pop();
                         q.push({nx,ny});
                         break;
                   }
               }

        }
    }
}

int main()
{
//    FastRead
//    fRead("in");
//    fWrite("out");
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int x,y,sx=-1,sy=-1;
        cin>>M;
        maxcNum =-1;
        for(int i=0;i<M;i++)
        {
           for(int j=0;j<M;j++)
           {
               char ch;
               cin>>ch;
               grid[i][j] = ch;
               if(ch=='A'){sx = i;sy=j;}
               if(ch>='A' && ch<='Z'){maxcNum++;}
           }
        }

        cout<<"Case "<<t<<": ";
        MEM(vis,0);
        MEM(dist,0);
        Next = 'B';
        cost=0;
        bfs(sx,sy);

        if(re==-1  || sx==-1)
            cout<<"Impossible"<<endl;
        else
            cout<<re<<endl;
    }

    return 0;


}

