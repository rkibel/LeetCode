import java.util.*;
class Problem30 {
    public List<Integer> findSubstring(String s, String[] words) {
        int len = words[0].length();
        Map<Integer, List<Integer>> map = new HashMap<>();
        
        for (int i = 0; i < words.length; i++){
            int index = s.indexOf(words[i]);
            while(index >= 0){
                if (map.containsKey(index)) map.get(index).add(i);
                else map.put(index, new ArrayList<>(Arrays.asList(i)));
                index = s.indexOf(words[i], index+1);
            }
        }

        Queue<int[]> q = new LinkedList<>();
        List<Integer> res = new ArrayList<>();
        for (Integer key: map.keySet()){
            int[] start = new int[words.length+2];
            start[0] = key;
            start[1] = key;
            q.add(start);
        }
        
        while(!q.isEmpty()){
            int[] curr = q.poll();
            if (full(curr) && !res.contains(curr[0])){
                res.add(curr[0]);
                continue;
            }
            if (map.containsKey(curr[1])){
                for (Integer key: map.get(curr[1])){
                    if (curr[key+2] == 0){
                        int[] copy = curr.clone();
                        copy[key+2] = 1;
                        copy[1] += len;
                        q.add(copy);
                    }
                }
            }
        }
        return res;
    }
    public boolean full (int[] arr){
        for (int i = 2; i < arr.length; i++){
            if (arr[i] == 0) return false;
        }
        return true;
    }
}