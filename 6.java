class Problem6 {
    public String convert(String s, int numRows) {
        int tot;
        if (numRows <= 2) tot = numRows;
        else tot = numRows + (numRows-2);
        String output = "";
        for (int i = 0; i < numRows; i++){
            for (int j = 0; j < s.length(); j++){
                if (j % tot == i || j % tot == tot-i)
                    output += s.charAt(j);
            }
        }
        return output;
    }
}