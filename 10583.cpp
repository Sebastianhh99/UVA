#include <bits/stdc++.h>

using namespace std;

class DS{
private:
    vector<int> Disyunto;
public:
    int tam;
    DS(int n);
    int papa(int i);
    void unir(int x, int y);
};

DS::DS(int n){
    for(int i=0;i<n;i++){
        Disyunto.push_back(i);
    }
    tam=n;
}

int DS::papa(int i){
    if(i!=Disyunto[i]) return papa(Disyunto[i]);
    return i;
}

void DS::unir(int x, int y){
    y=papa(y);
    x=papa(x);
    if(x!=y){
        Disyunto[y]=x;
        tam--;
    }
}

int main(){
    int Case=1;
    int n,m,x,y;
    scanf("%d %d",&n,&m);
    while(n+m!=0){
        DS Conjunto(n);
        for(int i=0;i<m;i++){
            cin>>x;
            cin>>y;
            Conjunto.unir(x,y);
        }
        cout<<"Case "<<Case<<": "<<Conjunto.tam<<endl;
        Case++;
        scanf("%d %d",&n,&m);
    }
    return 0;
}
