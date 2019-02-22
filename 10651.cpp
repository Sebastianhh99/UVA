#include <bits/stdc++.h>

using namespace std;

int fichas(char str[17],int valor){
    int number=valor;

    for(int i=2;i<14;i++){
        if(str[i]=='o'){
            if(str[i-1]=='o' && str[i-2]=='-'){

                str[i]='-';
                str[i-1]='-';
                str[i-2]='o';

                valor=min(valor,fichas(str,number-1));
                str[i]='o';
                str[i-1]='o';
                str[i-2]='-';

            }
            if(str[i+1]=='o' && str[i+2]=='-'){
                str[i]='-';
                str[i+1]='-';
                str[i+2]='o';
                valor=min(valor,fichas(str,number-1));
                str[i]='o';
                str[i+1]='o';
                str[i+2]='-';
            }
        }
    }

    return valor;
}

int main(){
    char lis1[13],lis2[17];
    int cont,n;
    lis2[0]='o';lis2[1]='o';lis2[15]='o';lis2[14]='o';
    cin>>n;
    for(int j=0;j<n;j++){
        cont=0;
        cin>>lis1;
        for(int i=2;i<14;i++){
            lis2[i]=lis1[i-2];
            if(lis1[i-2]=='o')cont++;
        }

        cout<<fichas(lis2,cont)<<endl;
    }
    return 0;
}
