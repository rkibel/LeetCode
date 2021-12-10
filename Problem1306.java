class Problem1306 {
    public boolean canReach(int[] arr, int start) {
        boolean[] b = new boolean[arr.length];
        return jumper(arr, b, start);
    }
    public boolean jumper(int[] arr, boolean[] bools, int index){
        if (arr[index] == 0) return true;
        else if (bools[index] == false){
            boolean a = false;
            bools[index] = true;
            if (index + arr[index] < arr.length) a = jumper(arr, bools, index + arr[index]);
            if (index - arr[index] >= 0) a = a || jumper(arr, bools, index-arr[index]);
            return a;
        }
        return false;
    }
}