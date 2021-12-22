import java.util.*;

class Problem18 {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (nums.length < 4) return res;
        for (int i = 0; i < nums.length-3; i++){
            int x = target-nums[i];
            List<List<Integer>> tsum = threeSum(Arrays.copyOfRange(nums, i+1, nums.length), x);
            if (tsum.size() != 0){
                for (int j = 0; j < tsum.size(); j++){
                    List<Integer> list = tsum.get(j);
                    list.add(0, nums[i]);
                    Collections.sort(list);
                    if (!res.contains(list)) res.add(list);
                }
            }
        }
        return res;
    }
    public List<List<Integer>> threeSum(int[] nums, int target) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        for (int i = 0; i < nums.length; i++){
            int left = i+1, right = nums.length-1;
            while (left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target) left++;
                else if (sum > target) right--;
                else{
                    res.add(new ArrayList<>(Arrays.asList(nums[i], nums[left], nums[right])));
                    while(left+1 <= right && nums[left] == nums[left+1]) left++;
                    left++;
                    right--;
                }
            }
            while(i+1 < nums.length && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
}