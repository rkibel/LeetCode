class Problem668 {
public:
    int findKthNumber(int m, int n, int k) {
        int high = m*n, low = 1;
        while (low < high){
            int mid = low + (high-low)/2;
            if (greaterThan(m, n, mid) < k)
                low = mid+1;
            else
                high = mid;
        }
        return low;
    }
    int greaterThan(int row, int col, int element){
        int counter = 0;
        for (int i = 1; i <= row; i++){
            if (element / i <= col)
                counter += element/i;
            else 
                counter += col;
        }
        return counter;
    }
};