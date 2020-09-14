class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ans;
        for (string row : rows) ans += row;
        return ans;
    }
};
// TLE
// class Solution {
// public:
//     string convert(string s, int n) {
//         if(s.size()==0 || s.size()==1) return s;
//         int k = (n-1)*2,j,z;
//         string ans = "";
//         for(int i=0; i<n; i++){
//             if(k<=0) k += (n-1)*2;
//             z = k;
//             j = i;
//             ans += s[j];
//             while(j+z < s.size()){
//                 j += z;
//                 ans += s[j];
//                 if((n-1)*2-z>0) z = (n-1)*2-z;
//                 // cout<<k<<" "<<z<<endl;
//             }
            
//             k -= 2;
//         }
        
//         return ans;
//     }
// };