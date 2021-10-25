import java.util.*;
public class Problem380 {
    private List <Integer> list;
    public Problem380() {
        list = new ArrayList<>();
    }
    
    public boolean insert(int val) {
        boolean x = list.contains(val);
        if (!x)
            list.add(val);
        return !x;
            
    }
    
    public boolean remove(int val) {
        boolean x = false;
        if (list.contains(val)){
            x = true;
            list.remove(list.indexOf(val));
        }
        return x;
    }
    
    public int getRandom() {
        if (list.size() == 0)
            return -1;
        return list.get((int)(Math.random() * list.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */