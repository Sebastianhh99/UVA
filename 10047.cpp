#include <bits/stdc++.h>

using namespace std;
char Grafo[30][30];
map< char,tuple<int,int,char,int> > Posibles;
bool isVisited[30][30];
int Distancia[30][30];
Posibles['N']=make_tuple(-1,0,'N',1);
Posibles['S']=make_tuple(1,0,'S',1);
Posibles['E']=make_tuple(0,1,'E',1);
Posibles['W']=make_tuple(0,-1,'W',1);

int BFS(int i,int j){
    deque< pair<int,int> > D;
    D.push_back(make_pair(i,j));
    isVisited[i][j]=true;
    while(!D.empty()){
        i=D[0].first;
        j=D[0].second;
        D.pop_front();
        isVisited[i][j]=true;
        if(Grafo[i][j]=='T'){
            return Distancia[i][j];
        }
        if(isVisited[i+1][j]==false){
            D.push_back(make_pair(i+1,j));
            Distancia[i+1][j]=Distancia[i][j]+1;
        }
        if(isVisited[i-1][j]==false){
            D.push_back(make_pair(i-1,j));
            Distancia[i-1][j]=Distancia[i][j]+1;
        }
        if(isVisited[i][j-1]==false){
            D.push_back(make_pair(i,j-1));
            Distancia[i][j-1]=Distancia[i][j]+1;
        }
        if(isVisited[i][j+1]==false){
            D.push_back(make_pair(i,j+1));
            Distancia[i][j+1]=Distancia[i][j]+1;
        }
    }
    return -1;
}

int main(){
    int inii,inij,n,m,ans;
    string Linea;
    scanf("%d %d",&n,&m);
    while(n+m!=0){
        memset(Distancia,0,sizeof(Distancia));
        memset(Grafo,'N',sizeof(Grafo));
        memset(isVisited,true,sizeof(isVisited));
        for(int i=0;i<n;i++){
            cin>>Linea;
            for(int j=0;j<m;j++){
                Grafo[i+1][j+1]=Linea[j];
                if(Grafo[i+1][j+1]=='S'){
                    inii=i+1;
                    inij=j+1;
                }
                else if(Linea[j]!='#') isVisited[i+1][j+1]=false;
                else isVisited[i+1][j+1]=true;
            }
        }
        ans=BFS(inii,inij);
        cout<<ans<<endl;
        scanf("%d %d",&n,&m);
    }
    return 0;
}
