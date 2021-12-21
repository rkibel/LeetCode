import java.util.*;

class Problem16 {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < nums.length; i++){
            int left = i+1, right = nums.length-1;
            while(left < right){
                int diff = target - (nums[i] + nums[left] + nums[right]);
                if (Math.abs(diff) < Math.abs(min)) min = diff;
                if (diff < 0) right--;
                else if (diff > 0) left++;
                else return target;
            }
            while(i+1 < nums.length && nums[i] == nums[i+1]) i++;
        }
        return target - min;
    }
}