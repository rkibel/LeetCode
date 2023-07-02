class Problem387 {
    public int firstUniqChar(String s) {
        int[]ascii = new int[256];
        for (int i = 0; i < s.length(); i++){
            int val = s.charAt(i);
            ascii[val]++;
        }
        for (int i = 0; i < s.length(); i++){
            int val = s.charAt(i);
            if (ascii[val] == 1)
                return i;
        }
        return -1;
    }
}