import java.util.*;
class Problem151 {
    public String reverseWords(String s) {
        String org = s.trim();
        String output = "";
        String word = "";
        List <Integer> spaces = new ArrayList <> ();
        for (int i = 0; i < org.length(); i++){
            if (Character.toString(org.charAt(i)).equals(" "))
                spaces.add(i);
        }
        if (spaces.size() == 0)
            return org;
        for (int i = spaces.size()-1; i >= 0; i--){
            if (i == spaces.size()-1){
                for (int j = spaces.get(i) + 1; j < org.length(); j++){
                    output += org.charAt(j);
                }
                output += " ";
            }
            else{
                for (int j = spaces.get(i) + 1; j < spaces.get(i+1); j++){
                        word += org.charAt(j);
                }
                if (!word.equals(" ")){
                    output += word + " ";
                    word = "";
                }
            }
        }
        for (int i = 0; i < spaces.get(0); i++){
            output += org.charAt(i);
        }
        //ill have to come back to this one
        return output;
    }
}