class Solution {
public:
    vector<int> pancakeSort(vector<int>& a) {
        int n = a.size();
        int m = n ;
        vector<int> v;
        
        while(m>1){
            
            int idx;
            for(int i=0; i<m; i++){
                if(a[i]==m){
                    idx=i;
                    break;
                }
            }
            
            // cout<<m<<" "<<idx<<"\n";
            v.push_back(idx+1);
            v.push_back(m);
            
            rev(a, idx+1, m, n);
            m--;
        }
        
        return v;
    }
    
    void rev(vector<int>& a, int f, int s, int n){
        for(int i=0; i<f/2; i++) swap(a[i], a[f-i-1]);
        // for(int i=0; i<n; i++) cout<<a[i]<<" ";
        // cout<<"\n";
        for(int i=0; i<s/2; i++) swap(a[i], a[s-i-1]);
        // for(int i=0; i<n; i++) cout<<a[i]<<" ";
        // cout<<"\n";
    }
};