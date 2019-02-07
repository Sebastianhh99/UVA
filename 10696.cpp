#include <bits/stdc++.h>

using namespace std;



int f91(int N){
    if(N<=100){
        return f91(f91(N+11));
    }
    else{
        return N-10;
    }
}

int main(){
    int N;
    cin>>N;
    while(N!=0){
        cout<<"f91("<<N<<") = "<<f91(N)<<endl;
        cin>>N;
    }
    return 0;
}
