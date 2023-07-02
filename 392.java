class Problem392 {
    public boolean isSubsequence(String s, String t) {
        for (int i = 0; i < t.length(); i++){
            if (s.length() == 0) return true;
            if (s.charAt(0) == t.charAt(i)) s = s.substring(1);
        }
        return s.length() == 0;
    }
}