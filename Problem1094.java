import java.util.*;

class Problem1094 {
    public boolean carPooling(int[][] trips, int capacity) {
        Map<Integer, Integer> map = new TreeMap<>();
        for (int[] trip: trips){
            if (map.containsKey(trip[1])) map.put(trip[1], map.get(trip[1]) + trip[0]);
            else map.put(trip[1], trip[0]);
            if (map.containsKey(trip[2])) map.put(trip[2], map.get(trip[2]) - trip[0]);
            else map.put(trip[2], -trip[0]);
        }
        int curr = 0;
        for (Integer key: map.keySet()){
            curr += map.get(key);
            if (curr > capacity) return false;
        }
        return true;
    }
}