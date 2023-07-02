class Problem69 {
public:
    int mySqrt(int x) {
        //O(logn) binary search approach
        return SQRT(x, 0, x);
    }
    int SQRT(int x, int left, int right){
        if (right == left) return right;
        long mid = ((long)left+(long)right+1)/2;
        if (mid*mid <= (long)x) return SQRT(x, mid, right);
        return SQRT(x, left, mid-1);
    }
};