#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        long long result=0,curr=0,maxi=0;
        for (size_t i = 0; i < n; i++){
            cin>>a[i];
            if(i%2==0) result += a[i];
        }
        
        for (size_t i = 1; i < n; i+=2){
            curr += a[i] - a[i-1];
            if(curr<0) curr=0;
            maxi = max(maxi,curr);
        }

        curr = 0;
        for (size_t i = 1; i < n-1 ; i+=2){
            curr += a[i] - a[i+1];
            if(curr<0) curr=0;
            maxi = max(maxi,curr);
        }

        cout<<result+maxi<<endl;
    }
}