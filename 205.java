class Problem205 {
    public boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length()) return false;
        int[] ascii1 = new int[255], ascii2 = new int[255];
        for (int i = 0; i < s.length(); i++){
            int a = s.charAt(i), b = t.charAt(i);
            if ((ascii1[a] != 0 || ascii2[b] != 0) && ascii1[a] != ascii2[b]) return false;
            ascii1[a] = i+1;
            ascii2[b] = i+1;
        }
        return true;
    }
}