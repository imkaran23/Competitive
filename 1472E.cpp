#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,w,h,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> h(n), w(n);
        vector<pair<int,pair<int,int>>> v;
        long long int area = INT_MAX;
        int mh = INT_MAX,mw = INT_MAX;
        for(int i=0; i<n; i++){ 
            cin>>h[i]>>w[i];
            area = min(area, (long long int)h[i]*w[i]);
            mw = min(mw,w[i]);
            mh = min(mh,h[i]);
        }
        
        for(int i=0; i<n; i++){
            if((long long int)h[i]*w[i] == area || mw==w[i] || mh==h[i]) 
                v.push_back({i,{h[i],w[i]}});

        }

        for(int i=0; i<n; i++){
            bool flag = true;
            for(auto x : v){
                if((x.second.first < h[i] && x.second.second < w[i]) || 
                   (x.second.second < h[i] && x.second.first < w[i])){
                       cout<<x.first+1<<" ";
                       flag = false;
                       break;
                   }
            }
            if(flag) cout<<-1<<" ";
        }

        cout<<"\n";
    }
    return 0;
    
}
