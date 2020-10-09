class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0, i=a.size()-1, j=b.size()-1;
        string ans = "";
        while(i>=0 || j>=0 || c==1){
            int d1 = i>=0?a[i--]-'0':0, d2 = j>=0?b[j--]-'0':0;
            ans = (char)((c+d1+d2)%2 + '0') + ans;
            c = (c+d1+d2)/2;
        }
        return ans;
    }
};