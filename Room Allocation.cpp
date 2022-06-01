#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int a, b;

    vector<tuple<int,int,int>> v;

    for(int i = 0; i<n; i++){
        cin>>a>>b;
        v.push_back({a,0,i});
        v.push_back({b,1,i});
    }

    sort(v.begin(), v.end());

    int c = 0;
    vector<int> arr(n);
    vector<int> vec;

    int x1, y, idx;

    for(auto x : v){
        x1 = get<0>(x);
        y = get<1>(x);
        idx = get<2>(x);
        // cout<<x1<<' '<<y<<' '<<idx<<'\n';

        if(y==0){
            c++;
            if(vec.empty()) arr[idx] = c;
            else {
                arr[idx] = vec.back();
                vec.pop_back();
            } 
        }
        else{
            c--;
            vec.push_back(arr[idx]);
        }
    }

    cout<<*max_element(arr.begin(), arr.end())<<'\n';
    for(auto x : arr) cout<<x<<' ';
    return 0;
}