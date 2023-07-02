import java.util.*;

class Problem169 {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        int m = 0, ele = 0;
        for (Integer i: nums){
            if (map.containsKey(i)) map.put(i, map.get(i)+1);
            else map.put(i, 1);
            if (map.get(i) > m){
                m = map.get(i);
                ele = i;
            }
        }
        return ele;
    }
}