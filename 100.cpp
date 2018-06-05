#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m,ans,cont;
    while(scanf("%d %d",&n,&m)!= EOF){
        int Mostrar_n=n,Mostrar_m=m;
        ans=0;
        if(n>m) swap(n,m);
        while(n<=m){
            cont=1;
            long long h=n;
            while(h!=1){
                if(h%2==0){
                    h=h>>1;
                    cont++;
                }
                else{
                    h=3*h+1;
                    cont++;
                }
            }
            if(cont>ans) ans=cont;
            n++;
        }
        printf("%d %d %d\n",Mostrar_n,Mostrar_m,ans);
    }
    return 0;
}
