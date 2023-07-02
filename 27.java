class Problem27 {
    public int removeElement(int[] nums, int val) {
        int counter = 0;
        for (int i = 0; i < nums.length; i++){
            if (nums[i] == val) counter++;
        }
        int target = nums.length-counter;
        counter = 0;
        for (int i = 0; i < nums.length; i++){
            if (nums[i] != val){
                nums[counter] = nums[i];
                counter++;
            }
        }
        return target;
    }
}