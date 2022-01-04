class Problem171 {
    public int titleToNumber(String tit) {
        int num = 0;
        for (int i = tit.length()-1; i >= 0; i--)
            num += (tit.charAt(i) - 'A' + 1)*Math.pow(26, tit.length()-1-i);
        return num;
    }
}