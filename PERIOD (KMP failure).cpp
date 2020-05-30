#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)

int main(){
    int q;
    cin>>q;
    f(k,1,q){
        int n;
        string t;
        cin>>n>>t;
        int lps[n+1];
        // i : suffix boundary
        // j : prefix boundary
        lps[0] = 0;
        for (int i = 1; i < t.length(); ++i) {
            // update prefix boundary
            int j = lps[i - 1];
            // move to the last prefix boundary match
            while (j > 0 && t[j] != t[i]) j = lps[j - 1];
            // if prefix and suffix boundary matches, increase prefix length
            lps[i] = j + (t[j] == t[i] ? 1 : 0);
        }

        cout<<"Test case #"<<k<<endl;
        f(i,2,n){
            if(i<n && lps[i]>lps[i+1]) cout<<i<<" "<<lps[i]<<endl;
            else cout<<" "<<lps[i]<<endl;
        }
    }
    return 0;
}