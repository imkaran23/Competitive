<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

int find(vector<vector<int>>& v, int i){
    int l = 0, h = i-1;
    while(l<=h){
        int mid = (l+h)/2;

        if(v[i][0]>v[mid][1]){
            if(v[i][0]>v[mid+1][1]) l = mid+1;
            else return mid;
        }
        else h = mid-1;
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,a,b,p;
    cin>>n;

    vector<vector<int>> v;
    for(int i=0; i<n; i++){
        cin>>a>>b>>p;
        v.push_back({a,b,p});
    }

    auto cmp = [](vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    };

    sort(v.begin(), v.end(), cmp);

    long long dp[n];
    dp[0] = v[0][2];

    for(int i=1; i<n; i++){
        dp[i] = v[i][2];
        // for(int j=i-1; j>=0; j--){
        //     if(v[j][1]<v[i][0]){
        //         dp[i] = max(dp[i], v[i][2]+dp[j]);
        //         // break;
        //     }
        // }

        int j = find(v, i);
        if(j!=-1) dp[i] = max(dp[i-1], v[i][2]+dp[j]);
        else dp[i] = max(dp[i-1], dp[i]);
    }

    // long long ans = 0;
    // // cout<<'\n';
    // for(int i=0; i<n; i++){
    //     // cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<"\n";
    //     ans = max(ans, dp[i]);
    // }

    cout<<dp[n-1];

    return 0;
=======
#include<bits/stdc++.h>
using namespace std;

int find(vector<vector<int>>& v, int i){
    int l = 0, h = i-1;
    while(l<=h){
        int mid = (l+h)/2;

        if(v[i][0]>v[mid][1]){
            if(v[i][0]>v[mid+1][1]) l = mid+1;
            else return mid;
        }
        else h = mid-1;
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,a,b,p;
    cin>>n;

    vector<vector<int>> v;
    for(int i=0; i<n; i++){
        cin>>a>>b>>p;
        v.push_back({a,b,p});
    }

    auto cmp = [](vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    };

    sort(v.begin(), v.end(), cmp);

    long long dp[n];
    dp[0] = v[0][2];

    for(int i=1; i<n; i++){
        dp[i] = v[i][2];
        // for(int j=i-1; j>=0; j--){
        //     if(v[j][1]<v[i][0]){
        //         dp[i] = max(dp[i], v[i][2]+dp[j]);
        //         // break;
        //     }
        // }

        int j = find(v, i);
        if(j!=-1) dp[i] = max(dp[i-1], v[i][2]+dp[j]);
        else dp[i] = max(dp[i-1], dp[i]);
    }

    // long long ans = 0;
    // // cout<<'\n';
    // for(int i=0; i<n; i++){
    //     // cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<"\n";
    //     ans = max(ans, dp[i]);
    // }

    cout<<dp[n-1];

    return 0;
>>>>>>> 9792f9752c6d29d618d9d63727181fd7af8ce748
}