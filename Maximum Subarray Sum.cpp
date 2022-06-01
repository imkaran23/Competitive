<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    } 

    long long int s = 0, ans = INT_MIN;

    for(int i=0; i<n; i++){
        s+=a[i];
        ans = max(ans, s);
        if(s<0) s=0;
    }

    cout<<ans;

    return 0; 
=======
#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    } 

    long long int s = 0, ans = INT_MIN;

    for(int i=0; i<n; i++){
        s+=a[i];
        ans = max(ans, s);
        if(s<0) s=0;
    }

    cout<<ans;

    return 0; 
>>>>>>> 9792f9752c6d29d618d9d63727181fd7af8ce748
}