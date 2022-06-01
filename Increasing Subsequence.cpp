<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

int LIS(vector<int>& v)
{
    if (v.size() == 0) // boundary case
        return 0;
 
    vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail
 
    tail[0] = v[0];
 
    for (int i = 1; i < v.size(); i++) {
 
        // Do binary search for the element in
        // the range from begin to begin + length
        auto b = tail.begin(), e = tail.begin() + length;
        auto it = lower_bound(b, e, v[i]);
 
        // If not present change the tail element to v[i]
        if (it == tail.begin() + length)
            tail[length++] = v[i];
        else
            *it = v[i];
    }
 
    return length;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n;

    vector<int> v(n);
    // int a[n];
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    // int dp[n];

    // for(int i=0; i<n; i++){
    //     dp[i] = 1;
    //     for(int j=0; j<i; j++){
    //         if(a[j]<a[i]){
    //             dp[i] = max(dp[i], dp[j] + 1);
    //         }
    //     }
    // }
    // cout<<dp[n-1]<<'\n';

    cout<<LIS(v);

    return 0;
=======
#include<bits/stdc++.h>
using namespace std;

int LIS(vector<int>& v)
{
    if (v.size() == 0) // boundary case
        return 0;
 
    vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail
 
    tail[0] = v[0];
 
    for (int i = 1; i < v.size(); i++) {
 
        // Do binary search for the element in
        // the range from begin to begin + length
        auto b = tail.begin(), e = tail.begin() + length;
        auto it = lower_bound(b, e, v[i]);
 
        // If not present change the tail element to v[i]
        if (it == tail.begin() + length)
            tail[length++] = v[i];
        else
            *it = v[i];
    }
 
    return length;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n;

    vector<int> v(n);
    // int a[n];
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    // int dp[n];

    // for(int i=0; i<n; i++){
    //     dp[i] = 1;
    //     for(int j=0; j<i; j++){
    //         if(a[j]<a[i]){
    //             dp[i] = max(dp[i], dp[j] + 1);
    //         }
    //     }
    // }
    // cout<<dp[n-1]<<'\n';

    cout<<LIS(v);

    return 0;
>>>>>>> 9792f9752c6d29d618d9d63727181fd7af8ce748
}