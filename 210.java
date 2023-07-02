import java.util.*;

class Problem210 {
    List<Integer> list = new ArrayList<>();
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int[] i : prerequisites){
            int course = i[0], prereq = i[1];
            if (map.containsKey(course)) map.get(course).add(prereq);
            else map.put(course, new ArrayList<>(Arrays.asList(prereq)));
            if (!map.containsKey(prereq)) map.put(prereq, new ArrayList<>());
        }
        for (Integer key: map.keySet()){
            parseMap(map, key);
        }
        int[] res = new int[numCourses];
        if (prerequisites.length == 0){
            for (int i = 0; i < numCourses; i++)
                res[i] = numCourses-1-i;
            return res;
        }
        for (int i = 0; i < list.size(); i++){
            res[i] = list.get(i);
        }
        return res;
    }
    public void parseMap(Map<Integer, List<Integer>> map, Integer i){
        if (list.contains(i)) return;
        if (map.get(i).size() == 0) list.add(i);
        else{
            for (Integer t: map.get(i)){
                parseMap(map, t);
            }
            list.add(i);
        }
    }
}