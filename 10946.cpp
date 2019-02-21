#include <bits/stdc++.h>

using namespace std;

int di[]={-1,1,0,0};
int dj[]={0,0,-1,1};
vector<string> G;
deque< pair<int,char> > ans;
int n,m;

bool sorting(pair<int,char> a,pair<int,char> b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first>b.first;
}

int DFS(int i,int j){
    char temp=G[i][j];
    int cont=1;
    G[i][j]='.';
    for(int k=0;k<4;k++){
        if(i+di[k]>-1 && j+dj[k]>-1 && i+di[k]<n && j+dj[k]<m){
            if(G[i+di[k]][j+dj[k]]==temp){
                cont+=DFS(i+di[k],j+dj[k]);
            }
        }
    }
    return cont;
}

int main(){
    int cases=0;
    char t[51];
    scanf("%d %d",&n,&m);
    while(n+m!=0){
        G.clear();
        ans.clear();
        cases++;
        for(int i=0;i<n;i++){
            cin>>t;
            G.push_back(t);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(G[i][j]!='.'){
                    char temp=G[i][j];
                    ans.push_back(make_pair(DFS(i,j),temp));
                }
            }
        }
        sort(ans.begin(),ans.end(),sorting);
        cout<<"Problem "<<cases<<":"<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].second<<" "<<ans[i].first<<endl;
        }
        scanf("%d %d",&n,&m);
    }
    return 0;
}
