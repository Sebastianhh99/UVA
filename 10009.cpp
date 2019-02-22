#include <bits/stdc++.h>

using namespace std;

map<string,int> go;
map<int,string> backk;
vector< vector<int> > G;

string BFS(int start,int finish){
    deque< pair<int,string> > que;
    que.push_back(make_pair(start,""));
    while(que.size()!=0){
        pair<int,string> temp=que[0];
        que.pop_front();
        if(temp.first==finish){
            return temp.second;
        }
        for(int i=0;i<G[temp.first].size();i++){
            que.push_back(make_pair(G[temp.first][i],temp.second+backk[G[temp.first][i]][0]));
        }
    }
}

int main(){
    string a,b;
    int cases,n,m;
    cin>>cases;
    for(int casee=0;casee<cases;casee++){
        int tam=0;
        G.clear();
        go.clear();
        backk.clear();
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++){
            cin>>a;
            cin>>b;
            if(go.count(a)==0){
                vector<int> temp;
                G.push_back(temp);
                go[a]=tam;
                backk[tam]=a;
                tam++;
            }
            if(go.count(b)==0){
                vector<int> temp;
                G.push_back(temp);
                go[b]=tam;
                backk[tam]=b;
                tam++;
            }
            G[go[a]].push_back(go[b]);
            G[go[b]].push_back(go[a]);
        }
        for(int i=0;i<m;i++){
            int start,finish;
            cin>>a;
            cin>>b;
            start=go[a];
            finish=go[b];
            if(start!=finish){
                string ans=BFS(start,finish);
                cout<<a[0]<<ans<<endl;
            }
            else{
                cout<<a[0]<<endl;
            }
        }
        if(casee!=cases-1){
            cout<<""<<endl;
        }
    }
}
