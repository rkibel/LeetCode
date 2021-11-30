class Problem84 {
    public int largestRectangleArea(int[] heights) {
        int soln = 0;
        for (int i = 0; i < heights.length; i++){
            soln = Math.max(soln, maxArea(heights, i+1));
        }
        return soln;
    }
    public int mArray(int[]arr, int start, int end){
        Integer m = null;
        for (int i = start; i <= end; i++){
            if (m == null) m = arr[i];
            m = Math.min(arr[i], m);
        }
        return m;
    }
    public int maxArea(int[] arr, int nextTo){
        int area = 0;
        for (int i = 0; i < arr.length+1-nextTo; i++){
            int minHeight = mArray(arr, i, i+nextTo-1);
            area = Math.max(area, minHeight*nextTo);
        }
        return area;
    }
}