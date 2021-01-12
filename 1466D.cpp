#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x,y;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> w(n+1,0), e(n+1,0), w1;
        long long sum = 0;
        for(int i=1; i<=n ; i++){
            cin>>w[i];
            sum+=w[i];
        }

        for(int i=0; i<n-1 ; i++){
            cin>>x>>y;
            e[x]++;
            e[y]++;
        }

        for(int i=1; i<=n ; i++){
            if(e[i]>1){
                for(int j=1; j<e[i]; j++)
                    w1.push_back(w[i]);
            }
        }

        sort(w1.begin(),w1.end(),greater<>());

        cout<<sum<<" ";
        for(int k : w1) sum+=k, cout<<sum<<" ";
        cout<<"\n";
    }
    return 0;
}