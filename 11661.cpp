#include <bits/stdc++.h>

using namespace std;

int Distancia(string Cadena){
    int pos_1;
    int pos_2;
    char flag='N';
    unsigned int ans=1e12;
    unsigned int temp=0;
    for(int i=0;i<Cadena.size();i++){
        if(Cadena[i]=='Z') return 0;
        else if(Cadena[i]=='R' && flag=='D'){
            pos_2=i;
            temp=abs(pos_1-pos_2);
            if(temp<ans) ans=temp;
            flag='R';
            pos_1=i;
        }
        else if(Cadena[i]=='D' && flag=='R'){
            pos_2=i;
            temp=abs(pos_1-pos_2);
            if(temp<ans) ans=temp;
            flag='D';
            pos_1=i;
        }
        else if(Cadena[i]=='R'){
            pos_1=i;
            flag=Cadena[i];
        }
        else if(Cadena[i]=='D'){
            pos_1=i;
            flag=Cadena[i];
        }
    }
    return ans;
}

int main(){
    int n,ans;
    string Cadena;
    cin>>n;
    while(n!=0){
        cin>>Cadena;
        ans=Distancia(Cadena);
        cout<<ans<<endl;
        cin>>n;
    }
    return 0;
}
