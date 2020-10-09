class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0;
        vector<int> a(n,0);
        int ans = 0;
        for(int i=2; i<n; i++){
            if(!a[i]){
                ans++;
                for(int j=2*i; j<n; j+=i) a[j] = 1;
            }
        }
        return ans;
    }
};