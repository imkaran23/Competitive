class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0, power = 31;
    while (n != 0) {
      ret += (n & 1) << power;
      n = n >> 1;
      power -= 1;
    }
    return ret;
    }
};

// class Solution {
// public:
//     uint32_t reverseByte(uint32_t byte, map<uint32_t, uint32_t> cache) {
//         if (cache.find(byte) != cache.end()) {
//             return cache[byte];
//         }
//         uint32_t value = (byte * 0x0202020202 & 0x010884422010) % 1023;
//         cache.emplace(byte, value);
//         return value;
//     }

//     uint32_t reverseBits(uint32_t n) {
//         uint32_t ret = 0, power = 24;
//         map<uint32_t, uint32_t> cache;
//         while (n != 0) {
//             ret += reverseByte(n & 0xff, cache) << power;
//             n = n >> 8;
//             power -= 8;
//         }
//         return ret;
//     }
// };

// class Solution {
// public:
//     uint32_t reverseBits(uint32_t num) {
//     unsigned int count = sizeof(num) * 8 - 1; 
//     unsigned int reverse_num = num; 
      
//     num >>= 1;  
//     while(num) 
//     { 
//        reverse_num <<= 1;        
//        reverse_num |= num & 1; 
//        num >>= 1; 
//        count--; 
//     } 
//     reverse_num <<= count; 
//     return reverse_num; 
//     }
// };