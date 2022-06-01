#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,x,t,z;
    cin>>n>>x;

    vector<pair<long long, long long> > v;

    for(int i=0 ;i<n; i++){
        cin>>t;
        v.push_back({t, i+1});
    }

    sort(v.begin(), v.end());

    for(int i=0; i<n-3; i++){
        for(int j=i+1; j<n-2; j++){

            int k = j+1, l = n-1;
            
            while(k<l){
                long long sum = v[i].first + v[j].first + v[k].first + v[l].first;
                if(sum == x){
                    cout<<v[i].second <<' '<< v[j].second <<' '<< v[k].second <<' '<< v[l].second;
                    return 0;
                }
                else if(sum>x) l--;
                else k++;
            }
            
        }
    }

    cout<<"IMPOSSIBLE";

    return 0;
}