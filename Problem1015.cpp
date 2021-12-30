class Problem1015 {
public:
    int smallestRepunitDivByK(int k) {
        int n = 0;
        for (int i = 1; i <= k; i++){
            n = (n*10+1) % k;
            if (n == 0) return i;
        }
        return -1;
    }
};