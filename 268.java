import java.util.*;

class Problem268 {
    public int missingNumber(int[] nums) {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i <= nums.length; i++) list.add(i);
        for (int i: nums) list.remove((Integer)i);
        return list.get(0);
    }
}