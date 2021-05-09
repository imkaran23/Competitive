class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        while(a != 0 || b != 0 || c){
            int aBit = a & 1;
            int bBit = b & 1;
            int cBit = c & 1;
            if(cBit == 1 && bBit == 0 && aBit == 0){
                count ++; 
            }else if (cBit == 0){
                if(aBit == 1 && bBit == 1) count += 2;
                if(aBit + bBit == 1) count++;
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return count;
    }
};

// class Solution {
// public:
//     int minFlips(int a, int b, int c) {
//         int count = 0;
//         while (a | b != c)
//         {
//             // get left bits of each number
//             int aa = a & 0x1;
//             int bb = b & 0x1;
//             int cc = c & 0x1;
//             if (cc == 0) // if left bit of c is zero - both a and b have to be zero
//             {
//                 if (aa == 1) {count++; a--;}
//                 if (bb == 1) {count++; b--;}
//             }
//             else // if left bit of c is one, either a or b have to be one
//                 if ((aa == 0) && (bb == 0)) {count++; a += 1;}
//             a = a>>1;
//             b = b>>1;
//             c = c>>1;
//         }
//         return count;
//     }
// };