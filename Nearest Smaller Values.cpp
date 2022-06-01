#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int a[n];
    vector<int> v, ans;

    for(int i=0 ;i<n; i++){
        cin>>a[i];

        while(v.size() && a[v.back()]>=a[i]){
            v.pop_back();
        }

        if(v.size()) ans.push_back(v.back()+1);
        else ans.push_back(0);

        v.push_back(i);
    }

    for (size_t i = 0; i < n; i++) cout<<ans[i]<<' ';
    
    return 0;
}