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
        cout<<"Test case #"<<k<<endl;
        int lps[t.length()];
        // i : suffix boundary
        // j : prefix boundary
        lps[0] = 0;
        for (int i = 1; i < t.length(); ++i) {
            // update prefix boundary
            int j = lps[i - 1];
            // move to the last prefix boundary match
            while (j > 0 && t[j] != t[i]) j = lps[j - 1];
            // if prefix and suffix boundary matches, increase prefix length
            j += (t[j] == t[i] ? 1 : 0) ;
            lps[i] = j ;
            if(j>0 && (i+1)%(i+1-j)==0)
                cout<<i+1<<" "<<(i+1)/(i+1-j)<<endl;
        }
        cout<<endl;
    }
    return 0;
}