class Problem96 {
public:
    int numTrees(int n) {
        if (n <= 1)
            return 1;
        int output = 0;
        for (int i = 1; i <= n; i++){
            output += numTrees(i-1) * numTrees(n-i);
        }
        return output;
    }
};