#include <cstdint>

class Solution {
public:
    uint32_t reverseBits(uint32_t n, int len = 32) {
        return (len == 0) ? 0 : reverseBits(n>>1, len-1) | ((n&0x00000001)<<(len-1)); 
    }
};