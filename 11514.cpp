#include <bits/stdc++.h>

using namespace std;
vector<int> Poder;
vector<int> Calorias;
vector<string> Nombres;
vector<int> Poderv;
vector<string> Afecta;
long long INF=1e10;
ofstream Archivo;

int Valido(int i, int j){
    if(i==Poder.size() || j==Poderv.size()){
        if(j<Poderv.size()){
            return INF;
        }
        else{
            return 0;
        }
    }
    else if((Afecta[j].find(Nombres[i])==Afecta[j].npos) || (Poder[i]<Poderv[j])){
        return Valido(i+1,j);
    }
    else{
        return Calorias[i]+min(Valido(i+1,j),Valido(i+1,j+1));
    }
}

int main(){
    Archivo.open("salida.txt",ios::out);
    int super,villan,caloria,a,b;
    string poder,villano,afectado;
    scanf("%d %d %d",&super,&villan,&caloria);
    while(super+villan+caloria!=0){
        for(int k=0;k<super;k++){
            cin>>poder;cin>>a;cin>>b;
            Nombres.push_back(poder);
            Poder.push_back(a);
            Calorias.push_back(b);
        }
        for(int k=0;k<villan;k++){
            cin>>villano;cin>>a;cin>>afectado;
            Poderv.push_back(a);
            Afecta.push_back(afectado);
        }
        int Minimo=Valido(0,0);
        if(Minimo<=caloria){
            Archivo<<"Yes"<<endl;
        }
        else{
            Archivo<<"No"<<endl;
        }
        Poder.clear();
        Calorias.clear();
        Nombres.clear();
        Poderv.clear();
        Afecta.clear();
        scanf("%d %d %d",&super,&villan,&caloria);
    }
    return 0;
}
