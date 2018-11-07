/*
Name    :      Md. Ashraful Haque
Study   :      CSE, DUET
Address :      Dhaka, Bangladesh
 E-mail :      ashraful.duetg@gmail.com
FB      :      fb.com/ashrafulDUET1
 */


#include<bits/stdc++.h>
#define MAXN 20005
using namespace std;
vector<int> GT[MAXN],result;
int indeg[MAXN];
map<string,int>mp;
map<int,string>imp;//For printing nodes.

bool topological_sort(int n)    //Call with total number of nodes.
{
    queue<int>Q;
    for(int i=0;i<n;i++){
        if(indeg[i]==0)Q.push(i);
    }
    while(!Q.empty()){
        int f = Q.front();
        Q.pop();
        for(int i=0;i<GT[f].size();i++){
            indeg[GT[f][i]]--;
            if(indeg[GT[f][i]]==0)
                Q.push(GT[f][i]);
        }
    }
    bool flag = true;
    for(int i=0;i<n;i++){
        if(indeg[i] != 0){
                for( ;i<n;i++)
                    indeg[i]=0;
            flag = false;
            break;
        }
    }
    return flag;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int tc,nE,nN=0,m=0;string u,v;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++)
    {
        cin>>nE;nN=0,m=0;
        for(int i =0;i<nE; i++){
            cin>>u>>v;
            if(mp.find(u)==mp.end()){
                    mp[u] =m;
                    imp[m++] = u;
                    nN++;
            }
            if(mp.find(v)==mp.end()){
                mp[v] =m;
                imp[m++] = v;
                nN++;
            }
            GT[mp[u]].push_back(mp[v]);
            indeg[mp[v]]++;
        }
        bool r = topological_sort(nN+1);
        if(r)
        {
            printf("Case %d: Yes\n",t);
        }
        else{
            printf("Case %d: No\n",t);
        }
        mp.clear();
        imp.clear();
        for(int i=0;i<MAXN;i++)
        GT[i].clear();
    }

    return 0;
}
