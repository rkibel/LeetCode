
class Problem151 {
    public String reverseWords(String s) {
        int wordLength = s.length() - 1;
        String output = "";
        for (int i = wordLength; i >= -1; i--){
                if (i == -1 || Character.toString(s.charAt(i)).equals(" ")){
                    if (i < wordLength && output.length() > 0)
                        output += " ";
                    for (int j = i+1; j <= wordLength; j++)
                        output += Character.toString(s.charAt(j));
                    wordLength = i-1;
                }
        }




        return output;
    }
}