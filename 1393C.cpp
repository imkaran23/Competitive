#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int t;
	cin >> t;
	while(t--)
{
	int n , ans = 0 , arr[100001] = {} , temp;
	cin >> n;
        for(int i = 0 ; i < n ; i++)
		cin >> temp , arr[temp]++;
	for(auto i : arr)
		ans = max(i,ans);
        for(auto i : arr)
		if(i==ans)
			n--;
        ans--;
        cout << n/ans-1 << endl;
}
}

// #include <bits/stdc++.h>
// using namespace std;
// vector<int> v;
// int t,n,x;

// int bs(int low, int high){
//     int mid = (low + high )/2,k=n-2;
//     while(low<=high){
//         mid = (low + high )/2; 
//         cout<<low<<" "<<mid<<" "<<high<<" "<<k<<endl;
//         bool ans = true;
//         for(int i=0; i<v.size(); i++){
//             int tmp = (n-i)/(mid+1) + (n-i)%(mid+1)==0?0:1;
//             if(v[i]>tmp){
//                 ans = false;
//                 break;
//             }
//         }

//         if(ans){ low = mid+1; k = mid;}
//         else high = mid;
//     }
//     return k;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cin>>t;
//     while(t--){
//         cin>>n;
//         int a[n+1]; 
//         memset(a,0,sizeof(a));
//         v.clear();
//         for(int i=0;i<n;i++){ 
//             cin>>x;
//             a[x]++;
//         }

//         for(int i=0;i<=n;i++) if(a[i]) v.push_back(a[i]);
//         sort(v.begin(),v.end(),greater<>());
//         int low=0,high=n-2;
//         cout<<bs(low,high)<<endl;
//     }
//     return 0;
// }