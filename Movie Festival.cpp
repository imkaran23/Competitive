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
        v.push_back({y,x});
    } 

    sort(v.begin(), v.end());

    int ans = 1, b = v[0].first;

    for(int i=1; i<n; i++){
        if(v[i].second>=b){
            b = v[i].first;
            ans++;
        }
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
        v.push_back({y,x});
    } 

    sort(v.begin(), v.end());

    int ans = 1, b = v[0].first;

    for(int i=1; i<n; i++){
        if(v[i].second>=b){
            b = v[i].first;
            ans++;
        }
    }

    cout<<ans;

    return 0; 
>>>>>>> 9792f9752c6d29d618d9d63727181fd7af8ce748
}