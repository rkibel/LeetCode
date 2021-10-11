public class Problem3 {
    public int lengthOfLongestSubstring(String s) {
        String maxString = "";
        String currString = "";
        for (int i = 0; i < s.length(); i++){
            if (currString.indexOf(s.charAt(i)) == -1) 
                currString += Character.toString(s.charAt(i));
            else 
                currString = Character.toString(s.charAt(i));
            if (currString.length() > maxString.length()) 
                maxString = currString;
        }
    return maxString.length();
    }
}
