#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){ 
        int n,r,R,maxi=0,idx=-1;
        cin>>n;
        vector<vector<int>> v(n);
        for(int i=0; i<n; i++){
			cin>>r>>R;
            v[i] = {r,R};
            if(r>maxi){
                maxi = r;
                idx = i;
            }
		}

        bool flag = true;
        for(int i=0; i<n; i++){
            if(i!=idx && v[i][1] >=maxi) flag = false;
        }

        if(flag) cout<<idx+1<<"\n";
        else cout<<-1<<"\n";
    }

    return 0;
}