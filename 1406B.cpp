#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x,p,q;
    cin>>t;
    while(t--){
        cin>>n;
        long long a[n];
        for(int i=0 ;i<n; i++) cin>>a[i];
        sort(a,a+n);
        long long ans;
        ans=max(a[n-1]*a[n-2]*a[n-3]*a[n-4]*a[n-5],a[n-1]*a[n-2]*a[n-3]*a[0]*a[1]);
		ans=max(ans,a[n-1]*a[2]*a[3]*a[0]*a[1]);
        
        cout<<ans<<endl;
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t,n,tmp;
//     cin>>t;
//     while(t--){
//         cin>>n;
//         long long a[n], ans=1, count=0;
//         vector<long long> v(6);
//         for(int i=0 ;i<n; i++){ cin>>a[i]; if(a[i]==0) count++; }

//         if(count>n-5){ cout<<0<<endl; continue;}
//         else{
//             count = 5;
//             for(int i=0 ;i<n && count; i++) {
//                     if(a[i]!=0){ ans *= a[i]; count--;}
//             } 
//         }

//         for(int i=0 ;i<5; i++){ v[i] = a[i]; }
//         v[5] = ans;

//         for(int i=5 ;i<n; i++){
//             tmp = -1;
//             for(int j=0 ;j<5; j++){
//                 // cout<<ans<<" "<<v[5]/v[j]*a[i]<<endl;
//                 if(v[j]!=0 && ((v[5]/v[j])*a[i]) > ans){
//                     ans = v[5]/v[j]*a[i];
//                     tmp = j;
//                 }
//             }

//             if(tmp!=-1){ v[tmp] = a[i]; v[5] = ans;}
//         }

//         cout<<ans<<endl;
//     }
//     return 0;
// }