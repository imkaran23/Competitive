// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t,n;
//     cin>>t;
//     while(t--){
//         cin>>n;
//         int a[n];
//         for (size_t i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }
        
//         sort(a,a+n);
//         int ans = 0,i,j;
//         for (i = 1; i+1 < n; i++)
//         {
//             j=i+2;
//             if(a[j]-a[i]<=2)
//             {
//                 while(j<n && a[j]-a[i]<=2) j++;
//                 int x = j-2-i;
//                 ans += x*(x+1)/2;
//             }
            
//         }
//         cout<<ans<<"\n";
//     }
//     return 0;
// }