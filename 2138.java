class Problem2138 {
    public String[] divideString(String s, int k, char fill) {
        String curr = "";
        String[] res = new String[(s.length()+k-1)/k];
        for (int i = 0; i < s.length(); i++){
            if (curr.length() == k){
                res[i/k-1] = curr;
                curr = "";
            }
            curr += s.charAt(i);
        }
        int diff = k-curr.length();
        for (int i = 0; i < diff; i++) curr += fill;
        res[res.length-1] = curr;
        return res;
    }
}