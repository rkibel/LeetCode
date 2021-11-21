import java.util.*;

class Problem368{
    private List<Integer> maxSubset, currSubset;

    public List<Integer> largestDivisibleSubset(int[]nums){
        maxSubset = new ArrayList<>(); 
        currSubset = new ArrayList<>();
        List<Integer> NUMS = new ArrayList<>();
        for (int i : nums){
            NUMS.add(i);
        }
        findLargestDivisibleSubset(NUMS);
        return maxSubset;
    }

    void findLargestDivisibleSubset(List<Integer> x){
        if (x.size() == 0){
            if (currSubset.size() > maxSubset.size()){
                maxSubset = copy(currSubset);
            }
            currSubset.clear();
            return;
        }
        int max = findLargest(x);
        if (currSubset.size() == 0){
            currSubset.add(x.get(max));
            x.remove(max);
            findLargestDivisibleSubset(x);
            return;
        }
        else{
            if (belongsInList(currSubset, x.get(max))){
                currSubset.add(x.get(max));
            }
            x.remove(max);
            findLargestDivisibleSubset(x);
            return;
        }

    }

    public int findLargest(List<Integer> nums){
        int max = nums.get(0);
        int index = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums.get(i) > max){
                max = nums.get(i);
                index = i;
            }
        }
        return index;
    }
    public boolean belongsInList(List<Integer> curr, int val){
        for (int i : curr){
            if (val % i != 0 && i % val != 0)
                return false;
        }
        return true;
    }

    public List<Integer> copy(List<Integer> x){
        List<Integer> y = new ArrayList<>();
        for (int i = 0; i < y.size(); i++){
            x.add(y.get(i));
        }
        return y;
    }
}