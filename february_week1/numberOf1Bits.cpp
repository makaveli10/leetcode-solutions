#include <stdint.h>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // in each iteration shift right and check least significant digit
        int result = 0;
        
        while (n > 0){
            // n & n-1 gives 0 is n is power of 2 
            n = n & n-1;
            result ++;
        }
        return result;
    }
};