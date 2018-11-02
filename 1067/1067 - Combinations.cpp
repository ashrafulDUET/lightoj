#include<bits/stdc++.h>
using namespace std;
#define MOD 1000003

long long  x,y;

void extenedEuclid(long long a, long long b){
    if( b == 0){
        x = a;
        y = 0;
        return ;
    }
    extenedEuclid(b, a % b);
    long long tx, ty;
    tx = y;
    ty = x - a/b*y;
    x = tx;
    y = ty;
}
int mInv(int a, int m)
{
    extenedEuclid(a,m);
    return (x + MOD)%MOD ;
}

long long  nmodm[1000006];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    nmodm[0]=1;
    for(long long i=1;i<1000006;i++)
    {
        nmodm[i] = (nmodm[i-1] * i) % MOD;
    }
    int tc;
    cin>>tc;
    for(int t = 1;t<=tc;t++)
    {
        //cout<<nmodm[38968]<<endl;
        int n,r;
        cin>>n>>r;
        int s = (nmodm[(n-r)]%MOD * nmodm[r] ) %MOD;
        int re = mInv(s,MOD);

        cout<<"Case "<<t<<": "<<(nmodm[n] * re )%MOD<<endl;

    }
    return 0;
}




































