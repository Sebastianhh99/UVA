#include <bits/stdc++.h>

using namespace std;

vector< tuple<int,int,int> > Grafo;
int completo;

class Conjunto{
private:
    vector<int> Disyunt;
    int tam;
    int total;
public:
    Conjunto(int n);
    void Unir(int y, int x, int z);
    int papa(int i);
    void Kruskal();
};

Conjunto::Conjunto(int n){
    for(int i=0;i<n;i++){
        Disyunt.push_back(i);
    }
    tam=n;
    total=0;
}

int Conjunto::papa(int i){
    if(i!=Disyunt[i]){
        return papa(Disyunt[i]);
    }
    else{return i;}

}

void Conjunto::Unir(int y, int x, int z){
    y=papa(y);
    x=papa(x);
    if(x!=y){
        Disyunt[x]=y;
        total=total+z;
        tam=tam-1;
    }
}

void Conjunto::Kruskal(){
    int i=0;
    while(tam!=1){
        Unir(get<1>(Grafo[i]),get<2>(Grafo[i]),get<0>(Grafo[i]));
        i++;
    }
    cout<<completo-total<<endl;
}

int main(){
    int n,m,x,y,z;
    scanf("%d %d",&n,&m);
    while(n+m!=0){
        Conjunto Sete(n);
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&x,&y,&z);
            completo=completo+z;
            Grafo.push_back(make_tuple(z,x,y));
        }
        sort(Grafo.begin(),Grafo.end());
        Sete.Kruskal();
        Grafo.clear();
        completo=0;
        scanf("%d %d",&n,&m);
    }
    return 0;
}
