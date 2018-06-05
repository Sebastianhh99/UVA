#include <bits/stdc++.h>

using namespace std;

int main(){
    deque<int> Cartas;
    vector<int> Descartadas;
    int n;
    cin>>n;
    while(n!=0){
        if(n==1){
            cout<<"Discarded cards:"<<endl;
            cout<<"Remaining card: "<<1<<endl;
            Descartadas.clear();
            Cartas.clear();
            cin>>n;
        }
        else{
        for(int i=1;i<=n;i++){
            Cartas.push_back(i);
        }
        while(Cartas.size()>1){
            Descartadas.push_back(Cartas[0]);
            Cartas.pop_front();
            Cartas.push_back(Cartas[0]);
            Cartas.pop_front();
        }
        cout<<"Discarded cards: ";
        for(int i=0;i<Descartadas.size();i++){
            if(i==Descartadas.size()-1){
                cout<<Descartadas[i]<<endl;
            }
            else{
                cout<<Descartadas[i]<<", ";
            }
        }
        cout<<"Remaining card: "<<Cartas[0]<<endl;
        Descartadas.clear();
        Cartas.clear();
        cin>>n;
        }
    }
    return 0;
}
