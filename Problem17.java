import java.util.*;

class Problem17 {
    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) 
            return new ArrayList<String>();
        List<String> first = options(digits.charAt(0));
        if (digits.length() == 1) return first;
        else return multiply(first, letterCombinations(digits.substring(1)));   
    }
    public List<String> options (char dig){
        switch(dig){
            case '2': return new ArrayList<String>(Arrays.asList("a", "b", "c"));
            case '3': return new ArrayList<String>(Arrays.asList("d", "e", "f"));
            case '4': return new ArrayList<String>(Arrays.asList("g", "h", "i"));
            case '5': return new ArrayList<String>(Arrays.asList("j", "k", "l"));
            case '6': return new ArrayList<String>(Arrays.asList("m", "n", "o"));
            case '7': return new ArrayList<String>(Arrays.asList("p", "q", "r", "s"));
            case '8': return new ArrayList<String>(Arrays.asList("t", "u", "v"));
            case '9': return new ArrayList<String>(Arrays.asList("w", "x", "y", "z"));
            default: return new ArrayList<String>();
        }
    }
    public List<String> multiply(List<String> x, List<String> y){
        List<String> output = new ArrayList<>();
        for (String i: x)
            for (String j: y) 
                output.add(i+j);
        return output;
    }
}