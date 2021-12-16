class Problem20 {
    public boolean isValid(String s) {
        String pre = "";
        for (int p = 0; p < s.length(); p++){
            char i = s.charAt(p);
            if (i == ')' || i == ']' || i == '}'){
                if (pre.length() == 0) return false;
                if (isComplement(i, pre.charAt(pre.length()-1)))
                    pre = pre.substring(0, pre.length()-1);
                else return false;
            }
            else pre += i;
        }
        return pre.length() == 0;
    }
    public boolean isComplement(char back, char front){
        if (back == ')' && front == '(') return true;
        if (back == ']' && front == '[') return true;
        if (back == '}' && front == '{') return true;
        return false;
    }
}