// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//         int count = 0;
//         uint32_t mask = 1;
//         for (int i = 0; i < 32; i++) {
//             if ((n & mask) != 0) {
//                 count++;
//             }
//             mask <<= 1;
//         }
//         return count;
//     }
// };

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) { 
            n &= (n - 1); 
            count++; 
        } 
        return count;
    }
};