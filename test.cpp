#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int, pair<int,int>> mp;

    mp[1] = {1,1};
    mp[2] = {1,2};
    mp[3] = {1,3};
    mp[4] = {2,1};
    mp[5] = {2,2};
    mp[6] = {2,3};
    mp[7] = {3,1};
    mp[8] = {3,2};
    mp[9] = {3,3};

    int arr[10][10];

    for(int i=1;i<10; i++){
        for(int j=1; j<10; j++){
            auto x = mp[i];
            auto y = mp[j];
            arr[i][j] = max(abs(x.first-y.first), abs(x.second-y.second));
        }
    }

    for(int i=1;i<10; i++){
        for(int j=1; j<10; j++){
            cout<<arr[i][j];
        }
        cout<<'\n';
    }

    long long ans = 0;

    string s;
    cin>>s;
    
    for(int i=0; i<s.size()-1; i++){
        int x = s[i]-'0';
        int y = s[i+1] - '0';

        ans += arr[x][y];
    }

    return 0;
}

