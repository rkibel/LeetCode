class Problem3 {
    public int lengthOfLongestSubstring(String s) {
        //O(n^2) runtime solution
        /*int m = 0;    
        for (int i = 0; i < s.length(); i++){
            String currString = Character.toString(s.charAt(i));
            m = Math.max(m, currString.length());
            for (int j = i+1; j < s.length(); j++){
                if (currString.indexOf(s.charAt(j)) == -1){
                    currString += s.charAt(j);
                    m = Math.max(m, currString.length());
                }
                else j = s.length();
            }
            m = Math.max(m, currString.length());
        }
        
        return m;
        */
        //O(n) runtime solution
        int m = 0;
        String curr = "";
        if (s.length() == 0) return m;
        curr += s.charAt(0);
        m = Math.max(m, curr.length());
        for (int i = 1; i < s.length(); i++){
            if (curr.indexOf(s.charAt(i)) != -1)
                curr = curr.substring(curr.indexOf(s.charAt(i)) + 1) + Character.toString(s.charAt(i));
            else
                curr += s.charAt(i);
            m = Math.max(m, curr.length());
        }
        return m;
    }
}