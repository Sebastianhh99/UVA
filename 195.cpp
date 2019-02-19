#include <bits/stdc++.h>

using namespace std;

string word;
vector<string> ans;

bool comparator(char a,char b){
    if(tolower(a)==tolower(b)){
        return a<b;
    }
    return tolower(a)<tolower(b);
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        ans.clear();
        cin>>word;
        sort(word.begin(),word.end(),comparator);
        cout<<word<<endl;
        while(next_permutation(word.begin(),word.end(),comparator)){
            cout<<word<<endl;
        }
    }
}
