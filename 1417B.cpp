#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0; i<n; i++){ 
            cin>>a[i];   
        }

        unordered_map<int, int> s1,s2;
        for(int i=0; i<n; i++){
            bool ins1 = s1.find(k-a[i]) != s1.end();
            bool ins2 = s2.find(k-a[i]) != s2.end();
            if(!ins1){
                cout<<1<<" ";
                s1[a[i]]++;
            }
            else if(!ins2){
                cout<<0<<" ";
                s2[a[i]]++;
            }
            else if(s1[k-a[i]] < s2[k-a[i]]){
                cout<<1<<" ";
                s1[a[i]]++;
            }
            else{
                cout<<0<<" ";
                s2[a[i]]++;
            }
        }
        cout<<endl;
    }
    return 0;
}