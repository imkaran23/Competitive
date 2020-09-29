class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.back()!=9){ 
            digits.back()++; 
            return digits;
        }
        else {
            for(int i=digits.size()-1; i>=0; i--){
                if(digits[i] == 9) digits[i] = 0;
                else{
                    digits[i]++;
                    return digits;
                }
            }
        }
        digits[0]=1;
        digits.push_back(0);
        return digits;
    }
};