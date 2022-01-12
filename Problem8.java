class Problem8 {
    public int myAtoi(String s) {
        String trimmed = s.trim();
        System.out.println(trimmed);
        String builder = "";
        boolean hasSign = false;
        boolean neg = false;
        for (int i = 0; i < trimmed.length(); i++){
            System.out.println(builder + "|");
            if (hasSign == false){
                if ((int)trimmed.charAt(i) == 43){
                    System.out.println("positive");
                    hasSign = true;
                    continue;
                }
                else if ((int)(trimmed.charAt(i)) == 45){
                    System.out.println("negative");
                    hasSign = true;
                    neg = true;
                    continue;
                }
            }
            if (Character.isDigit(trimmed.charAt(i))){
                System.out.println("digit");
                builder += trimmed.charAt(i);
                hasSign = true;
            }
            else break;
        }
        int res = 0;
        if (builder.length() > 0){
            try{
                res = Integer.parseInt(builder);    
            }
            catch (java.lang.NumberFormatException e){
                if (neg) return Integer.MIN_VALUE;
                return Integer.MAX_VALUE;
            }
        }
        if (neg) res *= -1;
        return res;
    }
}