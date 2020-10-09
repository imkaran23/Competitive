class Solution {
public:
    int nthUglyNumber(int n) { 
        if(n <= 6) return n;
        if(n <= 9) return n+1;
        vector<int> k(n,1);
        int p2 = 0, p3 = 0, p5 = 0;      
        for(int i  = 1; i < n ; i ++)
        {
            k[i] = min(k[p2]*2,min(k[p3]*3,k[p5]*5));
            if(k[i] == k[p2]*2) p2++; 
            if(k[i] == k[p3]*3) p3++;
            if(k[i] == k[p5]*5) p5++;
        }
        return k[n-1];
    }
};