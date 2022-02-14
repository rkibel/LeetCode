import java.util.*;

class Problem78 {
    List<List<Integer>> res;
    public List<List<Integer>> subsets(int[] nums) {
        res = new ArrayList<>();
        res.add(new ArrayList<>());
        traverse(nums, new ArrayList<>(), 0);
        return res;
    }
    public void traverse(int[] nums, List<Integer> curr, int index){
        if (index >= nums.length) return;
        List<Integer> copy = new ArrayList<>(curr);
        copy.add(nums[index]);
        res.add(copy);
        traverse(nums, curr, index+1);
        traverse(nums, copy, index+1);
    }
}