import java.util.*;

class Problem15 {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        Map<Integer, List<List<Integer>>> map = new HashMap<>();
        
        for (int i = 1; i < nums.length; i++){
            if (i >= 0 && map.containsKey(-nums[i])){
                List<List<Integer>> val = map.get(-nums[i]);
                for (int j = 0; j < val.size(); j++){
                    List<Integer> x = val.get(j);
                    List<Integer> adder = new ArrayList<>(Arrays.asList(x.get(0), x.get(1), nums[i]));
                    if (!res.contains(adder)) res.add(adder);
                }   
            }
            for (int j = i-1; j >= 0; j--){
                int key = nums[j] + nums[i];
                List<Integer> list = new ArrayList<>(Arrays.asList(nums[j], nums[i]));
                if (map.containsKey(key)) map.get(key).add(list);
                else{
                    List<List<Integer>> val = new ArrayList<List<Integer>>();
                    val.add(list);
                    map.put(key, val);
                }
            }
        }
        return res;
    }
}