class Problem168 {
    public String convertToTitle(int num) {
        String res = "";
        while (num != 0){
            res = (char)('A' + (num-1)%26) + res;
            num = (num-1)/26;
        }
        return res;
    }
}