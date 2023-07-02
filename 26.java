public class Problem26 {
    public int removeDuplicates(int[] nums) {
        /*boolean[] b = new boolean[201];
        for (int i: nums) b[i+100] = true;
        int counter = 0;
        for (int i = 0; i < b.length; i++)
            if (b[i]){
                nums[counter] = i-100;
                counter++;
            }
        return counter;
        */
        
        if (nums.length < 2) return nums.length;
        int totCount = 0, curr = nums[0];
        for (int i = 1; i < nums.length; i++){
            if (nums[i] == curr) totCount++;
            else curr = nums[i];
            nums[i-totCount] = nums[i];
        }
        return nums.length-totCount;
        
    }
}