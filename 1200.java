import java.util.*;

class Problem1200 {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < arr.length-1; i++){
            int diff = arr[i+1]-arr[i];
            if (diff <= min){
                if (diff < min){
                    res.clear();
                    min = diff;
                }
                res.add(new ArrayList<>(Arrays.asList(arr[i], arr[i+1])));
            }
        }
        return res;
    }
}