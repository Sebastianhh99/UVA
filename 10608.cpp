#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > G;
bool visited[30001];

int DFS(int i){
    visited[i]=true;
    int cont=1;
    for(int j=0;j<G[i].size();j++){
        if(!visited[G[i][j]]){
            cont+=DFS(G[i][j]);
        }
    }
    return cont;
}

int main(){
    int cases,n,m,a,b,ans;
    cin>>cases;
    for(int c=0;c<cases;c++){
        G.clear();
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++){
            vector<int> temp;
            G.push_back(temp);
        }
        for(int i=0;i<m;i++){
            scanf("%d %d",&a,&b);
            G[a-1].push_back(b-1);
            G[b-1].push_back(a-1);
        }
        ans=DFS(0);
        for(int i=1;i<G.size();i++){
            memset(visited,false,sizeof visited);
            ans=max(ans,DFS(i));
        }
        cout<<ans<<endl;
    }
}
