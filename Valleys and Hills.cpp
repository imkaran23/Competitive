#include<bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){

        int n,m;
        cin>>n>>m;

        string s = "";

        if(n>m){
            s = "010";
            n--;

            while(m--){
                s += "10";
                n--;
            }

            while(n--){
                s += "010";
            }
            
        }

        else if(n<m){
            s = "101";
            m--;

            while(n--){
                s += "01";
                m--;
            }

            while(m--){
                s += "101";
            }
        }
        
        else{
            int z = n+1;
            s = "";
            while(z--){
                s += "01";
            }
        }

        cout<<s.size()<<"\n"<<s<<"\n";
    }
    
    return 0;
}