#include <bits/stdc++.h>

using namespace std;

vector<bool> isVisited;
vector<int> Color;
string result="None";
vector< vector<int> > graf;

void bicolor(int i){
    isVisited[i]=true;
    for(int j=0;j<graf[i].size();j++){
        if(Color[graf[i][j]]==2){
            Color[graf[i][j]]=(!Color[i]);
        }
        else if(Color[graf[i][j]]==Color[i]){
            result="false";
        }
    }
    for(int j=0;j<graf[i].size();j++){
        if(isVisited[graf[i][j]]==false){
            bicolor(graf[i][j]);
        }
    }
    if(result!="false"){
       result="true";
    }
}

int main(){
    int n,m;
    cin>>n;
    while(n!=0){
        for(int i=0;i<n;i++){
            graf.push_back({});
            isVisited.push_back(false);
            Color.push_back(2);
        }
        Color[0]=1;
        cin>>m;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x;cin>>y;
            graf[x].push_back(y);
            graf[y].push_back(x);
        }
        bicolor(0);
        if(result=="true"){
            cout<<"BICOLORABLE."<<endl;
        }
        else{
            cout<<"NOT BICOLORABLE."<<endl;
        }
        graf.clear();
        Color.clear();
        isVisited.clear();
        result="None";
        cin>>n;
    }
    return 0;
}
