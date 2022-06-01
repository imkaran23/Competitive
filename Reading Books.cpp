<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,t;
    cin>>n;

    vector<long long > v;

    long long sum = 0;

    while(n--){
        cin>>t;
        v.push_back(t);
        sum += t;
    }

    sort(v.rbegin(), v.rend());

    if(v[0]<=sum/2) cout<<sum;
    else cout<<v[0]*2;

    return 0;
=======
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,t;
    cin>>n;

    vector<long long > v;

    long long sum = 0;

    while(n--){
        cin>>t;
        v.push_back(t);
        sum += t;
    }

    sort(v.rbegin(), v.rend());

    if(v[0]<=sum/2) cout<<sum;
    else cout<<v[0]*2;

    return 0;
>>>>>>> 9792f9752c6d29d618d9d63727181fd7af8ce748
}