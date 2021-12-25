import java.util.*;
class Problem56 {
    public int[][] merge(int[][] intervals) {
        //LinkedList approach
        Arrays.sort(intervals, (a,b) -> Integer.compare(a[0], b[0]));
        LinkedList<int[]> res = new LinkedList<>();
        for (int[] interval: intervals){
            if (res.isEmpty() || res.getLast()[1] < interval[0]) 
                res.add(interval);
            else if (res.getLast()[1] >= interval[0]) 
                res.getLast()[1] = Math.max(res.getLast()[1], interval[1]);
        }
        return res.toArray(new int[res.size()][]);

        //ArrayList approach
        /*
        Arrays.sort(intervals, (a,b)-> Integer.compare(a[0], b[0]));
        List<int[]> list = new ArrayList<>();
        list.add(intervals[0]);
        int iter = 0;
        for (int i = 1; i < intervals.length; i++){
            if (list.get(iter)[1] >= intervals[i][0]) 
                list.set(iter, new int[]
                {list.get(iter)[0], 
                Math.max(list.get(iter)[1], intervals[i][1])}
                );
            else{
                iter++;
                list.add(intervals[i]);
            }
        }
        return list.toArray(new int[list.size()][]);
        */
    }
}