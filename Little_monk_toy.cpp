#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

main(){
    int n,x;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(),v.end());
    // int curr_width=0,prev_width=v[0],h=1,curr_box=0,prev_box=1;
    // for(int i=1;i<n;i++){
    //     curr_width+=v[i];
    //     curr_box++;
    //     if(curr_width>prev_width && curr_box>prev_box){
    //         prev_width= curr_width;
    //         prev_box=curr_box;
    //         h++;
    //         curr_width=0;
    //         curr_box=0;
    //     }
    // }
    int h;
    h = -1 + sqrt(1+8*n);
    cout<<h/2<<endl;
}   