import java.util.*;

class Problem368{
    public List<Integer> largestDivisibleSubset(int[]nums){
        Arrays.sort(nums);
        int[]length = new int[nums.length];
        Arrays.fill(length, 1);

        int maxLength = 0;
        for (int i = nums.length-1; i >= 0; i--){
            int tempLength = 0;
            for (int j = i; j < nums.length; j++){
                if (nums[j] % nums[i] == 0)
                    tempLength = Math.max(tempLength, length[j]);
            }
            length[i] += tempLength;
            maxLength = Math.max(maxLength, length[i]);
        }

        List<Integer>output = new ArrayList<>();
        for (int i = 0; i < nums.length; i++){
            if (length[i] == maxLength){
                if (output.size() == 0 || nums[i] % output.get(output.size()-1) == 0)
                    output.add(nums[i]);
                else
                    continue;
                maxLength--;
            }
        }
        return output;
    }
}