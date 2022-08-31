#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin>>t;

    while(t--){
        long long n, k, b, s;
        cin>>n>>k>>b>>s;
        
        bool flag = true;

        if(b>s || s > b*k + n*(k-1) || s<b*k) cout<<-1<<'\n';
        else{
            vector<long long> ans;

            long long tmp = b*k + k-1;

            if(s>tmp){
                ans.push_back(tmp);
                s -= tmp;

                while(s>0){
                    if(s>k-1){
                        ans.push_back(k-1);
                        s -= k-1;
                    }
                    else{
                        ans.push_back(s);
                        s = 0;
                    }

                    if(ans.size()>n){
                        cout<<-1<<'\n';
                        flag = false;
                        break;
                    }
                }

                if(flag){
                    while(ans.size()<n) ans.push_back(0);
                    for(int x : ans) cout<<x<<' ';
                    cout<<'\n';
                }
            }
            else{
                if(s/k != b){
                long long tmp = b*k;

                ans.push_back(tmp);
                s -= tmp;

                while(s>0){
                    if(s>k-1){
                        ans.push_back(k-1);
                        s -= k-1;
                    }
                    else{
                        ans.push_back(s);
                        s = 0;
                    }

                    if(ans.size()>n){
                        cout<<-1<<'\n';
                        flag = false;
                        break;
                    }
                }

                if(flag){
                    while(ans.size()<n) ans.push_back(0);
                    for(int x : ans) cout<<x<<' ';
                    cout<<'\n';
                }
                }
                else{
                    ans.push_back(s);
                    s = 0;
                    while(ans.size()<n) ans.push_back(0);
                    for(long long x : ans) cout<<x<<' ';
                    cout<<'\n';
                }
            }
        }
    }

    return 0;
}