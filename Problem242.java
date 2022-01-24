class Problem242 {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        int[] letters = new int[255];
        for (int i = 0; i < s.length(); i++){ letters[s.charAt(i)]++; letters[t.charAt(i)]--; }
        for (int let: letters) if (let != 0) return false;
        return true;
    }
}