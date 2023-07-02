import java.util.*;
class Solution {
    Map<Integer, List<Integer>> map = new HashMap<>();
    List<List<String>>list = new ArrayList<>();
    public List<List<String>> partition(String s) {
        for (int i = 0; i < s.length(); i++){
            for (int j = i+2; j <= s.length(); j++){
                if (isPalin(s.substring(i, j))){
                    if (map.containsKey(i)) map.get(i).add(j-1);
                    else map.put(i, new ArrayList<>(Arrays.asList(j-1)));
                }
            }
        }
        traverse(s, new ArrayList<String>(), 0);
        return list;
    }
    public void traverse(String s, ArrayList<String> curr, int pos){
        if (pos >= s.length()){
            list.add(curr);
            return;
        }
        if (map.containsKey(pos)){
            for (Integer i: map.get(pos)){
                ArrayList<String> iter = new ArrayList<>(curr);
                iter.add(s.substring(pos, i+1));
                traverse(s, iter, i+1);
            }
        }
        curr.add(Character.toString(s.charAt(pos)));
        traverse(s, curr, pos+1);
    }
    public boolean isPalin(String s){
        for (int i = 0; i < s.length()/2; i++) if (s.charAt(i) != s.charAt(s.length()-1-i)) return false;
        return true;
    }
}