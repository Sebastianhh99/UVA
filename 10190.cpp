#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
int m;

void f(int n){
    cout<<n<<endl;
    ans.push_back(n);
    if(n%m==0 && m!=1){
        f(n/m);
    }
}

int main(){
    int n;
    while(scanf("%d %d",&n,&m)!=EOF){
        cout<<m<<endl;
        if(m!=0){
            cout<<1<<endl;
            ans.clear();
            f(n);
        }
        if(ans.back()!=1){
            cout<<"Boring!"<<endl;
        }
        else{
            for(int i=0;i<ans.size()-1;i++){
                cout<<ans[i]<<" ";
            }
            cout<<ans.back()<<endl;
        }
    }
}
