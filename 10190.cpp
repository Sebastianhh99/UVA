#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n, i;
    while(scanf("%d %d", &m, &n) != EOF) {
        if(n < 2 || m == 0 || m < n) {
            cout<<"Boring!"<<endl;
            continue;
        }
        int ans[100] = {m};
        for(i = 1; ; i++) {
            if(ans[i-1] == 1)
                break;
            if(ans[i-1]%n) {
                i = -1;
                break;
            }
            ans[i] = ans[i-1]/n;
        }
        if(i < 0)   cout<<"Boring!"<<endl;
        else {
            printf("%d", ans[0]);
            for(m = 1; m < i; m++)
                printf(" %d", ans[m]);
            puts("");
        }
    }
    return 0;
}
