import java.util.*;

class Problem997 {
    public int findJudge(int n, int[][] trust) {
        if (trust.length == 0){
            return (n == 1) ? 1 : -1;
        }
        Map<Integer, List<Integer>> tru = new HashMap<>();
        List<Integer> trustees = new ArrayList<>();
        for (int[] i: trust){
            if (!trustees.contains(i[0])) trustees.add(i[0]);
            if (tru.containsKey(i[1])) tru.get(i[1]).add(i[0]);
            else tru.put(i[1], new ArrayList<>(Arrays.asList(i[0])));
        }
        for (Integer key: tru.keySet()) 
            if (tru.get(key).size() == n-1 && !trustees.contains(key)) return key;
        return -1;
    }
}