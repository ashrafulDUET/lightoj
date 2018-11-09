#include<bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("in","r",stdin);
//    freopen("out","w",stdout);
    long long int a,b,n,m,i,j,ck=0,ln,ln2;
    string FirstStr,subStr;
    cin>>n;
    for(i=1; i<=n; i++){
        cin>>FirstStr;
        ln = FirstStr.length();
        cin>>subStr;
        ln2 = subStr.length();

        for(j=0; j<ln; j++){

             if(FirstStr.compare(j,ln2,subStr)==0){ //Substring Compare UsingBuildinFuc
                ck++;
             }
        }
        printf("Case %lld: %lld\n",i, ck);
        ck=0;

    }


}
