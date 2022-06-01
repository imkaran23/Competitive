<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x,y;
    cin>>n;

    vector<pair<int,int>> v;

    for(int i=0; i<n; i++){
        cin>>x>>y;
        v.push_back({x,1});
        v.push_back({y,-1});
    } 

    int ans = 0, tmp = 0;

    sort(v.begin(), v.end());

    for(auto x : v){
        tmp += x.second;
        ans = max(ans, tmp);
    }   

    cout<<ans;

    return 0; 
=======
#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x,y;
    cin>>n;

    vector<pair<int,int>> v;

    for(int i=0; i<n; i++){
        cin>>x>>y;
        v.push_back({x,1});
        v.push_back({y,-1});
    } 

    int ans = 0, tmp = 0;

    sort(v.begin(), v.end());

    for(auto x : v){
        tmp += x.second;
        ans = max(ans, tmp);
    }   

    cout<<ans;

    return 0; 
>>>>>>> 9792f9752c6d29d618d9d63727181fd7af8ce748
}