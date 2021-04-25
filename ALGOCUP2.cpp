#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T --) {
        int n, x, cnt = 0, m=INT_MAX;
        bool flag = 0;

        cin >> n;
        for(int i=0;i<n;i++){
            cin>>x;
            if(x==1) 
                flag = 1;
            if(x>1){
                m = min(m,x);
                cnt++;
            }
        }

        if(flag && cnt==0) cnt++,m=1;
        cout<<cnt<<" "<<m<<"\n";
    }
    return 0;
}