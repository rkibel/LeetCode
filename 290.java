import java.util.*;
class Problem290 {
    public boolean wordPattern(String pattern, String s) {
        List<String> words = new ArrayList<>();
        while(s.indexOf(' ') != -1){
            words.add(s.substring(0, s.indexOf(' ')));
            s = s.substring(s.indexOf(' ')+1);
        }
        words.add(s);
        if (words.size() != pattern.length()) return false;

        Map<Integer, String> patternToWord = new HashMap<>();
        Map<String, Integer> wordToPattern = new HashMap<>();
        for (int i = 0; i < pattern.length(); i++){
            int val = pattern.charAt(i);
            if ((patternToWord.containsKey(val) && !patternToWord.get(val).equals(words.get(i)))
            || (wordToPattern.containsKey(words.get(i)) && wordToPattern.get(words.get(i)) != val)) return false;
            patternToWord.put(val, words.get(i));
            wordToPattern.put(words.get(i), val);
        }
        return true;
    }
}