#include <bits/stdc++.h>
//it Does not pass in UVA


using namespace std;
int i,j,d; //declaramos marcadores para saber posicion y direccion del robot;
int tamx,tamy; //Declaramos el tamaño del tablero;
char Direccion[4]={'N','E','S','W'}; //Array para saber a que direccion voltea y en que direccion va
map<char,int> Asignacion;
bool Lost=false,flag=false; //declaramos si esta perdido o no
vector<tuple<int,int>> Marcas;
tuple<int,int> tupla;

bool Coordenadas(){
    if(d==0){
        if(j+1>tamy){
            tupla=make_tuple(i,j);
            for(int k=0;k<Marcas.size();k++){
                if(Marcas[k]==tupla){
                    flag=true;
                    break;
                }
            }
            if(flag==false){
                Lost=true;
                Marcas.push_back(tupla);
                return true;
            }
        }
        else{
            j++;
            return false;
        }

    }

    else if(d==1){
        if(i+1>tamx){
            tupla=make_tuple(i,j);
            for(int k=0;k<Marcas.size();k++){
                if(Marcas[k]==tupla){
                    flag=true;
                    break;
                }
            }
            if(flag==false){
                Lost=true;
                Marcas.push_back(tupla);
                return true;
            }
        }
        else{
            i++;
            return false;
        }
    }

    else if(d==2){
        if(j-1<0){
            tupla=make_tuple(i,j);
            for(int k=0;k<Marcas.size();k++){
                if(Marcas[k]==tupla){
                    flag=true;
                    break;
                }
            }
            if(flag==false){
                Lost=true;
                Marcas.push_back(tupla);
                return true;
            }
        }
        else{
            j--;
            return false;
        }
    }

    else if(d==3){
        if(i-1<0){
            tupla=make_tuple(i,j);
            for(int k=0;k<Marcas.size();k++){
                if(Marcas[k]==tupla){
                    flag=true;
                    break;
                }
            }
            if(flag==false){
                Lost=true;
                Marcas.push_back(tupla);
                return true;
            }
        }
        else{
            i--;
            return false;
        }
    }
}

void Right(){
    if(d==3){
        d=0;
    }
    else{
        d++;
    }
}

void Left(){
    if(d==0){
        d=3;
    }
    else{
        d--;
    }
}

int main(){
    Asignacion['N']=0;
    Asignacion['E']=1;
    Asignacion['S']=2;
    Asignacion['W']=3;
    scanf("%d %d",&tamx,&tamy);
    int initx,inity,initd;// declaramos la posicion inicial del robot junto con su direccion;
    string Movimientos;
    while(scanf("%d %d %c",&initx,&inity,&initd)!= EOF){
        Lost=false;
        d=Asignacion[initd];
        i=initx;
        j=inity;
        cin>>Movimientos;
        for(int paso=0;paso<Movimientos.size();paso++){
            flag=false;
            if(Movimientos[paso]=='L'){
                Left();
            }

            else if(Movimientos[paso]=='R'){
                Right();
            }

            else{
                if(Coordenadas()){
                    break;
                }
            }
        }
        if(Lost) cout<<i<<" "<<j<<" "<<Direccion[d]<<" LOST"<<endl;
        else cout<<i<<" "<<j<<" "<<Direccion[d]<<endl;
    }
    return 0;
}
