#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a,b;
        for(int i=0; i<n; i++){ 
            cin>>x;
            if(x%2) b.push_back(x);
            else a.push_back(x);
        }
        sort(a.begin(), a.end(), greater<>());
        sort(b.begin(), b.end(), greater<>());
        long long sa=0, sb=0;
        auto ita = a.begin(), itb = b.begin();
        for(int i=0; i<n; i++){
            if(i%2){
                //BOB
                if(itb!=b.end() && ita!=a.end()){
                    if(*itb>*ita){
                        sb+=*itb;
                        itb++;
                    }
                    else{
                        ita++;
                    }
                }
                else if (itb!=b.end()){
                    sb+=*itb;
                    itb++;
                }
                else{
                    ita++;
                }
            }
            else{
                //ALICE
                if(ita!=a.end() && itb!=b.end()){
                    if(*ita>*itb){
                        sa+=*ita;
                        ita++;
                    }
                    else{
                        itb++;
                    }
                }
                else if (ita!=a.end()){
                    sa+=*ita;
                    ita++;
                }
                else{
                    itb++;
                }
            }
        }

        // cout<<sa<<" "<<sb<<" ";
        if(sa>sb) cout<<"Alice\n";
        else if(sa==sb) cout<<"Tie\n";
        else cout<<"Bob\n";
    }
    return 0;
    
}
