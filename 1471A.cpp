#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n>>x;
        int a;
        long long int s1 =0, s2=0;
        for (int i = 0; i < n; i++)
        {
            cin>>a;
            s1+=a;
            s2+=(a+x-1)/x;
        }
        
        cout<<(s1+x-1)/x<<" "<<s2<<"\n";
    }
    return 0;
    
}
