#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x,p,q;
    cin>>t;
    while(t--){
        cin>>n;
        int a[101] = {0};
        for(int i=0 ;i<n; i++){
            cin>>x;
            a[x]++;
        }

        for(p=0;a[p]>=2;p++);
		for(q=0;a[q]>=1;q++);
        
        cout<<p+q<<endl;
    }
    return 0;
}