#include <bits/stdc++.h>

//Falta ordenar en orden alfabetico

using namespace std;

string word;
vector<string> ans;

int main(){
    ofstream archivo;
    archivo.open("test.txt",ios::out);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>word;
        sort(word.begin(),word.end());
        archivo<<word<<endl;
        while(next_permutation(word.begin(),word.end())){
            archivo<<word<<endl;
        }
    }
}
