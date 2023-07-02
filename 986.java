import java.util.*;

class Problem986 {
    public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
        List<Integer>nums1 = new ArrayList<>();
        for (int[] a : firstList){
            for (int i = a[0]; i <= a[1]; i++){
                if (i == a[0] || i == a[1]) nums1.add(-i);
                else nums1.add(i);
            }
                
        }
        List<Integer> nums2 = new ArrayList<>();
        for (Integer b : nums1){
            if (found(secondList, b) != 0)
                nums2.add(found(secondList, b) * Math.abs(b));
        }
        System.out.println(nums2);
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        Integer begin = null;
        Integer end = null;
        for (int i = 0; i < nums2.size(); i++){
            Integer rep = nums2.get(i);
            if (rep < 0){
                List<Integer> x = new ArrayList<>();
                x.add(rep); x.add(rep);
                list.add(x);
                begin = null; end = null;
                continue;
            }
            if (begin == null){
                begin = rep;
                end = rep;
                continue;
            }
            if (rep-1 == nums2.get(i-1)){
                end = rep;
                continue;
            }
            List<Integer> x = new ArrayList<>();
            x.add(begin);
            x.add(end);
            list.add(x);
            begin = null; end = null;
        }
        
        int[][]output = new int[0][0];
        //for (int i = 0; i < list.size(); i++){
        //    output[i] = list.get(i);
        //}
        return output;
    }
    public int found(int[][]list, int val){
        boolean neg = false;
        if (val <= 0)
            neg = true;
        int v = Math.abs(val);
        for (int i = list.length-1; i >= 0; i--){
            if (list[i][0] <= v){
                if (neg && (list[i][0] == v || list[i][1] == v))
                    return -1;
                else if (list[i][1] >= v)
                    return 1;
                return 0;
            }
        }
        return 0;
    }
}