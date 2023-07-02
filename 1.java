import java.util.*;
class Problem1 {
    public int[] twoSum(int[] nums, int target) {
        
        // O(n) runtime solution
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++){
            if (map.containsKey(target-nums[i])) 
                return new int[] {map.get(target-nums[i]), i};
            map.put(nums[i], i);
        }
        return new int[] {-1, -1};

        /**
        *** O(n^2) runtime solution
        for (int i = 0; i < nums.length-1; i++){
            for (int j = i+1; j < nums.length; j++){
                if (nums[i] + nums[j] == target){
                    return new int[] {j, i};
                }
            }
        }
        return new int[] {-1, -1};
        **/
    }
}