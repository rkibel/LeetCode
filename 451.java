import java.util.*;
public class Problem451 {
    public String frequencySort(String s) {
        List<Character> chars = new ArrayList<>();
        List<Integer> freq = new ArrayList<>();
        String output = "";
        for (int i = 0; i < s.length(); i++){
            if (!chars.contains(s.charAt(i))){
                chars.add(s.charAt(i));
                freq.add(1);
            }
            else{
                int index = chars.indexOf(s.charAt(i));
                freq.set(index, freq.get(index) + 1);
            }
        }
        quickSort(freq, chars, 0, freq.size()-1);
        for (int i = freq.size()-1; i >= 0; i--){
            for (int j = 0; j < freq.get(i); j++){
                output += Character.toString(chars.get(i));
            }
        }
        return output;
    }
    static void quickSort (List<Integer>nums, List<Character> freq, int first, int last){
        int pivot, i, j, temp;
        char t;
        if (first < last){
            pivot = first;
            i = first;
            j = last;
            while (i < j){
                while (nums.get(pivot) >= nums.get(i) && i < last)
                    i++;
                while (nums.get(j) > nums.get(pivot))
                    j--;
                if (i < j){
                    temp = nums.get(i);
                    t = freq.get(i);
                    nums.set(i, nums.get(j));
                    freq.set(i, freq.get(j));
                    nums.set(j, temp);
                    freq.set(j, t);
                }        
            }
            temp = nums.get(pivot);
            t = freq.get(pivot);
            nums.set(pivot, nums.get(j));
            freq.set(pivot, freq.get(j));
            nums.set(j, temp);
            freq.set(j, t);
            quickSort(nums, freq, first, j-1);
            quickSort(nums, freq, j+1, last);
        }
    }
}
