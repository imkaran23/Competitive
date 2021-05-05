class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        ans.push_back(label); 
        int h=log2(label);
        
        while(h!=0){
            int l=pow(2,h-1); 
            int r=pow(2,h)-1;
            label=l+(r-label/2);
            ans.push_back(label);  
            h--;
        }
        
        reverse(ans.begin(),ans.end()); 
        return ans;
    }
};

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        int h=log2(label);
        
        int rlabel = pow(2,h) + pow(2,h+1) - 1 -label;
        while(label != 0 && rlabel != 0){
            ans.push_back(label);          
            label /= 2;
            rlabel /= 2;
            swap(label,rlabel);
        }
        
        reverse(ans.begin(),ans.end()); 
        return ans;
    }
};

// class Solution {
// public:
//     const int n = 1e6 + 1; 
//     int a[1000002];
    
//     Solution(){
//         int j = 1,k=0;
//         for(int i=0; i<=log2(n); i++){
//             int z = pow(2,i);
//             if(i%2==0){
//                 while(z-- && k<n) a[k++] = j, j++;
//             }
//             else{
//                 int k1 = k+z;
//                 k += z-1; 
//                 while(z-- && k<n) a[k--] = j, j++;
//                 k  = k1;
//             }
//         }
//     }
    
//     vector<int> pathInZigZagTree(int label) {
//         vector<int> v;
//         int idx;
//         for(int i=0; i<n; i++) if(a[i] == label) {idx = i; break;}
//         while(idx){
//             v.push_back(a[idx]);
//             idx = (idx-1)/2;
//         }
//         v.push_back(1);
        
//         reverse(v.begin(), v.end());
//         cout<<idx<<" ";
//         return v;
//     }
// };