#include <bits/stdc++.h>

using namespace std;

pair<int,int> start,finish;
map<char,int> asing;
bool table[9][9];
int di[]={-2,-1,1,2,2,1,-1,-2};
int dj[]={-1,-2,-2,-1,1,2,2,1};

int BFS(){
    deque< pair< pair<int,int> ,int> > que;
    que.push_back(make_pair(start,0));
    while(!que.empty()){
        table[que[0].first.first][que[0].first.second]=true; //Vuleve ese espacio verdadero
        if(que[0].first.first==finish.first && que[0].first.second==finish.second) return que[0].second; //Verifica si ya se llego al destino
        for(int i=0;i<8;i++){ // genera los posibles movimientos de la ficha
            if(que[0].first.first+di[i]>-1 && que[0].first.first+di[i]<8 && que[0].first.second+dj[i]>-1 && que[0].first.second+dj[i]<8){ //Verifica que no se salga del array con las sumas y restas
                if(!table[que[0].first.first+di[i]][que[0].first.second+dj[i]]){ // verifica si la posicion ya esta visitada
                    que.push_back(make_pair( make_pair(que[0].first.first+di[i],que[0].first.second+dj[i]) ,que[0].second+1)); // Ingresa una nueva posicion a la cola
                }
            }
        }
        que.pop_front();
    }
    return -1;
}

int main(){
    string a,b;
    asing['a']=0;
    asing['b']=1;
    asing['c']=2;
    asing['d']=3;
    asing['e']=4;
    asing['f']=5;
    asing['g']=6;
    asing['h']=7;
    while((cin>>a>>b)){
        memset(table,false,sizeof table);
        int temp=(a[1]-'0')-1;
        int temp2=(b[1]-'0')-1;
        start=make_pair(asing[a[0]],temp);
        finish=make_pair(asing[b[0]],temp2);
        int ans=BFS();
        cout<<"To get from "<<a<<" to "<<b<<" takes "<<ans<<" knight moves."<<endl;
    }
    return 0;
}
