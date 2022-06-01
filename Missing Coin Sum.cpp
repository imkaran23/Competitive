#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    sort(a, a+n);

    long long int sum = 0;
    for(int i=0; i<n; i++){
        if(a[i]>sum+1){
            cout<<sum+1<<'\n';
            return 0;
        }
        sum += a[i];
    }
    cout<<sum+1<<'\n';

    return 0;
}