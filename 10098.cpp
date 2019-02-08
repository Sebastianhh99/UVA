#include <bits/stdc++.h>

using namespace std;

string word;

void f(){
    while(next_permutation(word.begin(),word.end())){
        cout<<word<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>word;
        sort(word.begin(),word.end());
        cout<<word<<endl;
        f();
        cout<<""<<endl;
    }
}
