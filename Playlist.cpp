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

    map<int, int> mp;

    int prev = -1, tmp = 0, ans = 1;
    for(int i=0; i<n; i++){
        if(mp.find(a[i])!=mp.end() && mp[a[i]]>prev){
            prev = mp[a[i]];
            tmp = i - prev;
        }
        else{
            tmp++;
        }
        ans = max(ans, tmp);
        mp[a[i]] = i;
    }
    cout<<ans<<'\n';

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

    map<int, int> mp;

    int prev = -1, tmp = 0, ans = 1;
    for(int i=0; i<n; i++){
        if(mp.find(a[i])!=mp.end() && mp[a[i]]>prev){
            prev = mp[a[i]];
            tmp = i - prev;
        }
        else{
            tmp++;
        }
        ans = max(ans, tmp);
        mp[a[i]] = i;
    }
    cout<<ans<<'\n';

    return 0;
>>>>>>> 9792f9752c6d29d618d9d63727181fd7af8ce748
}