class Problem461 {
public:
    int hammingDistance(int x, int y) {
        int XOR = x ^ y;
        return countBits(XOR);
        
    }
    int countBits(int num){
        if (num == 0)
            return 0;
        return (num & 1) + countBits(num >> 1);
    }
};