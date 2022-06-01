#include<bits/stdc++.h>
using namespace std;
 
long long check(vector<long long>& v, long long mid, long long& t){
    long long ans = 1, tmp = 0;
    for(auto x : v) {
        if(x > mid) return 0;
        if(tmp + x <= mid) tmp += x;
        else {
            tmp = x;
            ans++;
        }
    }
    return ans; 
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    long long n,t,x,sum=0;
    cin>>n>>t;
 
    vector<long long> v;
 
    while(n--){
        cin>>x;
        v.push_back(x);
        sum += x;
    }
 
    long long l = 1, h = sum;
    long long ans = h, mid;
 
    while(l<=h){
        mid = (l+h)/2;
        long long div = check(v, mid, t);
        // cout<<mid<<" "<<div<<"\n";
        if(div==0 || div>t) l = mid+1;
        else{
            h = mid-1;
            if(div>0) ans = mid;
        }
    }
 
    cout<<ans;
 
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// bool check(vector<long long>& v, long long mid, long long& t){
//     long long ans = 1, tmp = 0;
//     for(auto x : v) {
//         if(x>mid) return 0;
//         if(tmp + x > mid) {
//             ans++;
//             tmp = x;
//         }
//         else {
//             tmp += x;
//         }
//     }
//     cout<<ans<<"\n";
//     return (ans<=t?1:0); 
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     long long n,t,x,sum=0;
//     cin>>n>>t;

//     vector<long long> v;

//     while(n--){
//         cin>>x;
//         v.push_back(x);
//         sum += x;
//     }

//     long long l = 1, h = sum;
//     long long ans = h, mid;

//     while(l<=h){
//         mid = (l+h)/2;
//         cout<<mid<<"\n";
//         if(check(v, mid, t)) {
//             ans = mid;
//             h = mid-1;
//         }
//         else l = mid+1;
//     }

//     cout<<ans;

//     return 0;
// }